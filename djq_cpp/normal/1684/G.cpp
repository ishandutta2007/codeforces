#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

namespace fl
{
	int vn, en;
	PII E[2100005];
	vector<int> G[2005];
	void clear(int n)
	{
		vn = n;
		rep(i, n) G[i].clear();
		en = 0;
	}
	int dis[2005];
	int adde(int u, int v, int w)
	{
		E[en] = MP(v, w);
		G[u].push_back(en ++);
		E[en] = MP(u, 0);
		G[v].push_back(en ++);
		return en - 2;
	}
	int pos[2005], que[2005], fr, rr;
	bool bfs(int v, int t)
	{
		rep(i, vn) {
			pos[i] = 0;
			dis[i] = -1;
		}
		fr = rr = 0;
		dis[v] = 0;
		que[rr ++] = v;
		while(fr < rr) {
			v = que[fr ++];
			rep(i, G[v].size()) {
				int ce = G[v][i];
				if(E[ce].second == 0) continue;
				if(dis[E[ce].first] == -1) {
					dis[E[ce].first] = dis[v] + 1;
					que[rr ++] = E[ce].first;
				}
			}
		}
		return dis[t] != -1;
	}
	int dfs(int s, int t, int tot = INF)
	{
		if(s == t) return tot;
		int ret = 0;
		for(; pos[s] < (int)G[s].size(); pos[s] ++) {
			int ce = G[s][pos[s]];
			if(E[ce].second > 0 && dis[E[ce].first] == dis[s] + 1) {
				int cf = min(E[ce].second, tot);
				cf = dfs(E[ce].first, t, cf);
				tot -= cf;
				ret += cf;
				E[ce].second -= cf;
				E[ce ^ 1].second += cf;
			}
			if(tot == 0) break;
		}
		return ret;
	}
	int calc(int s, int t)
	{
		int ret = 0;
		while(bfs(s, t)) ret += dfs(s, t);
		return ret;
	}
}

int n, m, a[1005], eid[1005][1005], b;
vector<PII> ans;

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	fl::vn = n + 2;
	rep(i, n) if(a[i] > m / 3) {
		fl::adde(i, n + 1, 1); b ++;
	} else eid[n][i] = fl::adde(n, i, 1);
	rep(i, n) if(a[i] > m / 3) rep(j, n) if(a[i] % a[j] == 0 && a[j] + a[i] * 2LL <= m) eid[i][j] = fl::adde(j, i, 1);
	if(fl::calc(n, n + 1) != b) {
		printf("-1\n"); return 0;
	}
	
	rep(i, n) if(a[i] > m / 3) {
		rep(j, n) if(a[i] % a[j] == 0 && a[j] + a[i] * 2LL <= m && fl::E[eid[i][j]].second == 0) ans.push_back(MP(a[j] + a[i] * 2, a[j] + a[i]));
	} else if(fl::E[eid[n][i]].second != 0) ans.push_back(MP(a[i] * 3, a[i] * 2));
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}