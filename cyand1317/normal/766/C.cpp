#include <cstdio>
static const int MAXN = 1e3 + 2;
static const int ALPHABET = 26;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
#define __ %= MODULUS

int n;
char s[MAXN];
int lim[ALPHABET];

bool occs[MAXN][MAXN][ALPHABET] = {{{ 0 }}};
bool valid[MAXN][MAXN] = {{ false }};
int f[MAXN] = { 0 };

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar() - 'a';
    for (int i = 0; i < ALPHABET; ++i) scanf("%d", &lim[i]);

    for (int i = 0; i < n; ++i) {
        occs[i][i][s[i]] = true; valid[i][i] = true;
        for (int j = i + 1; j < n; ++j) {
            valid[i][j] = true;
            for (int k = 0; k < ALPHABET; ++k) occs[i][j][k] = occs[i][j - 1][k];
            occs[i][j][s[j]] = true;
            for (int k = 0; k < ALPHABET; ++k)
                if (occs[i][j][k] && (j - i + 1) > lim[k]) { valid[i][j] = false; break; }
        }
    }

    // Subproblem 1
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) if (valid[j][i - 1]) (f[i] += f[j])__;
    }
    printf("%d\n", f[n]);

    // Subproblem 2
    int longest = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) if (valid[i][j] && longest < j - i + 1) longest = j - i + 1;
    printf("%d\n", longest);

    // Subproblem 3
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = MAXN;
        for (int j = 0; j < i; ++j) if (valid[j][i - 1] && f[i] > f[j] + 1) f[i] = f[j] + 1;
    }
    printf("%d\n", f[n]);

    return 0;
}