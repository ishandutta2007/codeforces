#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int n, m, g, eu[300005], ev[300005], ew[300005];
vector<PII> G[300005];
int la, lb;
vector<int> hva[300005], hvb[300005];
 
int deg[300005], ptr[300005], seq[600005], tot;
bool used[600005];
void dfs(int v)
{
	for(; ptr[v] < (int)G[v].size(); ) {
		int u = G[v][ptr[v]].first, e = G[v][ptr[v]].second, d = 1;
		if(e < 0) e *= d *= -1;
		ptr[v] ++;
		if(used[e]) continue;
		used[e] = true;
		dfs(u);
		seq[tot ++] = e * d;
	}
}
 
int ca[3][300005];
vector<pair<int, PII> > H[300005];
void calc(int cw, int& len, vector<int> ret[])
{
	rep1(i, n) G[i].clear();
	rep1(i, n) deg[i] = ptr[i] = 0;
	rep1(i, n + m) used[i] = false;
	tot = 0;
	
	rep1(i, m) if(ew[i] == cw) {
		G[eu[i]].push_back(MP(ev[i], i)); G[ev[i]].push_back(MP(eu[i], -i));
		deg[eu[i]] ++; deg[ev[i]] ++;
	}
	int rm = m, pre = -1;
	rep1(i, n) if(deg[i] & 1) {
		if(cw == 1) g ++;
		if(pre == -1) pre = i;
		else {
			rm ++;
			G[pre].push_back(MP(i, rm)); G[i].push_back(MP(pre, -rm));
			pre = -1;
		}
	}
	
	rep1(i, n) {
		seq[tot ++] = MOD;
		int ori = tot;
		dfs(i);
		reverse(seq + ori, seq + tot);
		for(int j = ori; j < tot; j ++) if(seq[j] > m || seq[j] < -m) {
			rotate(seq + ori, seq + j, seq + tot); break;
		}
	}
	
	len = 1;
	rep(i, tot) if(seq[i] > m || seq[i] < -m) {
		if(!ret[len].empty()) len ++;
	} else ret[len].push_back(seq[i]);
	if(ret[len].empty()) len --;
	
	rep1(i, len) {
		int u = ret[i][0] < 0 ? ev[-ret[i][0]] : eu[ret[i][0]], v = ret[i].back() < 0 ? eu[-ret[i].back()] : ev[ret[i].back()];
		if(u != v) {
			ca[cw][i] = 0;
			H[u].push_back(MP(v, MP(i, cw)));
			H[v].push_back(MP(u, MP(-i, cw)));
		} else ca[cw][i] = 1;
	}
}
 
void dfs1(int v)
{
	rep(i, H[v].size()) {
		int u = H[v][i].first, ce = H[v][i].second.first, cw = H[v][i].second.second, ct = 1;
		if(ce < 0) ce *= ct *= -1;
		if(ca[cw][ce]) continue;
		ca[cw][ce] = ct;
		dfs1(u);
	}
}
 
int ans[300005];
int main()
{
	scanf("%d%d", &n, &m);
	rep1(i, m) scanf("%d%d%d", &eu[i], &ev[i], &ew[i]);
	
	calc(1, la, hva);
	calc(2, lb, hvb);
	
	rep1(i, n) if((int)H[i].size() == 1) dfs1(i);
	rep1(i, n) dfs1(i);
	rep1(i, la) rep(j, hva[i].size()) {
		int ce = hva[i][j], ct = 1;
		if(ce < 0) ce *= ct *= -1;
		ans[ce] = ca[1][i] * ct > 0 ? 2 : 1;
	}
	rep1(i, lb) rep(j, hvb[i].size()) {
		int ce = hvb[i][j], ct = 1;
		if(ce < 0) ce *= ct *= -1;
		ans[ce] = ca[2][i] * ct > 0 ? 2 : 1;
	}
	
	printf("%d\n", g);
	rep1(i, m) printf("%d", ans[i]);
	return 0;
}