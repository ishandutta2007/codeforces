#include <cstdio>
#include <algorithm>
static const int MAXN = 24;

int n, m;
int a[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);

    bool valid;
    for (int c1 = 0; c1 < m; ++c1) {
        for (int c2 = c1; c2 < m; ++c2) {
            for (int i = 0; i < n; ++i) std::swap(a[i][c1], a[i][c2]);
            valid = true;
            for (int i = 0; i < n; ++i) {
                int ct = 0;
                for (int j = 0; j < m; ++j) if (j + 1 != a[i][j]) ++ct;
                if (ct > 2) { valid = false; break; }
            }
            // Recover
            for (int i = 0; i < n; ++i) std::swap(a[i][c1], a[i][c2]);
            if (valid) break;
        }
        if (valid) break;
    }

    puts(valid ? "YES" : "NO");
    return 0;
}