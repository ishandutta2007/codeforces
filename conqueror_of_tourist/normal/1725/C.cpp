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
const int MOD = 998244353;

int POW(int b, int e) {
	b %= MOD;
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


int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n, m;
	int s = 0;
	cin >> n >> m;
	vi arr(n); 
	M00(i, n) cin >> arr[i];
	M00(i, n) s += arr[i];
	//start at i
	int j = 0;
	int ps = 0;
	int diams = 0;
	M00(i, n) {
		while(ps < (s/2)) {
			ps += arr[j];
			j++;
			j %= n;
		}
		if(ps + ps == s) diams++;
		ps -= arr[i];
	}
	diams /= 2;
	int M = 300000;
	vi fact(M+1, 1), ifact(M+1);
	M00(i, M) fact[i+1] = (fact[i] * (i+1)) % MOD;
	ifact[M] = INV(fact[M]);
	for(int i = M-1; i >= 0; i--) {
		ifact[i] = (ifact[i+1] * (i+1)) % MOD;
	}

	int ans = 0;
	for(int same = 0; same <= diams; same++) {
		int need = same;
		if(same < diams) need += 2;
		else if(diams * 2 < n) need += 1;
		if(m < need) continue;

		int C = (fact[m] * ifact[m-same]) % MOD;
		int CC = (fact[diams] * ifact[diams - same]) % MOD;
		CC = (CC * ifact[same]) % MOD;

		int D = POW((m - same) * (m - same - 1), diams - same);
		int DD = POW(m - same, n - (diams * 2));
		int delta = (C * CC) % MOD;
		delta = (delta * D) % MOD;
		delta = (delta * DD) % MOD;
		ans += delta;
	}
	ans %= MOD;
	cout << ans << endl;
}