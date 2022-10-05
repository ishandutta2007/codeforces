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


int32_t main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vi arr(n), b(3);
	M00(i, n) cin >> arr[i];
	M00(i, n) b[arr[i] % 3]++;
	M00(z, 3) {
		vvi conf(3, vi(3));
		M00(i, 3) M00(j, 3) {
			int m = (i + j) * (i + j) + i*j;
			m %= 3;
			if(m != z) conf[i][j] = 1;
		}
		//conflict resolve
		M00(m1, 8) M00(m2, 8) {
			bool good = true;
			int s1 = 0, s2 = 0;
			M00(i, 3) M00(j, 3) {
				if((m1 & (1 << i)) && (m2 & (1 << j)) && (!(conf[i][j]))) good = false;
			}
			M00(i, 3) {
				if(m1 & (1 << i)) s1 += b[i];
				if(m2 & (1 << i)) s2 += b[i];
				if(b[i] > 0 && (!((m1 | m2) & (1 << i)))) good = false;
			}
			if(s1 < n/2 || s2 < n/2) good = false;
			if(good) {
				cout << z << endl;
				int used = 0;
				vi ans(n);
				M00(i, n) {
					int type = arr[i] % 3;
					bool a1 = m1 & (1 << type);
					bool a2 = m2 & (1 << type);
					if(a1 && !a2) { 
						ans[i] = 1;
						used++;
					}
					if(a2 && !a1) ans[i] = 2;
				}
				M00(i, n) {
					int type = arr[i] % 3;
					bool a1 = m1 & (1 << type);
					bool a2 = m2 & (1 << type);
					if(ans[i] == 0 && used < n/2) {
						used++;
						ans[i] = 1;
					} else if(ans[i] == 0) {
						ans[i] = 2;
					}
				}
				M00(i, n) cout << ans[i]-1;
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}