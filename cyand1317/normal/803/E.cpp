#include <cstdio>
#include <utility>
static const int MAXN = 1005;

int n, k;
char s[MAXN];
// f[sequence position][win/lose + MAXN] = whether possible, and a transition
std::pair<bool, char> f[MAXN][MAXN * 2];
char ans[MAXN] = { 0 };

int main()
{
    scanf("%d%d", &n, &k); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar();

    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN * 2; ++j) f[i][j] = std::make_pair(false, -1);

    f[0][MAXN] = std::make_pair(true, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAXN * 2; ++j) if (f[i][j].first) {
            if ((s[i] == 'W' || s[i] == '?') && j + 1 < MAXN + k + (i == n - 1))
                f[i + 1][j + 1] = std::make_pair(true, 'W');
            if ((s[i] == 'L' || s[i] == '?') && j - 1 > MAXN - k - (i == n - 1))
                f[i + 1][j - 1] = std::make_pair(true, 'L');
            if (s[i] == 'D' || s[i] == '?')
                f[i + 1][j] = std::make_pair(true, 'D');
        }
    }

    int start = -1;
    if (f[n][MAXN + k].first) start = MAXN + k;
    else if (f[n][MAXN - k].first) start = MAXN - k;
    else { puts("NO"); return 0; }

    for (int i = n; i > 0; --i) {
        ans[i - 1] = f[i][start].second;
        switch (f[i][start].second) {
            case 'W': --start; break;
            case 'L': ++start; break;
            case 'D': default: break;
        }
    }
    puts(ans);

    return 0;
}