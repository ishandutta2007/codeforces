#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n;
ve<long> a, b;
vi dad;
ve<vi> gr;
void read() {
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
    dad.resize(n);
    b.resize(n);
    gr.resize(n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%I64d", &dad[i], &b[i]);
        gr[--dad[i]].push_back(i);
    }
}

struct BIT {
    ve<long> dd;
    void resize(int n) { dd.assign(n + 1, 0); }
    void operator()(int i, long v) { for (++i; i < sz(dd); i += i & -i) dd[i] += v; }
    long operator[](int i) { long ans = 0; for (++i; i > 0; i -= i & -i) ans += dd[i]; return ans;}
} bit;

ve<long> dst;
vi tp;
void dfs(int u) {
    static long curdst = 0;
    dst[u] = curdst;
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        curdst += b[v];
        dfs(v);
        curdst -= b[v];
    }
    tp.push_back(u);
}

ve<vi> spt;

int findlowestmanager(int u) {
    int v = u;
    for (int i = sz(spt) - 1; i >= 0; --i) {
        if (dst[u] - dst[spt[i][v]] <= a[u]) v = spt[i][v];
    }
    return v;
}

vi m, ans;

void process() {
    dst.resize(n);
    dfs(0);
    spt.resize(log(n) / log(2) + 1, vi(n));
    copy(dad.bb, dad.ee, spt[0].bb);
    for (int i = 1; i < sz(spt); ++i) {
        for (int f = 0; f < n; ++f)
            spt[i][f] = spt[i - 1][spt[i - 1][f]];
    }

    m.resize(n); ans = m;
    for (int i = 0; i < n; ++i) {
        int u = findlowestmanager(i);
        if (u == i) continue;
        m[dad[i]] ++;
        if (u != 0) m[dad[u]] --;
    }

    for (int i = 0; i < n; ++i) {
        int u = tp[i], v = dad[u];
        ans[u] = m[u];
        m[v] += m[u];
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    process();
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);


    return 0;
}