#include <stdio.h>

int nhan_truong(int a, int b, int n, int p)
{
    int kq = 0;
    int bit_cao = 1 << n;
    int mask = bit_cao - 1;

    while (b > 0)
    {
        if (b & 1)
            kq = kq ^ a;

        b = b >> 1;
        a = a << 1;

        if (a & bit_cao)
            a = a ^ p;

        a = a & mask;
    }

    return kq;
}

void chay_GF4()
{
    int a, b;

    printf("\\n--- Phep nhan trong GF(2^4) ---\\n");
    printf("Da thuc toi gian: x^4 + x + 1\\n");

    printf("Nhap a (0 - 15): ");
    if (scanf("%d", &a) != 1)
        return;

    printf("Nhap b (0 - 15): ");
    if (scanf("%d", &b) != 1)
        return;

    if (a < 0 || a > 15 || b < 0 || b > 15)
    {
        printf("Gia tri khong hop le!\\n");
        return;
    }

    int kq = nhan_truong(a, b, 4, 0x13);

    printf("Ket qua: %X\\n", kq);
    printf("Dang nhi phan: ");
    for (int i = 3; i >= 0; i--)
        printf("%d", (kq >> i) & 1);

    printf("\\n");
}

void chay_GF8()
{
    int a, b;

    printf("\\n--- Phep nhan trong GF(2^8) ---\\n");
    printf("Da thuc toi gian: x^8 + x^4 + x^3 + x + 1\\n");

    printf("Nhap a (0 - 255): ");
    if (scanf("%d", &a) != 1)
        return;

    printf("Nhap b (0 - 255): ");
    if (scanf("%d", &b) != 1)
        return;

    if (a < 0 || a > 255 || b < 0 || b > 255)
    {
        printf("Gia tri khong hop le!\\n");
        return;
    }

    int kq = nhan_truong(a, b, 8, 0x11B);

    printf("Ket qua: %02X\\n", kq);
    printf("Dang nhi phan: ");
    for (int i = 7; i >= 0; i--)
        printf("%d", (kq >> i) & 1);

    printf("\\n");
}

int main(void)
{
    int chon;

    do
    {
        printf("\\n===== NHAN DA THUC TRONG TRUONG HUU HAN =====\\n");
        printf("1. GF(2^4)\\n");
        printf("2. GF(2^8)\\n");
        printf("0. Thoat\\n");
        printf("Lua chon: ");

        if (scanf("%d", &chon) != 1)
        {
            printf("Du lieu khong hop le.\\n");
            return 1;
        }

        switch (chon)
        {
            case 1:
                chay_GF4();
                break;

            case 2:
                chay_GF8();
                break;

            case 0:
                printf("Ket thuc chuong trinh.\\n");
                break;

            default:
                printf("Lua chon khong hop le!\\n");
        }

    } while (chon != 0);

    return 0;
}
