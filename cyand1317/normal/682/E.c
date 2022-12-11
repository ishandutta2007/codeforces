// Long time no C!
#include <stdio.h>
#define MAXN 5005
typedef long long int64;
int64 abs(int64 x) { return x > 0 ? x : -x; }

int n;
int x[MAXN], y[MAXN];
//int64 s;

int64 area(int i, int j, int k)
{
    return abs(
        (int64)(x[j] - x[i]) * (y[k] - y[i]) -
        (int64)(y[j] - y[i]) * (x[k] - x[i]));
}

int main()
{
    int i, a, b, c;
    scanf("%d%*I64d", &n);
    for (i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);

    a = 0, b = 1, c = 2;
    unsigned char updated = 1;
    while (updated) {
        updated = 0;
        for (i = 0; i < n; ++i) {
            if (area(a, b, i) > area(a, b, c)) { c = i; updated = 1; }
            if (area(a, i, c) > area(a, b, c)) { b = i; updated = 1; }
            if (area(i, b, c) > area(a, b, c)) { a = i; updated = 1; }
        }
    }

    printf("%d %d\n%d %d\n%d %d\n",
        -x[a] + x[b] + x[c], -y[a] + y[b] + y[c],
        x[a] - x[b] + x[c], y[a] - y[b] + y[c],
        x[a] + x[b] - x[c], y[a] + y[b] - y[c]);

    return 0;
}