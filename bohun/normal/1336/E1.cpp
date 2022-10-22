#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int nax = 2e5 + 100;
const int mod = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int bit (ll mask, int k) {
	return (mask >> k) & 1;
}

int n, m;
ll a;

ll basis[50];
ll res[50];
vector <ll> q;

unordered_map <ll, int> dp[50][50];

int main() {
	scanf ("%d%d", &n, &m);
	ll b = 1;
	rep(i, 1, n) {
		scanf ("%lld", &a);
		per(j, 0, m - 1) {
			if (!bit(a, j)) continue;
			if (basis[j]) a ^= basis[j];
			else {
				q.pb(a);
				basis[j] = a;
				break;
			}
		}
		if (!a) b = 2 * b % mod;
	}
	#define pc(x) __builtin_popcountll(x)
	if (ss(q) <= 20) {
		int w = ss(q);
		rep(mask, 0, (1 << w) - 1) {
			ll x = 0;
			rep(j, 0, w - 1)
				if (bit(mask, j))
					x ^= q[j];
			res[pc(x)]++;
		}
		rep(i, 0, m)
			printf ("%lld ", res[i] * b % mod);
		return 0;
	}
	
	q.clear();
	ll maska = 0;
	per(i, 0, m - 1) {
		if (!basis[i]) {
			maska += 1LL << i;
			continue;
		}
		per(j, 0, i - 1) {
			if (!basis[j]) continue;
			if (bit(basis[i], j)) basis[i] ^= basis[j];
		}
		q.pb(basis[i]);
	}
	
	dp[0][0][0] = 1;
	rep(i, 0, ss(q) - 1) 
		rep(j, 0, ss(q)) 
			for (auto it : dp[i][j]) {
				add(dp[i + 1][j][it.fi], it.se);
				ll nowa = (it.fi ^ (q[i] & maska));
				add(dp[i + 1][j + 1][nowa], it.se);
			}
	rep(j, 0, ss(q)) 
		for (auto it : dp[ss(q)][j]) {
			res[j + pc(it.fi)] += it.se;
		}
	rep(i, 0, m) {
		res[i] %= mod;
		printf ("%lld ", res[i] * b % mod);
	}
			
	
	
	
	return 0;
}