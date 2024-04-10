#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, m;
vector<PII> G[1000005];
int mlen[1000005];
vector<int> hv[1000005];

int pre[1000005];
int conc[1000005];
int dp[1000005];

bool vis[1000005];
void bfs(int stp)
{
	rep1(i, n) mlen[i] = MOD;
	
	queue<int> que;
	vis[stp] = true;
	que.push(stp);
	mlen[stp] = 0;
	
	while(!que.empty()) {
		int v = que.front();
		que.pop();
		rep(i, G[v].size()) {
			int u = G[v][i].first;
			if(vis[u]) continue;
			vis[u] = true;
			que.push(u);
			mlen[u] = mlen[v] + 1;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	int pn = n;
	rep1(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		int cur = i, cv = v;
		while(cur > 0) {
			int nv = cur < 10 ? u : ++ n;
			G[nv].push_back(MP(cv, cur % 10));
			cv = nv;
			cur /= 10;
		}
		cur = i; cv = u;
		while(cur > 0) {
			int nv = cur < 10 ? v : ++ n;
			G[nv].push_back(MP(cv, cur % 10));
			cv = nv;
			cur /= 10;
		}
	}
	
	bfs(1);
	rep1(i, n) hv[mlen[i]].push_back(i);
	
	rep1(i, n) conc[i] = MOD;
	conc[1] = 0;
	
	rep(i, n) {
		vector<int> cch;
		rep(j, hv[i].size()) {
			int v = hv[i][j];
			cch.push_back(conc[v]);
		}
		sort(cch.begin(), cch.end());
		cch.resize(unique(cch.begin(), cch.end()) - cch.begin());
		rep(j, hv[i].size()) {
			int v = hv[i][j];
			conc[v] = lower_bound(cch.begin(), cch.end(), conc[v]) - cch.begin();
		}
		
		rep(j, hv[i].size()) {
			int v = hv[i][j];
			rep(k, G[v].size()) {
				int u = G[v][k].first;
				if(mlen[u] > mlen[v]) {
					conc[u] = min(conc[u], conc[v] * 10 + G[v][k].second);
					if(conc[u] == conc[v] * 10 + G[v][k].second) {
						pre[u] = v;
						dp[u] = (10LL * dp[v] + G[v][k].second) % MOD;
					}
				}
			}
		}
	}
	
	rep1(i, pn) if(i > 1) printf("%d\n", dp[i]);
	return 0;
}