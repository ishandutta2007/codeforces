#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, p[100005];
vector<int> chi[100005];
int dep[100005];
int seq[100005], epos[100005], cnt;
int ans[100005], tot;

void dfs0(int v, int cd)
{
	dep[v] = cd;
	if(chi[v].empty()) return;
	rep(i, chi[v].size()) {
		int u = chi[v][i];
		dfs0(u, cd + 1);
		dep[v] = max(dep[v], dep[u]);
	}
	int uid = 0;
	rep(i, chi[v].size()) {
		int u = chi[v][i];
		if(dep[u] == dep[v]) uid = i;
	}
	if(uid != chi[v].size() - 1) swap(chi[v][chi[v].size() - 1], chi[v][uid]);
}

void dfs(int v)
{
	seq[cnt ++] = v;
	rep(i, chi[v].size()) {
		int u = chi[v][i];
		dfs(u);
	}
	if(cnt != n) ans[tot ++] = cnt;
}

int main()
{
	scanf("%d", &n);
	rep1(i, n - 1) scanf("%d", &p[i]);
	rep1(i, n - 1) chi[p[i]].push_back(i);
	
	dfs0(0, 0);
	dfs(0);
	rep(i, n) printf("%d ", seq[i]); printf("\n");
	printf("%d\n", tot);
	rep(i, tot) printf("%d ", seq[ans[i]]);
	printf("\n");
	return 0;
}