#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 1001000;
int h[N], sh[N], f[N], g[N];
vector<int> ch[N];
int n, k;

void dfs(int u, int th) {
    h[u] = th;

    sh[u] = (ch[u].size() ? N : h[u]);
    f[u] = (ch[u].size() ? 0 : 1);
    g[u] = 1;

    for (auto& v : ch[u]) {
        dfs(v, th+1);
        sh[u] = min(sh[u], sh[v]);
        f[u] += (sh[v] <= h[u]+k ? f[v] : 0);
    }

    for (auto& v : ch[u]) {
        int z = f[u] - (sh[v] <= h[u]+k ? f[v] : 0) + g[v];
        g[u] = max(g[u], z);
    }

    //cerr << "! " << u << ": " << f[u] << " " << g[u] << endl;
}

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if (S==T) {
        T=(S=buf)+fread(buf, 1, 100000, stdin);
        if (S==T) return EOF;
    }
    return *S++;
}

void read(int& x) {
    static char c; x = 0;
    for (c=get(); c<'0' || c>'9'; c=get());
    for (; c>='0' && c<='9'; c=get()) x = x*10+c-'0';
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(n); read(k);
    for (int i=2; i<=n; ++i) {
        int p;
        read(p);
        ch[p].push_back(i);
    }

    dfs(1,1);
    cout << g[1] << "\n";
    return 0;
}