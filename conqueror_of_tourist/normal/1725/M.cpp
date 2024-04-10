#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a)*(a))

#define MOO(i,a,b) for (int i=a; i<b; i++)
#define M00(i,a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a,b) for (int i=a; i<b; i++)

#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << endl, 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _<< " _ " <<

#define int long long

template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }

typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ld,ld> pld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;

const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 1e9+7;

int POW(int b, int e) {
	int r = 1;
	while(e) {
		if(e % 2 == 1) {
			r *= b;
			r %= MOD;
		}
		e /= 2;
		b *= b;
		b %= MOD;
	}
	return r;
}
int gcd(int a, int b) {
	if(b > a) return gcd(b,a);
	if(b == 0) return a;
	return gcd(b, a % b);
}
int INV(int a) {
	return POW(a, MOD-2);
}
//Constants and Variables here
template<int SZ> struct dijkstra {
    const int inf = 1e16;
    vector<pi> adj[SZ];
    bool vis[SZ];
    int d[SZ];

    void addEdge(int u, int v, int l) {
        adj[u].pb(mp(v, l));
    }
    int dist(int v) {
        return d[v];
    }
    void build(int u) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
		M00(i, SZ) {
			pq.push(mp(d[i], i));
		}
        while(!pq.empty()) {
            pi t = pq.top(); pq.pop();
            if(vis[t.s]) continue;
            vis[t.s] = 1;

            for(auto v: adj[t.s]) {
                if(d[v.f] > d[t.s] + v.s) {
                    d[v.f] = d[t.s] + v.s;
                    pq.push(mp(d[t.s]+v.s, v.f));
                }
            }
        }
    }
};

const int N = 100010;

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	dijkstra<N> G, RG;
	int n, m; cin >> n >> m;
	M00(i, m) {
		int a, b, w; cin >> a >> b >> w;
		a--; b--;
		G.addEdge(a,b,w);
		RG.addEdge(b,a,w);
	}
	M00(i, n) G.d[i] = G.inf;
	G.d[0] = 0;
	G.build(0);
	M00(i, n) RG.d[i] = G.d[i];
	RG.build(0);
	for(int i = 1; i < n; i++) {
		if(RG.d[i] >= 1e15) cout << -1 << " ";
		else cout << RG.d[i] << " ";
	}
	cout << endl;
}