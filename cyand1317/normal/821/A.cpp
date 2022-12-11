#include <cstdio>
static const int MAXN = 52;

int n;
int a[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (a[i][j] != 1) {
            bool valid = false;
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l)
                    if (a[i][k] + a[l][j] == a[i][j]) {
                        valid = true; break;
                    }
                if (valid) break;
            }
            if (!valid) { puts("No"); return 0; }
        }

    puts("Yes"); return 0;
}