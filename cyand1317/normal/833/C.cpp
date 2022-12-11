#include <cstdio>
typedef long long int64;
static const int MAXN = 19;
static const int MAXS = 7e6;

int64 l, r;
char ld[MAXN], rd[MAXN];

int sct = 0;
int rou[MAXN];
char s[MAXS][MAXN] = {{ 0 }};

void dfs(int u, int d)
{
    if (u == MAXN) {
        for (int i = 0; i < MAXN; ++i) ++s[sct][rou[i]];
        ++sct;
        return;
    }
    for (rou[u] = d; rou[u] <= 9; ++rou[u])
        dfs(u + 1, rou[u]);
}

bool check(char *s)
{
    int u = MAXN - 1;
    while (ld[u] == rd[u]) { if ((--s[ld[u]]) < 0) return false; --u; }

    static int t[MAXN];
    for (int i = 0; i < MAXN; ++i) t[i] = s[i];

    for (int i = u; i >= 0; --i) {
        for (int j = rd[i] - 1; j >= (i == u ? ld[i] + 1 : 0); --j)
            if (s[j] > 0) return true;
        if ((--s[rd[i]]) < 0) break;
    }

    for (int i = 0; i < MAXN; ++i) s[i] = t[i];
    for (int i = u; i >= 0; --i) {
        for (int j = ld[i] + 1; j <= (i == u ? rd[i] - 1 : 9); ++j)
            if (s[j] > 0) return true;
        if ((--s[ld[i]]) < 0) break;
    }

    return false;
}

int main()
{
    scanf("%I64d%I64d", &l, &r); --l, ++r;
    int64 _l = l, _r = r;
    for (int i = 0; i < MAXN; ++i, _l /= 10) ld[i] = _l % 10;
    for (int i = 0; i < MAXN; ++i, _r /= 10) rd[i] = _r % 10;

    dfs(0, 0);

    int ans = 0;
    for (int i = 0; i < sct; ++i) if (check(s[i])) ++ans;
    printf("%d\n", ans);

    return 0;
}