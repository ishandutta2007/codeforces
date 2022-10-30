#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 1e9+7;
const int N = 2e5+5;
int p[N],n;
ll dp[N],ans[N];
vector<ll> cv[N],pre[N],post[N],c[N];

void dfs1(int u) {
	for(int v : c[u]) {
		dfs1(v);
		cv[u].pb(1+dp[v]);
	}
	pre[u].pb(1);
	post[u].pb(1);
	for(int i = 0; i < c[u].size(); ++i) {
		pre[u].pb(pre[u].back()*cv[u][i]%M);
		post[u].pb(post[u].back()*cv[u][cv[u].size()-i-1]%M);
	}
	dp[u] = pre[u].back();
}

void dfs2(int u) {
	ans[u] = dp[u];
	// test << "rooted at " << u << ":\n";
	// for(int i = 1; i <= n; ++i)
	// 	test << dp[i] << " ";
	// test << "\n";
	for(int i = 0; i < c[u].size(); ++i) {
		int v = c[u][i];
		dp[u] = pre[u][i]*post[u][c[u].size()-i-1]%M*(1+dp[p[u]])%M;
		dp[v] = dp[v]*(1+dp[u])%M;
		dfs2(v);
		dp[v] = pre[v].back();
		dp[u] = ans[u];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	p[1]=0;
	dp[0]=0;
	for(int i = 2; i <= n; ++i) {
		cin >> p[i];
		c[p[i]].pb(i);
	}
	dfs1(1);
	dfs2(1);
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}