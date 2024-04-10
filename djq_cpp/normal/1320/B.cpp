#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, k, p[200005];
vector<int> G[200005], rG[200005];

int dis[200005];
void bfs()
{
	memset(dis, -1, sizeof(dis));
	queue<int> que;
	dis[p[k - 1]] = 0;
	que.push(p[k - 1]);
	while(!que.empty()) {
		int v = que.front();
		que.pop();
		rep(i, rG[v].size()) {
			int u = rG[v][i];
			if(dis[u] != -1) continue;
			dis[u] = dis[v] + 1;
			que.push(u);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		rG[v].push_back(u);
	}
	scanf("%d", &k);
	rep(i, k) scanf("%d", &p[i]);
	
	bfs();
	int a0 = k - 1, a1 = k - 1;
	rep(i, k - 1) {
		a0 -= dis[p[i]] == dis[p[i + 1]] + 1;
		a1 --;
		rep(j, G[p[i]].size()) {
			int np = G[p[i]][j];
			if(dis[p[i]] == dis[np] + 1 && np != p[i + 1]) {
				a1 ++;
				break;
			}
		}
	}
	printf("%d %d\n", a0, a1);
	return 0;
}