#include <cstdio>
typedef long long int64;
static const int64 INF64 = 1LL << 59;
static const int MAXN = 204;
static const int MAXLEN = 204;
static const int MAXLENSUM = 208;
static const int ALPHABET = 26;
template <typename T, typename K> inline T max(const T a, const K b) { return a > b ? a : b; }
template <typename T, typename K> inline void upd_max(T &var, const K val) { if (var < val) var = val; }

int n; int64 l;
int a[MAXN];
char s[MAXN][MAXLEN]; int len[MAXN] = { 0 };
int suf_val[MAXN] = { 0 };
bool g[MAXLENSUM][MAXLENSUM] = {{ false }};

struct mat {
    int64 a[MAXLENSUM][MAXLENSUM];
    int sz;

    mat() : sz(0) { }
    mat(int sz) : sz(sz) { }

    inline void operator *= (const mat &rhs) {
        static int64 c[MAXLENSUM][MAXLENSUM];
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j < sz; ++j) {
                c[i][j] = -INF64;
                for (int k = 0; k < sz; ++k) upd_max(c[i][j], this->a[i][k] + rhs.a[k][j]);
            }
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j < sz; ++j) this->a[i][j] = c[i][j];
    }

    inline void operator ^= (int64 exp) {
        static mat ans;
        ans.sz = this->sz;
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j < sz; ++j) ans.a[i][j] = (i == j ? 0 : -INF64);
        for (; exp; exp >>= 1) {
            if (exp & 1) ans *= *this;
            *this *= *this;
        }
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j < sz; ++j) this->a[i][j] = ans.a[i][j];
    }
} m, vec;

namespace ac_automata {

struct node {
    int val, child[ALPHABET], fail;
} t[MAXLENSUM] = {{ 0 }};
int sz = 1;
static const int ROOT = 0;
inline void init() {
    for (int i = 0; i < MAXLENSUM; ++i)
        for (int j = 0; j < ALPHABET; ++j) t[i].child[j] = -1;
}

inline void insert(int n, char *s, int v)
{
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int &nxt = t[cur].child[s[i]];
        if (nxt == -1) nxt = sz++;
        cur = nxt;
    }
    t[cur].val += v;
}

inline void build_failtree()
{
    static int q[MAXLENSUM], qhead, qtail;
    qhead = qtail = 0;
    t[ROOT].fail = -1;
    for (int i = 0; i < ALPHABET; ++i) if (t[ROOT].child[i] != -1) {
        t[t[ROOT].child[i]].fail = ROOT;
        q[qhead++] = t[ROOT].child[i];
    }
    while (qhead > qtail) {
        int u = q[qtail++], v;
        for (int i = 0; i < ALPHABET; ++i) if (t[u].child[i] != -1) {
            for (v = t[u].fail; v != -1; v = t[v].fail) if (t[v].child[i] != -1) {
                t[t[u].child[i]].fail = t[v].child[i]; break;
            }
            if (v == -1) t[t[u].child[i]].fail = ROOT;
            q[qhead++] = t[u].child[i];
        }
    }
}

/*inline void dbgprn()
{
    for (int i = 0; i < sz; ++i) {
        printf("%2d val=%d | fail=%2d |", i, t[i].val, t[i].fail);
        for (int j = 0; j < ALPHABET; ++j)
            if (t[i].child[j] != -1) printf(" %c=%d", j + 'a', t[i].child[j]);
        putchar('\n');
    }
}*/

inline void build_graph(bool g[MAXLENSUM][MAXLENSUM])
{
    for (int i = 0; i < sz; ++i) {
        for (int u = i; u != -1; u = t[u].fail) {
            for (int e = 0; e < ALPHABET; ++e)
                if (t[u].child[e] != -1) g[i][t[u].child[e]] = true;
        }
    }
}

}

int main()
{
    scanf("%d%I64d", &n, &l);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    getchar();
    ac_automata::init();
    for (int i = 0; i < n; ++i) {
        while ((s[i][len[i]] = getchar() - 'a') != '\n' - 'a') ++len[i];
        ac_automata::insert(len[i], s[i], a[i]);
    }

    ac_automata::build_failtree();
    ac_automata::build_graph(g);

    for (int i = 0; i < ac_automata::sz; ++i) {
        for (int v = i; v != ac_automata::ROOT; v = ac_automata::t[v].fail)
            suf_val[i] += ac_automata::t[v].val;
    }

    m.sz = vec.sz = ac_automata::sz;
    for (int i = 0; i < ac_automata::sz; ++i)
        for (int j = 0; j < ac_automata::sz; ++j) m.a[i][j] = vec.a[i][j] = -INF64;
    vec.a[0][0] = 0;
    for (int i = 0; i < ac_automata::sz; ++i)
        for (int j = 0; j < ac_automata::sz; ++j) if (g[i][j]) {
            upd_max(m.a[i][j], suf_val[j]);
        }

    m ^= l;
    vec *= m;

    int64 ans = 0;
    for (int i = 0; i < ac_automata::sz; ++i) ans = max(ans, vec.a[0][i]);
    printf("%I64d\n", ans);
    return 0;
}