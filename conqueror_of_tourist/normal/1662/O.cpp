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
const int R = 22, D = 360;
bool arc[R][D];
bool line[R][D];

bool vis[R][D];

void solve() {
	int n; cin >> n;
	M00(i, R) M00(j, D) {
		arc[i][j] = false;
		line[i][j] = false;
		vis[i][j] = false;
	}
	M00(i, n) {
		char c; cin >> c;
		if(c == 'C') {
			int r, t1, t2;
			cin >> r >> t1 >> t2;
			for(int i = t1; i != t2; i = (i+1) % 360) {
				if(i == t2) break;
				arc[r][i] = true;
			}
		} else {
			int r1, r2, t;
			cin >> r1 >> r2 >> t;
			for(int i = r1+1; i <= r2; i++) {
				line[i][t] = true;
			}
		}
	}
	//stores radius, theta
	vector<pi> Q;
	M00(i, D) {
		if(!arc[1][i]) {
			Q.pb(mp(2, i));
			vis[2][i] = true;
		}
	}
	while(Q.size() > 0) {
		pi a = Q.back();
		Q.pop_back();
		int r = a.f, t = a.s;
		if(r >= 21) continue;
		//consider going down
		if(r >= 3 && !arc[r-1][t] && !vis[r-1][t]) {
			vis[r-1][t] = true;
			Q.pb(mp(r-1,t));
		}
		if(!line[r][t] && !vis[r][(t+D-1)%D]) {
			vis[r][(t+D-1)%D] = true;
			Q.pb(mp(r, (t+D-1)%D));
		}
		if(!line[r][(t+1)%D] && !vis[r][(t+1)%D]) {
			vis[r][(t+1)%D] = true;
			Q.pb(mp(r, (t+1)%D));
		}
		if(!arc[r][t] && !vis[r+1][t]) {
			vis[r+1][t] = true;
			Q.pb(mp(r+1,t));
		}
	}
	M00(i, D) {
		if(vis[21][i]) { 
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t;
	cin >> t;
	while(t--) solve();
}