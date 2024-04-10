#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

int n, m, k;
set<pii> forbidden[3001];
int dis[3001][3001];
pii par[3001][3001] = {{}};
bool inq[3001][3001] = {{}};
queue<pii> q;
vector<int> g[3001];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0, a, b; i < m; ++i) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0, a, b, c; i < k; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		forbidden[a].insert({b, c});
	}
	memset(dis, 0x7f, sizeof dis);
	dis[1][0] = 0;
	q.push(pii(1, 0));
	while(q.size()) {
		pii t = q.front(); q.pop();
		int cur = t.F, lst = t.S; inq[cur][lst] = false;
		for(int y : g[cur]) if(!forbidden[lst].count({cur, y})) {
			int td = dis[cur][lst] + 1;
			if(td < dis[y][cur]) {
				par[y][cur] = t;
				dis[y][cur] = td;
				if(!inq[y][cur]) {
					inq[y][cur] = true;
					q.push(pii(y, cur));
				}
			}
		}
	}
	int *mm = min_element(dis[n], dis[n] + n + 1);
	if(*mm == dis[0][0]) {
		puts("-1");
		return 0;
	}
	printf("%d\n", *mm);
	vector<int> ans;
	pii cur = pii(n, mm - dis[n]);
	while(cur.F != 1) {
		ans.push_back(cur.F);
		cur = par[cur.F][cur.S];
	}
	ans.push_back(cur.F);
	for(int i = (int)ans.size() - 1; i >= 0; --i)
		printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
	return 0;
}