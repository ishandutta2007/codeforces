#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 300300;

int w[NMAX];
vector<pii> adj[NMAX];

ll ans = 0;

int N;

struct mmm {
    ll a, b;
    mmm () :a(0), b(0) {}
    void insert(ll x) {
        if(x > a) {swap(a, b); a=x;}
        else if(x > b) b=x;
    }
};

ll dfs(int u, int p) {
    mmm mx;
    for(auto& pp : adj[u]) {
        int v = pp.first, c = pp.second;
        if(v == p) continue;
        mx.insert(dfs(v, u)-c);
    }
    ans = max(mx.a+mx.b+w[u], ans);
    return mx.a+w[u];
}

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}

inline void read(int& x) {
	char c; x = 0;
	for(c=get();c<'0'||c>'9';c=get());
	for(;c>='0'&&c<='9';c=get()) x = x*10+c-'0';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(N);
    for(int i=1;i<=N;++i) read(w[i]);
    for(int i=1;i<N;++i) {
        int u, v, c;
		read(u); read(v); read(c);
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}