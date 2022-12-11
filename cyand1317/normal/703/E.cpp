#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
typedef long long int64;
static const int INF32 = 0x3fffffff;
static const int MAXN = 1005;
static const int MAXDIV = 8192;
template <typename T> inline T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

int n;
int64 k;
int64 a[MAXN], gcdka[MAXN];
int divct = 0;
int64 divsr[MAXDIV];
std::map<int64, int> dividx;

std::pair<int, int64> f[MAXN][MAXDIV];

int main()
{
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        gcdka[i] = gcd(a[i], k);
    }

    for (int64 i = 1; i * i <= k; ++i) if (k % i == 0) {
        divsr[divct++] = i;
        if (i * i != k) divsr[divct++] = k / i;
    }
    std::sort(divsr, divsr + divct);
    for (int i = 0; i < divct; ++i) dividx[divsr[i]] = i;


    f[0][0] = std::make_pair(0, 0);
    for (int i = 1; i < divct; ++i)
        if (a[0] % divsr[i] == 0) f[0][i] = std::make_pair(1, a[0]);
        else f[0][i] = std::make_pair(INF32, 0);
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < divct; ++j) {
            int c = dividx[divsr[j] / gcd(divsr[j], gcdka[i])];
            f[i][j] = std::min(
                f[i - 1][j],
                std::make_pair(f[i - 1][c].first + 1, f[i - 1][c].second + a[i])
            );
            //printf("%d %I64d | %d %I64d\n", i, divsr[j], f[i][j].first, f[i][j].second);
        }

    if (f[n - 1][divct - 1].first == INF32) {
        puts("-1");
    } else if (k == 1) {
        printf("1\n%d", std::min_element(a, a + n) - a + 1);
    } else {
        printf("%d\n", f[n - 1][divct - 1].first);
        for (int i = n - 1, j = divct - 1; i >= 0; --i)
            if ((i == 0 && f[i][j].first == 1) || (i != 0 && f[i][j] != f[i - 1][j])) {
                printf("%d ", i + 1);
                j = dividx[divsr[j] / gcd(divsr[j], gcdka[i])];
            }
        putchar('\n');
    }

    return 0;
}