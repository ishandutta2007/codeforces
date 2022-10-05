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

typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
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
const int N = 200100;
vi adj[N];
vi seen(N, -1);
vi seeder(N, -1);
int n, m, s;
int t = -1;
int p1, p2;
bool done = false;
int seed = -1;


void dfs(int v, int par) {
	if(done) return;
	if(v == s) return;
	if(seen[v] != -1 && seeder[v] != seed) {
		t = v;
		p1 = par;
		p2 = seen[v];
		done = true;
	}
	if(seen[v] != -1) return;
	//important
	seen[v] = par;
	seeder[v] = seed;
	for(auto &w : adj[v]) {
		dfs(w, v);
	}
}

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin >> n >> m >> s;
	s--;
	M00(i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
	}
	for(auto &v : adj[s]) {
		seed = v;
		dfs(v, s);

		if(t != -1) {
			vi path1, path2;
			path1.pb(p1);
			path2.pb(p2);
			while(path1.back() != s) {
				path1.pb(seen[path1.back()]);
			}
			while(path2.back() != s) {
				path2.pb(seen[path2.back()]);
			}
			reverse(all(path1));
			reverse(all(path2));
			cout << "Possible" << endl;
			cout << path1.size() + 1 << endl;
			for(auto v : path1) cout << v+1 << " ";
			cout << t + 1 << endl;
			cout << path2.size() + 1 << endl;
			for(auto v : path2) cout << v+1 << " ";
			cout << t + 1 << endl;
			exit(0);
		}
	}
	cout << "Impossible" << endl;
}