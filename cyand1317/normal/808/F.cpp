#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using std::min;
typedef long long int64;
static const int INF = 0x3fffffff;
static const int MAXN = 103;
static const int MAXC = 200004;

namespace nwf {

static const int MAXN = 206;
static const int MAXM = 25005;

int n, m, source, sink;
int head[MAXN], dest[MAXM], cap[MAXM], next[MAXM];

inline void init(int _n) { n = _n, m = 0; for (int i = 0; i < n; ++i) head[i] = -1; }
inline void add_edge(int u, int v, int c) {
    dest[m] = v; cap[m] = c; next[m] = head[u]; head[u] = m++;
    dest[m] = u; cap[m] = 0; next[m] = head[v]; head[v] = m++;
}

int d[MAXN], cur[MAXN];
inline bool level_graph()
{
    static int q[MAXN], qhead, qtail;
    memset(d, -1, sizeof d);
    d[source] = 0, q[0] = source; qhead = 0, qtail = 1;
    while (qhead < qtail) {
        int u = q[qhead++];
        for (int w = head[u]; w != -1; w = next[w])
            if (cap[w] > 0 && d[dest[w]] == -1) {
                d[dest[w]] = d[u] + 1;
                q[qtail++] = dest[w];
            }
    }
    return (d[sink] > 0);
}

int augment(int u, int cur_cap = INF)
{
    if (u == sink) return cur_cap;
    int new_cap;
    for (int &w = cur[u]; w != -1; w = next[w])
        if (cap[w] > 0 && d[dest[w]] == d[u] + 1 && (new_cap = augment(dest[w], min(cur_cap, cap[w]))) > 0) {
            cap[w] -= new_cap;
            cap[w ^ 1] += new_cap;
            return new_cap;
        }
    return 0;
}

inline int plunge()
{
    int ans = 0, aug;
    while (level_graph()) {
        for (int i = 0; i < n; ++i) cur[i] = head[i];
        while ((aug = augment(source)) > 0) ans += aug;
    }
    return ans;
}

}

bool not_prime[MAXC] = { false };
int primes[MAXC / 10], prime_ct = 0;

inline void sieve()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXC; ++i) {
        if (!not_prime[i]) primes[prime_ct++] = i;
        for (int j = 0; j < prime_ct && (int64)i * primes[j] < MAXC; ++j) {
            not_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int n, k;
int p[MAXN], c[MAXN], l[MAXN];

inline bool check(int level_upperbound)
{
    nwf::init(n + 2);
    nwf::source = n, nwf::sink = n + 1;

    std::pair<int, int> largest_1 = std::make_pair(-1, -1);
    for (int i = 0; i < n; ++i) if (l[i] <= level_upperbound) {
        if (c[i] == 1) {
            largest_1 = std::max(largest_1, std::make_pair(p[i], i));
        } else if (c[i] % 2 == 0) {
            nwf::add_edge(nwf::source, i, p[i]);
        } else {
            nwf::add_edge(i, nwf::sink, p[i]);
        }
    }

    static bool valid[MAXN];
    for (int i = 0; i < n; ++i) valid[i] = (l[i] <= level_upperbound);
    if (largest_1.first != -1) {
        nwf::add_edge(largest_1.second, nwf::sink, largest_1.first);
        for (int i = 0; i < n; ++i)
            if (c[i] == 1 && i != largest_1.second) valid[i] = false;
    }

    for (int i = 0; i < n; ++i) if (valid[i]) {
        for (int j = 0; j < n; ++j) if (i != j && valid[j] && !not_prime[c[i] + c[j]]) {
            if (c[i] % 2 == 0) nwf::add_edge(i, j, INF);
            else nwf::add_edge(j, i, INF);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) if (valid[i]) ans += p[i];
    ans -= nwf::plunge();
    return (ans >= k);
}

int main()
{
    sieve();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &p[i], &c[i], &l[i]);

    int lo = 0, hi = n + 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid; else lo = mid;
    }
    printf("%d\n", hi == n + 1 ? -1 : hi);

    return 0;
}