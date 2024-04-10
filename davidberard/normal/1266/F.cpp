#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 500500;
vector<int> f[N];
int tmp[N];
int g[N];
int h[N]; // largest length which is greater than j
int ans[N];
int hh[N]; // height of subtree
int lon[N]; // longest path through parent
vector<int> adj[N];
int zero = 0;
int b2 = 0;
int n;

inline int& dp(const int& i, const int& j) {
    zero = 0;
    if (j>g[i]) return zero;
    return f[i][g[i]-j];
}

struct max2 {
    int first, second;
    max2() : first(-1), second(-1) {}
    void insert(int x) {
        if (x > first) {
            swap(first, second); first = x;
        } else if (x > second) {
            second = x;
        }
    }
    int other(int x) {
        return (x == first ? second : first);
    }
};

void prep(int u, int p, int hei) {
    hh[u] = hei;
    max2 m2;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        prep(v, u, hei+1);
        m2.insert(hh[v]);
        hh[u] = max(hh[u], hh[v]);
    }
    for (auto& v : adj[u]) {
        if (v == p) continue;
        lon[v] = max(hei-1, m2.other(hh[v])-hei+1);
    }
}

void prep2(int u, int p, int b) {
    lon[u] = max(lon[u], b);
    for (auto& v : adj[u]) {
        if (v == p) continue;
        prep2(v, u, lon[u]+1);
    }
}

void dfs(int u, int p, int hei) {
    pii best(0, 0);
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, hei+1);
        best = max(best, pii(g[v], v));
    }

    ans[1] = max(ans[1], (int) adj[u].size()+1);

    int q = -1;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (v == best.second) continue;
        for (int i=0; i<=g[v]; ++i) {
            tmp[i+1]++;
        }
        q = max(g[v], q);
    }

    b2 = max((int) best.first+q+2, b2);

    for (int i=1; i<=min(q+1, g[best.second]); ++i) {
        ans[i*2] = max(ans[i*2], tmp[i]+dp(best.second, i)+(lon[u]>= i));
    }

    f[u] = move(f[best.second]);
    g[u] = g[best.second];

    for (int i=0; i<=h[best.second]; ++i) {
        dp(u, i) = 1;
    }
    g[u]++;
    f[u].push_back(0);
    for (int i=1; i<=q+1; ++i) {
        dp(u, i) += tmp[i];
        tmp[i] = 0;
    }
    h[u] = q+1;

    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (v == best.second) continue;
        for (int i=1; i<=g[v]; ++i) {
            ans[i*2] = max(ans[i*2], dp(v, i)+dp(u, i)-1+(lon[u]>= i));
        }
    }

    for (int i=1; i<=q+1; ++i) {
        int ic = dp(u, i) + (lon[u]>= i);
        int ipc = dp(u, i+1) + (lon[u]>= i+1);
        ans[i*2] = max(ans[i*2], ic);
        ans[i*2+1] = max(ans[i*2+1], ipc + (ic > ipc));
    }

    b2 = max(b2, g[u]+lon[u]);
}

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if (S==T) {
        T = (S=buf)+fread(buf, 1, 100000, stdin);
        if (S==T) return EOF;
    }
    return *S++;
}

void read(int& x) {
    static char c; x=0;
    for(c=get(); c<'0' || c>'9'; c=get());
    for(; c>='0'&&c<='9'; c=get()) x=x*10+c-'0';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(n);
    for (int i=0; i<=n; ++i) {
        h[i] = g[i] = -1;
    }
    for (int i=1; i<=n-1; ++i) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        ans[i] = 1;
    }
    prep(1, -1, 1);
    prep2(1, -1, 0);
    ans[n] = 1;
    dfs(1, -1, 1);
    for (int i=1; i<=b2; ++i) {
        ans[i] = max(ans[i], 2);
    }
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}