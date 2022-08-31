#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n;
bool chv[200005], ist[200005];
vector<int> G[200005], H[200005];
int par[200005], otd[200005], sum[200005];
vector<int> fr;
void dfs(int v, int p, int d)
{
	par[v] = p;
	chv[v] = (d ^ (int)G[v].size()) & 1;
	ist[v] = d & 1;
	if(chv[v]) fr.push_back(v);
	sum[v] = chv[v] - ist[v];
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == p) continue;
		dfs(u, v, d ^ 1);
		sum[v] += sum[u];
	}
}

vector<PII> ca;
void solve()
{
	scanf("%d", &n);
	rep1(i, n) G[i].clear();
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v); G[v].push_back(u);
	}
	fr.clear();
	dfs(1, 0, 0);
	rep1(i, n) if(max(sum[i], -sum[i]) != (i >= 2)) {
		printf("NO\n"); return;
	}
	printf("YES\n");
	
	rep1(i, n) H[i].clear();
	for(int i = 2; i <= n; i ++) if(sum[i] > 0) H[i].push_back(par[i]);
	else H[par[i]].push_back(i);
	
	rep(i, fr.size()) {
		if(ist[fr[i]]) continue;
		ca.clear();
		int nj;
		for(int j = fr[i]; chv[j]; j = nj) {
			nj = H[j].back();
			ca.push_back(MP(j, nj));
			H[j].pop_back();
		}
		fr.push_back(nj);
		reverse(ca.begin(), ca.end());
		rep(j, ca.size()) {
			printf("%d %d\n", ca[j].first, ca[j].second);
			swap(chv[ca[j].first], chv[ca[j].second]);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}