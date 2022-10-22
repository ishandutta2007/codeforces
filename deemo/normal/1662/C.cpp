#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using ll = long long;

/*
 * Author: Matthew Agar
 * Date: 2021-07-29
 * Source: Own work
 * Description: Class for integer operations under modulo
 * Time: O(1) for add, subtract, multiply, O(log MOD) for division
 * Status: stress-tested
 */

template <int m>
struct ModInt {
    int v;
    static const int MOD = m;
    
    ModInt(ll val = 0) { v = (val % MOD + MOD) % MOD; }
    
    ModInt& operator +=(const ModInt& he) { v += he.v; if(v >= MOD) v -= MOD; return *this; }
    ModInt& operator -=(const ModInt& he) { v -= he.v; if(v < 0) v += MOD; return *this; }    
    ModInt& operator *=(const ModInt& he) { v = (ll) v * he.v % MOD; return *this; }
    
    friend ModInt pw(ModInt a, ll b) {
        ModInt r = 1; assert(b >= 0);
        while(b > 0) {
            if(b & 1) r *= a;
            a *= a; b >>= 1; 
        }
        return r;
    }
    
    friend ModInt inv(ModInt a) { return pw(a, MOD-2); }    
    ModInt& operator /= (const ModInt& he) { return *this *= inv(he); }
    
    friend ModInt operator +(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator -(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator *(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator /(ModInt a, const ModInt& b) { return a /= b; }
    
    friend ostream& operator <<(ostream& out, const ModInt& a) { return out << a.v; }
    friend bool operator ==(const ModInt& a, const ModInt& b) { return a.v == b.v; }
    friend bool operator !=(const ModInt& a, const ModInt& b) { return !(a == b); }
};

typedef ModInt<998244353> mint;

const char nl = '\n';
const int MX = 100 + 10;
const int MK = 1e4 + 10;

/*
 * Author: Matthew Agar
 * Date: 2021-08-09
 * Source: Own work
 * Description: Matrix multiplication and power
 *              - Use std::array instead of std::vector if fixed sized matrices 
 *                (reduces memory usage by a lot!)
 * Time: O(n^3) for mul (square matrices), O(n^3 * log k) for pw
 * Status: stress-tested
 */

#define rep(i,a,b) for(int i = a; i < (int) (b); i++)
typedef mint num;
typedef vector<vector<num>> mat;

mat neww(int n, int m) {
	return vector<vector<num>>(n, vector<num>(m));
}

mat mul(const mat& a, const mat& b) {
	int n = sz(a), m = sz(b[0]);
	assert(sz(a[0]) == sz(b));
	mat c = neww(n, m);
	rep(i,0,n)
		rep(j,0,sz(a[0]))
			rep(k,0,m)
				c[i][k] += a[i][j] * b[j][k];
	return c;
}

mat pw(mat a, ll k) {
	assert(sz(a) == sz(a[0]));
	int n = sz(a);
	mat r = neww(n, n);
	rep(i,0,n) r[i][i] = 1;
	while(k) {
		if(k & 1) r = mul(r,a);
		a = mul(a,a);
		k >>= 1;
	}
	return r;
}

bool adj[MX][MX];
int n, m, k;
/*
mint dp[MK][MX];
mint pre[2][MX];

mint work(int a) {
	for(int i = 0; i <= k; i++) {
		fill_n(dp[i], n, 0);
	}
	for(int x = 0; x < 2; x++) {
		fill_n(pre[x], n, 0);
	}
	dp[0][a] = 1;
	pre[0][a] = 1;
	for(int i = 1; i <= k; i++) {
		for(int v = 0; v < n; v++) {
			for(int u = 0; u < n; u++) {
				if(adj[v][u]) {
					mint sum = pre[(i-1)%2][u] - pre[i%2][v];
					dp[i][v] += sum;
				}
			}
			pre[i%2][v] += dp[i][v];
		}
	}
	return dp[k][a];
}
*/

void solve() {
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a][b] = adj[b][a] = true;
	}
	if(k == 0) {
		cout << n << nl;
		return;
	}
	if(k == 1) {
		cout << "0\n";
		return;
	}
	const int N = 4*n;
	mat M[2];
	for(int i = 0; i < 2; i++) {
		M[i] = neww(N, N);
	}

	auto enDP = [&](int i, int p) {
		assert(p < 2);
		return i + n*p;
	};

	auto enP = [&](int i, int p) {
		assert(p < 2);
		return i + n*p + 2*n;
	};

	for(int i = 0; i < 2; i++) {
		for(int v = 0; v < n; v++) {
			for(int p = 0; p < 2; p++) {
				M[i][enP(v, p)][enP(v, p)] += 1;
			}
		}
	}
	for(int v = 0; v < n; v++) {
		for(int u = 0; u < n; u++) {
			if(adj[v][u]) {
				for(int i = 0; i < 2; i++) {
					M[i^1][enP(v, i^1)][enDP(u, i)] += 1;
					M[i^1][enP(u, i)][enDP(u, i)] -= 1;
					// maybe?
					M[i^1][enP(v, i^1)][enP(u, i)] += 1;
					M[i^1][enP(u, i)][enP(u, i)] -= 1;
				}
			}
		}
	}
	int half = k/2;
	mat prod = mul(M[0], M[1]);
	prod = pw(prod, half);
	if(k % 2 == 1) {
		prod = mul(prod, M[0]);
	}
	mint ans = 0;
	for(int i = 0; i < n; i++) {
		ans += prod[enP(i, 0)][enDP(i, k%2)];
	}
	cout << ans << nl;

	/*
	mint ans = 0;
	for(int a = 0; a < n; a++) {
		ans += work(a);
	}
	cout << ans << nl;
	*/
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int te = 1;
//	cin >> te;
	while(te--) {
		solve();
	}
}