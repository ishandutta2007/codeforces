// Problem: D. Priority Queue
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.ml/contest/1542/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
using namespace std;
template<const int mod>
struct modint {
	int x;
	modint<mod>(int o = 0) {
		x = o;
	}
	modint<mod> &operator = (int o) {
		return x = o, *this;
	}
	modint<mod> &operator +=(modint<mod> o) {
		return x = x + o.x >= mod ? x + o.x - mod : x + o.x, *this;
	}
	modint<mod> &operator -=(modint<mod> o) {
		return x = x - o.x < 0 ? x - o.x + mod : x - o.x, *this;
	}
	modint<mod> &operator *=(modint<mod> o) {
		return x = 1ll * x * o.x % mod, *this;
	}
	modint<mod> &operator ^=(int b) {
		modint<mod> a = *this, c = 1;
		for (; b; b >>= 1, a *= a)
			if (b & 1)
				c *= a;
		return x = c.x, *this;
	}
	modint<mod> &operator /=(modint<mod> o) {
		return *this *= o ^= mod - 2;
	}
	modint<mod> &operator +=(int o) {
		return x = x + o >= mod ? x + o - mod : x + o, *this;
	}
	modint<mod> &operator -=(int o) {
		return x = x - o < 0 ? x - o + mod : x - o, *this;
	}
	modint<mod> &operator *=(int o) {
		return x = 1ll * x * o % mod, *this;
	}
	modint<mod> &operator /=(int o) {
		return *this *= ((modint<mod>(o)) ^= mod - 2);
	}
	template<class I>friend modint<mod> operator +(modint<mod> a, I b) {
		return a += b;
	}
	template<class I>friend modint<mod> operator -(modint<mod> a, I b) {
		return a -= b;
	}
	template<class I>friend modint<mod> operator *(modint<mod> a, I b) {
		return a *= b;
	}
	template<class I>friend modint<mod> operator /(modint<mod> a, I b) {
		return a /= b;
	}
	friend modint<mod> operator ^(modint<mod> a, int b) {
		return a ^= b;
	}
	friend bool operator ==(modint<mod> a, int b) {
		return a.x == b;
	}
	friend bool operator !=(modint<mod> a, int b) {
		return a.x != b;
	}
	bool operator ! () {
		return !x;
	}
	modint<mod> operator - () {
		return x ? mod - x : 0;
	}
};
typedef modint<998244353> mint;
#define int long long
const int N = 600;
int n;
char op[N];
int x[N];
mint dp[N][N];
 
signed main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		op[i] = getchar();
		while (op[i] != '+' && op[i] != '-')
			op[i] = getchar();
		if (op[i] == '+')
			scanf("%d", &x[i]);
	}
	mint ans = 0;
	//
	for (int i = 1; i <= n; i++)
		if (op[i] == '+') {
			// 
			memset(dp, 0, sizeof dp);
			dp[0][0] = 1;
			for (int j = 1; j < i; j++)
				for (int k = 0; k <= j; k++) {
					if (op[j] == '-') {
						if (k != 0)
							dp[j][k] = dp[j - 1][k + 1] + dp[j - 1][k];
						else
							dp[j][k] = dp[j - 1][k + 1] + dp[j - 1][k] * 2;
					} else {
						if (x[j] > x[i])
							dp[j][k] = dp[j - 1][k] * 2;
						else if (k != 0)
							dp[j][k] = dp[j - 1][k - 1] + dp[j - 1][k];
						else
							dp[j][k] = dp[j - 1][k];
					}
				}
			if (i == n) {
				for (int k = 0; k <= n; k++)
					ans += x[i] * dp[i - 1][k];
			} else {
				for (int j = i + 1; j <= n; j++) {
					int pre = j - 1;
					if (j == i + 1)
						pre = i - 1;
					for (int k = 0; k <= j; k++) {
						if (op[j] == '-') {
							dp[j][k] = dp[pre][k + 1] + dp[pre][k];
						} else {
							if (x[j] >= x[i])
								dp[j][k] = dp[pre][k] * 2;
							else if (k != 0)
								dp[j][k] = dp[pre][k - 1] + dp[pre][k];
							else
								dp[j][k] = dp[pre][k];
						}
					}
				}
				for (int k = 0; k <= n; k++)
					ans += x[i] * dp[n][k];
					//cout<<x[i]<<" "<<dp[n][k].x<<endl;;
			}
			//cout << ans.x<<endl;;
		}
	cout << ans.x;
}