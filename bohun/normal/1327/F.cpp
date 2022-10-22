#include <bits/stdc++.h>
#define LL long long
#define LD long double
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

const int MOD = 998244353;
const int pod = (1 << 19);
const int N = pod;

void add3(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int dp[N];


int n, k, m;
int a, b, c;

vector <pair<int, int>> one[50], zer[50];
int pref[N];

int suf[N];

vector <pair<int, int>> compress(vector <pair<int, int>> x) {
	sort(all(x));
	int sz = ss(x);
	rep(i, 0, sz) suf[i] = n + 10;
	per(i, 0, sz - 1) suf[i] = min(suf[i + 1], x[i].se);
	vector <pair<int, int>> res = {};
	rep(i, 0, sz - 1) {
		if (suf[i + 1] <= x[i].se) continue;
		res.pb(x[i]);
	}
	sort(all(res));
	return res;	
}

int solve(int bit) {
	rep(i, 0, N - 1) pref[i] = dp[i] = 0;
	
	zer[bit] = compress(zer[bit]);
	//cat("A");
	//for (auto it : zer[bit]) {
	//	printf ("%d %d %d\n", it.fi, it.se, bit);
	//}
	
	for (auto it : one[bit]) {
		pref[it.fi]++;
		pref[it.se + 1]--;
	}
	rep(i, 1, N - 1) pref[i] += pref[i - 1];
	dp[0] = 1;
	
	int j = 0;
	int wsk = 0;
	int Sum = 1;
	
	rep(i, 1, n) {
		//if (pref[i]) printf ("-- > %d\n", i);
		if (pref[i] > 0) continue;
		while (j < ss(zer[bit]) && zer[bit][j].se < i) {
			while (wsk < zer[bit][j].fi) {
				Sum = (Sum - dp[wsk] + MOD) % MOD;
				wsk++;
			}
			j++;
		}
		dp[i] = Sum;
		//printf ("%d %d\n", i, dp[i]);
		Sum = (Sum + dp[i]) % MOD;
	}
	int L = 0;
	if (ss(zer[bit])) {
		L = zer[bit].back().fi;
	}
	Sum = 0;
	rep(i, L, n) add3(Sum, dp[i]);
	return Sum;
}
	

int main() {
	scanf ("%d%d%d", &n, &k, &m);
	rep(i, 1, m) {
		scanf ("%d%d%d", &a, &b, &c);	
		rep(j, 0, k - 1) {
			if (((1 << j) & c)) one[j].pb({a, b});
			else zer[j].pb({a, b});
		}
	}
	int ans = 1;
	rep(i, 0, k - 1) 
		ans = (LL) ans * solve(i) % MOD;
	printf ("%d\n", ans);
	


	return 0;
}