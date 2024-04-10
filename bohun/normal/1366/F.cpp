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
#define int long long

using namespace std;

const int N = 2005;
const int MOD = 1e9 + 7;
const ll INF = 1e15;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n, m, q;
int a, b, c;

vector <pair<int, int>> g[N];

int dp[N][N];

struct Line {
	int a, b;
	bool operator < (Line x) const{
		return a < x.a;
	}
};

vector <Line> vec;

ld inter(Line p, Line q) {
	return (ld) (q.b - p.b) / (p.a - q.a);
}

ll cal(Line p, Line q) {
	ld xd = inter(p, q);
	if (xd >= 0) return floor(xd);
	return ceil(xd);
}

map <int, int> mapa;

int ans;

int sum(int n) {
	return 1LL * n * (n + 1) % MOD * ((MOD + 1) / 2) % MOD;
}

void add(Line p, int l, int r) {
	p.a %= MOD;
	p.b = (p.b % MOD + MOD) % MOD;
	add(ans, 1LL * (r - l + 1) * p.b % MOD);
	add(ans, 1LL * p.a * (sum(r) - sum(l - 1) + MOD) % MOD);
}

int32_t main() {
	scanf ("%lld%lld%lld", &n, &m, &q);
	rep(i, 1, m) {
		scanf ("%lld%lld%lld", &a, &b, &c);
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	
	const int L = m;
	
	rep(i, 1, n)
		rep(j, 0, L)
			dp[i][j] = -INF;
	dp[1][0] = 0;
	
	rep(j, 1, L)
		rep(i, 1, n)
			if (dp[i][j - 1] != -INF)
				for (auto it : g[i])
					dp[it.fi][j] = max(dp[it.fi][j], dp[i][j - 1] + it.se);
				
	rep(i, 1, L) {
		int Max = 0;
		rep(j, 1, n)
			Max = max(Max, dp[j][i]);
		add(ans, Max % MOD);
	}
	
	rep(len, 0, m - 1)
		rep(v, 1, n)
			for (auto it : g[v]) {
				int A = it.se;
				int B = dp[v][len] - it.se * len;
				if (!mapa.count(A))
					mapa[A] = B;
				else
					mapa[A] = max(mapa[A], B);
			}
	for (auto it : mapa)
		vec.pb({it.fi, it.se});
	sort(all(vec));
	
	vector <Line> G;
	for (auto it : vec) {
		while (ss(G) >= 2 && inter(it, G[ss(G) - 2]) < inter(G.back(), G[ss(G) - 2]))
			G.pop_back();
		G.pb(it);
	}
	vec = G;		
				
	ll Left = L + 1;
	ll Right = q;
	
	int ind = 0;
	
	while (Left <= Right) {
		ll R;
		if (ind + 1 == ss(vec)) R = Right;
		else R = cal(vec[ind], vec[ind + 1]);
		
		R = min(R, Right);
		
		
		if (Left <= R) {
			add(vec[ind], Left, R);
			Left = R + 1;
		}
		ind++;
	}
	
	printf ("%lld\n", ans);
	
	
	return 0;
}