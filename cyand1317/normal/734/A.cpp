#include <cstdio>

int n, act = 0, dct = 0;

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i)
        if (getchar() == 'A') ++act; else ++dct;
    if (act == dct) puts("Friendship"); else puts(act > dct ? "Anton" : "Danik");
    return 0;
}