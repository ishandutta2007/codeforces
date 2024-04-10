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
void solve() {
	string s, t;
	cin >> s >> t;
	vector<char> ss, tt;
	int sb = 0, tb = 0;
	for(auto c : s) {
		if(c == 'B') sb += 1;
		else {
			if(ss.size() < 1 || ss.back() != c) ss.pb(c);
			else ss.pop_back();
		}
	}
	for(auto c : t) {
		if(c == 'B') tb += 1;
		else {
			if(tt.size() < 1 || tt.back() != c) tt.pb(c);
			else tt.pop_back();
		}
	}
	bool good = true;
	if((sb - tb) % 2 != 0) good = false;
	if(tt.size() != ss.size()) good = false;
	if(tt.size() > 0 && ss.size() > 0 && tt[0] != ss[0]) good = false;
	cout << (good ? "YES" : "NO") << endl;
	
}

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t;
	cin >> t;
	while(t--) solve();
}