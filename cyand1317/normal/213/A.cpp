#include <cstdio>
#include <cstring>
static const int MAXN = 204;

int n;
int c[MAXN], k[MAXN], kk[MAXN];
bool g[MAXN][MAXN] = {{ false }};

int check(int pos)
{
    int ans = n, remain_ct = n;
    memcpy(k, kk, sizeof k);
    while (remain_ct > 0) {
        for (int rep = 0; rep < n; ++rep)
            for (int i = 0; i < n; ++i) if (k[i] == 0 && c[i] == pos) {
                for (int j = 0; j < n; ++j) if (g[i][j]) --k[j];
                k[i] = -1; --remain_ct;
            }
        if (remain_ct == 0) break;
        pos = (pos + 1) % 3; ++ans;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]); --c[i];
    }
    int aij;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &kk[i]);
        for (int j = 0; j < kk[i]; ++j) {
            scanf("%d", &aij); --aij;
            g[aij][i] = true;
        }
    }

    int ans = 0x7fffffff, cur;
    if ((cur = check(0)) < ans) ans = cur;
    if ((cur = check(1)) < ans) ans = cur;
    if ((cur = check(2)) < ans) ans = cur;
    printf("%d\n", ans);

    return 0;
}