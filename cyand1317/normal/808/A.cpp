#include <cstdio>

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; ; i *= 10) {
        for (int j = 1; j <= 9; ++j)
            if (j * i > n) { printf("%d\n", j * i - n); return 0; }
    }
    return 0;
}