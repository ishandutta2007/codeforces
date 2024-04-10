#include <cstdio>

int a[2];

int main()
{
    scanf("%d%d", &a[1], &a[0]);
    for (int i = 1; ; ++i) {
        if ((a[i & 1] -= i) < 0) { puts((i & 1) ? "Vladik" : "Valera"); break; }
    }
    return 0;
}