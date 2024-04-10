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
const int N = 100010;

int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	/*
	vi sieve(N, -1);
	vi primes;
	for(int i = 2; i < N; i++) {
		if(sieve[i] == -1) {
			primes.pb(i);
			for(int j = i; j += i; j < N) {
				sieve[j] = i;
			}
		}
	}
	*/
	int t; cin >> t;
	M00(A, t) {
		int w, l;
		cin >> w >> l;
		int perim = (w * l) - (w-2)*(l-2);
		int f = 1;
		vi facts;
		while(f * f <= perim) {
			if(perim % f == 0) {
				facts.pb(f);
				if(f*f != perim) facts.pb(perim/f);
			}
			f++;
		}
		set<int> ans;
		vi up = {w,l-1,w-1,l-2};
		vi down = {l,w-1,l-1,w-2};
		for(auto a : facts) {
			if(a <= 2) {
				ans.insert(a);
				continue;
			}
			int extra = 0;
			M00(i, 4) {
				int side = up[i] + extra;
				if(side % a > 1) {
					break;
				} else {
					extra = side % a;
					if(i == 3) ans.insert(a);
				}
			}
			extra = 0;
			M00(i, 4) {
				int side = down[i] + extra;
				if(side % a > 1) {
					break;
				} else {
					extra = side % a;
					if(i == 3) ans.insert(a);
				}
			}
		}
		cout << ans.size() << " ";
		for(auto x : ans) cout << x << " ";
		cout << endl;
	}
}