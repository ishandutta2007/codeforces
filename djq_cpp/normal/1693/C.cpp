#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m, ans[200005], deg[200005];
vector<int> G[200005];
bool vis[200005];
priority_queue<PII, vector<PII>, greater<PII> > que;

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[v].push_back(u); deg[u] ++;
	}
	rep1(i, n) ans[i] = INF;
	ans[n] = 0;
	que.push(MP(0, n));
	while(!que.empty()) {
		int v = que.top().second; que.pop();
		if(vis[v]) continue;
		vis[v] = true;
		rep(i, G[v].size()) {
			int u = G[v][i];
			deg[u] --;
			int na = deg[u] + ans[v] + 1;
			if(ans[u] > na) {
				ans[u] = na; que.push(MP(ans[u], u));
			}
		}
	}
	printf("%d\n", ans[1]);
	return 0;
}