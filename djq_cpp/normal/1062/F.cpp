#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, m;
vector<int> G[300005], rG[300005];
int ere[300005];
int tsq[300005], cnt;

int idg[300005];
void topo_s()
{
	rep1(i, n) idg[i] = 0;
	rep1(i, n) rep(j, G[i].size()) idg[G[i][j]] ++;
	
	queue<int> que;
	rep1(i, n) if(idg[i] == 0) que.push(i);
	while(!que.empty()) {
		int v = que.front();
		que.pop();
		tsq[cnt ++] = v;
		rep(i, G[v].size()) {
			int u = G[v][i];
			idg[u] --;
			if(idg[u] == 0) que.push(u);
		}
	}
}

int odeg[300005];
int idc[300005], itot[300005];
void solve(int ts[], vector<int> crG[])
{
	rep1(i, n) odeg[i] = 0;
	queue<int> que;
	
	cnt = 0;
	int x = 0;
	rep(i, n) {
		int v = ts[i];
		rep(j, crG[v].size()) {
			int u = crG[v][j];
			if(odeg[u] == 0) {
				cnt --;
				x ^= u;
				idc[u] = v;
				itot[v] ++;
			} else if(odeg[u] == 1) {
				itot[idc[u]] --;
				idc[u] = -1;
			}
			odeg[u] ++;
		}
		
		if(cnt == 1 && itot[x] == 0) ere[v] ++;
		else if(cnt != 0) ere[v] += 2;
		cnt ++;
		x ^= v;
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
	topo_s();
	solve(tsq, rG);
	reverse(tsq, tsq + n);
	solve(tsq, G);
	int ans = 0;
	rep1(i, n) if(ere[i] <= 1) ans ++;
	printf("%d\n", ans);
	return 0;
}