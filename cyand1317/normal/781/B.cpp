#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
static const int INF = 0x3fffffff;
static const int MAXN = 1004;
static const int ALPHABET = 26;
static const int SN_COUNT = ALPHABET * ALPHABET * ALPHABET;

namespace nwf {

static const int MAXN = ::SN_COUNT + ::MAXN + 2;
static const int MAXM = ::MAXN * 6 + ::SN_COUNT * 2;

int n, m, source, sink;
int head[MAXN], dest[MAXM], cap[MAXM], next[MAXM];

inline void init(int _n) { n = _n, m = 0; for (int i = 0; i < n; ++i) head[i] = -1; }
inline int add_edge(int u, int v, int c) {
    dest[m] = v; cap[m] = c; next[m] = head[u]; head[u] = m++;
    dest[m] = u; cap[m] = 0; next[m] = head[v]; head[v] = m++;
    return m - 1;
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

int n, val[MAXN][2];
bool taken[SN_COUNT] = { false };
int assigned[MAXN], e_id[MAXN][2];

int main()
{
    scanf("%d", &n);
    char s[2][25];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s", s[0], s[1]);
        val[i][0] = (s[0][0] - 'A') * 676 + (s[0][1] - 'A') * 26 + (s[0][2] - 'A');
        val[i][1] = (s[0][0] - 'A') * 676 + (s[0][1] - 'A') * 26 + (s[1][0] - 'A');
    }
    for (int i = 0; i < n; ++i) assigned[i] = -1;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) if (val[i][0] == val[j][0]) {
            if (assigned[i] == -1 && taken[val[i][1]]) { puts("NO"); return 0; }
            taken[val[i][1]] = true; assigned[i] = val[i][1];
            if (assigned[j] == -1 && taken[val[j][1]]) { puts("NO"); return 0; }
            taken[val[j][1]] = true; assigned[j] = val[j][1];
        }

    nwf::init(2 + n + SN_COUNT);
    nwf::source = n + SN_COUNT;
    nwf::sink = n + SN_COUNT + 1;
    int full_flow = 0;
    for (int i = 0; i < n; ++i)
        if (assigned[i] == -1) {
            full_flow++, nwf::add_edge(nwf::source, i, 1);
            e_id[i][0] = nwf::add_edge(i, n + val[i][0], 1);
            e_id[i][1] = nwf::add_edge(i, n + val[i][1], 1);
        }
    for (int i = 0; i < SN_COUNT; ++i)
        if (!taken[i]) nwf::add_edge(n + i, nwf::sink, 1);

    int actual_flow = nwf::plunge();
    if (actual_flow < full_flow) { puts("NO"); return 0; }

    for (int i = 0; i < n; ++i)
        if (assigned[i] == -1) {
            if (nwf::cap[e_id[i][0]]) assigned[i] = val[i][0];
            else if (nwf::cap[e_id[i][1]]) assigned[i] = val[i][1];
            else puts("> <");
        }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        putchar(assigned[i] / 676 + 'A');
        putchar(assigned[i] / 26 % 26 + 'A');
        putchar(assigned[i] % 26 + 'A');
        putchar('\n');
    }

    return 0;
}