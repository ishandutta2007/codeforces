#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, p[200005], l[200005], r[200005];
vector<int> G[200005];
int dpa[200005], dpm[200005];

void dfs(int v)
{
	LL s0 = 0, s1 = 0;
	rep(i, G[v].size()) {
		int u = G[v][i];
		dfs(u);
		s0 += dpa[u]; s1 += dpm[u];
	}
	s1 = min(s1, (LL)r[v]);
	if(l[v] <= s1) {
		dpa[v] = s0; dpm[v] = s1;
	} else {
		dpa[v] = s0 + 1; dpm[v] = r[v];
	}
}

void solve()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++) scanf("%d", &p[i]);
	rep1(i, n) scanf("%d%d", &l[i], &r[i]);
	rep1(i, n) G[i].clear();
	for(int i = 2; i <= n; i ++) G[p[i]].push_back(i);
	dfs(1);
	printf("%d\n", dpa[1]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}