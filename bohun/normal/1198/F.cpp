#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)
 
using ll = long long;
using namespace std;

ll rnd() {
	ll x = 0;
	rep(i, 0, 17)
		x = 10 * x + rand() % 10;
	return x;
}

const int N = 1e5 + 100;
const int K = 9;
const int M = 2 * K * K;
const int S = 1 << (K + K);


int n, a[N], skad[M][S];
bool dp[M][S];

vector <int> factorize(int u) {
	vector <int> p;
	for (int i = 2; i * i <= u; ++i) 
		if (u % i == 0) {
			p.pb(i);
			while (u % i == 0) u /= i;
		}
	if (u > 1) p.pb(u);
	return p;
}

int full(int x) {
	return (1 << x) - 1;
}

int cnt[N], M1[N], M2[N], ans[N];

int qq(int q, vector <int> x) {
	int mask = 0;
	rep(i, 0, ss(x) - 1)
		if (q % x[i] == 0)
			mask += 1 << i;
	return full(ss(x)) - mask;
}

void solve(int x, int y) {
	if (x == y) return;
	auto fx = factorize(a[x]), fy = factorize(a[y]);
	int sz1 = ss(fx), sz2 = ss(fy);
	
	rep(i, 0, sz1 + sz2 - 1) cnt[i] = 0;	
	vector <int> num;
	rep(i, 1, n) {
		if (i == x || i == y) continue;
		M1[i] = qq(a[i], fx);
		M2[i] = qq(a[i], fy);
		bool flag = 0;
		rep(j, 0, sz1 - 1)
			if (M1[i] >> j & 1 && cnt[j] < K + 2)
				flag = true;
		rep(j, 0, sz2 - 1)	
			if (M2[i] >> j & 1 && cnt[sz1 + j] < K + 2)
				flag = true;
		if (!flag) continue;
		num.pb(i);
		rep(j, 0, sz1 - 1)
			if (M1[i] >> j & 1) cnt[j]++;
		rep(j, 0, sz2 - 1)
			if (M2[i] >> j & 1) cnt[sz1 + j]++;
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	int sz = ss(num);
	rep(i, 0, sz) rep(j, 0, S - 1) dp[i][j] = false;
	dp[0][0] = true;
	rep(i, 0, sz - 1) {
		int x = num[i];
		rep(mask, 0, (1 << (sz1 + sz2)) - 1) {
			if (!dp[i][mask]) continue;
			int nmask = mask | M1[x];
			dp[i + 1][nmask] = true;
			skad[i + 1][nmask] = mask;
			nmask = mask | (M2[x] << sz1);
			dp[i + 1][nmask] = true;
			skad[i + 1][nmask] = mask;
		}
	}
	
	if (!dp[sz][full(sz1 + sz2)]) return;
		
	ans[x] = 0; ans[y] = 1;
	int mask = full(sz1 + sz2);
	per(i, 0, sz - 1) {
		int nmask = skad[i + 1][mask], x = num[i];
		if (31 - __builtin_clz(nmask ^ mask) < sz1) ans[x] = 0;
		else ans[x] = 1;
		mask = nmask;
	}
	
	puts("YES");
	rep(i, 1, n) printf ("%d ", ans[i] + 1);
	exit(0);
}
 
int main() {
	srand(2137);
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	
	while (1.0 * clock() / CLOCKS_PER_SEC <= 0.4) {
		int x = rnd() % n + 1, y = rnd() % n + 1;
		solve(x, y);
	}
	puts("NO");
	
	return 0;
}