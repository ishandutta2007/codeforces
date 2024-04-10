#include <cstdio>
static const int MAXN = 54;
static const int MAXL = 103;

int n, l, a[MAXN], b[MAXN];

int main()
{
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < n; ++j) {
            bool valid = true;
            for (int k = 0; k < n; ++k)
                if ((a[k] + i) % l != b[(k + j) % n]) { valid = false; break; }
            if (valid) { puts("YES"); return 0; }
        }
    }

    puts("NO"); return 0;
}