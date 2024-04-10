#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 2002;
int M, n;
 
void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}
int ad(int a, int b) {
	add(a, b);
	return a;
}
int mu(int a, int b) {
	return int(1LL * a * b % M);
}
void mul(int& a, int b) {
	a = mu(a, b);
}
int inv(int x) {
	return x == 1 ? 1 : M - mu(M / x, inv(M % x));
}

vi G[N];
int dp[N][N], aux2[N][N];

void dfs(int u, int p = 0) {
	vi c;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		c.PB(v);
	}
	if(c.empty()) {
		for(int i = 1; i < n; i++)
			dp[u][i] = i;
		return;
	}
	if(u != 1) {
		vi aux(n);
		for(int j = 0; j < n - 1; j++) { // u removed at position j
			vi p;
			{
				int tt = 1;
				for(int v:c) {
					mul(tt, dp[v][j + 1]);
					p.PB(tt);
				}
			}

			vi s;
			{
				reverse(ALL(c));
				int tt = 1;
				for(int v:c) {
					mul(tt, dp[v][j + 1]);
					s.PB(tt);
				}
				reverse(ALL(c));
				reverse(ALL(s));
			}
			for(int i = 0; i < SZ(c); i++) { // v is the only child left when u is removed 
				int v = c[i];
				add(aux2[v][j + 1], mu((i ? p[i - 1] : 1), (i + 1 < SZ(c) ? s[i + 1] : 1)));
			}
			if(SZ(c))
				add(aux[j + 1], M - mu(p.back(), SZ(c) - 1));
		}
		for(int v:c) {
			for(int i = 1; i < n; i++) {
				add(aux2[v][i], aux2[v][i - 1]);
				add(dp[u][i], mu(aux2[v][i], dp[v][i]));
			}
		}
		for(int i = 1; i < n; i++) {
			add(aux[i], aux[i - 1]);
			add(dp[u][i], aux[i]);
		}
	} else {
		for(int i = 1; i < n; i++) {
			int tt = 1;
			for(int v:c)
				mul(tt, dp[v][i]);
			dp[u][i] = tt;
		}
	}
}
int C[N][N];

signed main()
{
	IO_OP;

	cin >> n >> M;
	for(int i = 0; i < N; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
			C[i][j] = ad(C[i - 1][j], C[i - 1][j - 1]);
	}

	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < i; j++)
			add(dp[1][i], M - mu(dp[1][j], C[i][j]));
		cout << dp[1][i] << " ";
	}
		
}