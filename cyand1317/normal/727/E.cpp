#include <cstdio>
#include <map>
#include <tuple>
#include <vector>
static const int MAXN = 1e5 + 4;
static const int MAXK = 1e5 + 4;
static const int MAXL = 2e6 + 5 + MAXK;
static const int HBASE1 = 1000007;
static const int HMOD1 = 998244353;
static const int HBASE2 = 415411;
static const int HMOD2 = 1000000007;
static const int HBASE3 = 2333341;
static const int HBASE4 = 29;
typedef long long int64;
typedef unsigned long long uint64;
typedef std::tuple<int64, int64, uint64, uint64> hash_t;
int64 hpow1[MAXK], hpow2[MAXK], hpow3[MAXK], hpow4[MAXK];
template <typename T> inline bool relax(T &var, const T val) { if (var < val) return (var = val, true); else return false; }

int n, g, k;
char s[MAXL], t[MAXL];
hash_t hs[MAXL], ht[MAXN];
std::map<std::pair<hash_t, int>, int> occ;

bool valid_remainder[MAXK];
int _f[MAXL] = { false };
inline int& f(int row, int col) { return _f[row * k + col]; }
// f(first i games, remainder is j) = maximum number of games possible at positions (j + Int*k)
int ans[MAXN];

int main()
{
    scanf("%d%d", &n, &k); getchar();
    gets(s); for (int i = 0; i < k; ++i) s[i + n * k] = s[i];
    scanf("%d", &g); getchar();
    for (int i = 0; i < g; ++i) gets(t + (i * k));

    hpow1[0] = 1; for (int i = 1; i < k; ++i) hpow1[i] = hpow1[i - 1] * HBASE1 % HMOD1;
    hpow2[0] = 1; for (int i = 1; i < k; ++i) hpow2[i] = hpow2[i - 1] * HBASE2 % HMOD2;
    hpow3[0] = 1; for (int i = 1; i < k; ++i) hpow3[i] = hpow3[i - 1] * HBASE3;
    hpow4[0] = 1; for (int i = 1; i < k; ++i) hpow4[i] = hpow4[i - 1] * HBASE4;
    int64 hash1 = 0, hash2 = 0, hash3 = 0, hash4 = 0;
    for (int i = 0; i < k; ++i) {
        (hash1 += hpow1[k - i - 1] * (s[i] - 'a')) %= HMOD1;
        (hash2 += hpow2[k - i - 1] * (s[i] - 'a')) %= HMOD2;
        (hash3 += hpow3[k - i - 1] * (s[i] - 'a'));
        (hash4 += hpow4[k - i - 1] * (s[i] - 'a'));
    }
    for (int i = 0; i < k; ++i) valid_remainder[i] = true;
    for (int i = 0; i < n * k; ++i) {
        hs[i] = hash_t(hash1, hash2, hash3, hash4);
        hash1 -= hpow1[k - 1] * (s[i] - 'a');
        hash1 = (hash1 % HMOD1 + HMOD1);
        ((hash1 *= HBASE1) += (s[i + k] - 'a')) %= HMOD1;
        hash2 -= hpow2[k - 1] * (s[i] - 'a');
        hash2 = (hash2 % HMOD2 + HMOD2);
        ((hash2 *= HBASE2) += (s[i + k] - 'a')) %= HMOD2;
        hash3 -= hpow3[k - 1] * (s[i] - 'a');
        (hash3 *= HBASE3) += (s[i + k] - 'a');
        hash4 -= hpow4[k - 1] * (s[i] - 'a');
        (hash4 *= HBASE4) += (s[i + k] - 'a');
        //if (occ[std::make_pair(hs[i], i % k)]) valid_remainder[i % k] = false;
        occ[std::make_pair(hs[i], i % k)] = 1 + i;
    }
    for (int i = 0; i < g; ++i) {
        hash1 = hash2 = hash3 = hash4 = 0;
        for (int j = 0; j < k; ++j) {
            (hash1 += hpow1[k - j - 1] * (t[j + i * k] - 'a')) %= HMOD1;
            (hash2 += hpow2[k - j - 1] * (t[j + i * k] - 'a')) %= HMOD2;
            (hash3 += hpow3[k - j - 1] * (t[j + i * k] - 'a'));
            (hash4 += hpow4[k - j - 1] * (t[j + i * k] - 'a'));
        }
        ht[i] = hash_t(hash1, hash2, hash3, hash4);
    }

    for (int i = 1; i <= g; ++i) {
        for (int j = 0; j < k; ++j) if (valid_remainder[j]) {
            f(i, j) = f(i - 1, j);
            if (occ[std::make_pair(ht[i - 1], j)]) relax(f(i, j), f(i - 1, j) + 1);
        }
    }

    int max = 0;
    for (int i = 0; i < k; ++i) if (valid_remainder[i] && f(g, i) >= n) {
        puts("YES");
        for (int j = 0; j < g; ++j) if (f(j + 1, i) > f(j, i)) {
            // Where is ht[j]?
            ans[(occ[std::make_pair(ht[j], i)] - 1) / k] = j + 1;
        }
        for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
        return 0;
    } else relax(max, f(g, i));

    if (false) printf("NO %d/%d\n", max, g); else puts("NO");
    return 0;
}