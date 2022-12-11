#include <cstdio>
static const int MAXN = 1e5 + 2;

int n;

bool query(int x, int y)
{
    if (x == y) return true;
    printf("1 %d %d\n", x, y); fflush(stdout);
    static char resp[24];
    scanf("%s", resp);
    return (resp[0] == 'T');
}

inline int search(int l, int r)
{
    int mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (query(mid, mid + 1)) r = mid; else l = mid + 1;
    }
    return l;
}

int main()
{
    scanf("%d%*d", &n);

    int p = search(1, n), q = -1;
    if (p != 1) q = search(1, p - 1);
    if (q == -1 || !query(q, p)) q = search(p + 1, n);
    printf("2 %d %d\n", p, q);

    return 0;
}