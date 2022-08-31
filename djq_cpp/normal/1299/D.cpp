#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, m;
vector<PII> G[100005];
vector<int> hv[100005];
bool spec[100005], del[100005];
int dis[100005], pre[100005], rt[100005], xsum[100005], exc[100005];

void bfs(int v)
{
	memset(dis, -1, sizeof(dis));
	queue<int> que;
	dis[v] = 0;
	pre[v] = -1;
	xsum[v] = 0;
	que.push(v);
	while(!que.empty()) {
		v = que.front();
		que.pop();
		rep(i, G[v].size()) {
			int u = G[v][i].first;
			if(dis[u] == -1) {
				dis[u] = dis[v] + 1;
				pre[u] = v;
				xsum[u] = xsum[v] ^ G[v][i].second;
				rt[u] = v == 1 ? u : rt[v];
				que.push(u);
			}
		}
	}
}

map<unsigned int, int> sta;
int nxt[505][32], cnt;

unsigned int add_ele(unsigned int cc, int pe)
{
	rep(i, 32) if(cc >> i & 1) cc |= 1 << (i ^ pe);
	return cc;
}

void gen_sta()
{
	memset(nxt, -1, sizeof(nxt));
	queue<unsigned int> que;
	sta[1u] = 0;
	cnt = 1;
	que.push(1u);
	while(!que.empty()) {
		unsigned int cur = que.front();
		que.pop();
		int cpos = sta[cur];
		rep(i, 32) {
			unsigned int ncur = add_ele(cur, i);
			if(ncur == cur) continue;
			if(sta.find(ncur) == sta.end()) {
				nxt[cpos][i] = sta[ncur] = cnt ++;
				que.push(ncur);
			} else nxt[cpos][i] = sta[ncur]; 
		}
	}
}

int cdp[505], ndp[505];
int to[505];

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(MP(v, w));
		G[v].push_back(MP(u, w));
	}
	bfs(1);
	rep1(i, n) rep(j, G[i].size()) {
		int nj = G[i][j].first;
		if(pre[nj] == i || pre[i] == nj) continue;
		if(dis[i] == 1 && dis[nj] == 1) continue;
		if(i < nj) hv[rt[i]].push_back(xsum[i] ^ xsum[nj] ^ G[i][j].second);
	}
	rep1(i, n) rep(j, G[i].size()) {
		int nj = G[i][j].first;
		if(pre[nj] == i || pre[i] == nj) continue;
		if(dis[i] == 1 && dis[nj] == 1 && i < nj) {
			rep(k, hv[nj].size()) hv[i].push_back(hv[nj][k]);
			hv[nj].clear();
			spec[i] = true;
			del[nj] = true;
			exc[i] = xsum[i] ^ xsum[nj] ^ G[i][j].second;
		}
	}
	
	gen_sta();
	
	cdp[0] = 1;
	rep1(i, n) if(dis[i] == 1 && !del[i]) {
		if(!spec[i]) {
			rep(j, cnt) ndp[j] = cdp[j];
			rep(j, cnt) to[j] = j;
			rep(j, hv[i].size()) rep(k, cnt) to[k] = to[k] == -1 ? -1 : nxt[to[k]][hv[i][j]];
			rep(j, cnt) if(to[j] != -1) ndp[to[j]] = (ndp[to[j]] + cdp[j]) % MOD;
			rep(j, cnt) cdp[j] = ndp[j];
		} else {
			rep(j, cnt) ndp[j] = cdp[j];
			rep(j, cnt) to[j] = j;
			rep(j, hv[i].size()) rep(k, cnt) to[k] = to[k] == -1 ? -1 : nxt[to[k]][hv[i][j]];
			rep(j, cnt) if(to[j] != -1) ndp[to[j]] = (ndp[to[j]] + 2LL * cdp[j]) % MOD;
			rep(k, cnt) to[k] = to[k] == -1 ? -1 : nxt[to[k]][exc[i]];
			rep(j, cnt) if(to[j] != -1) ndp[to[j]] = (ndp[to[j]] + cdp[j]) % MOD;
			rep(j, cnt) cdp[j] = ndp[j];
		}
	}
	
	int ans = 0;
	rep(j, cnt) ans = (ans + cdp[j]) % MOD;
	printf("%d\n", ans);
	return 0;
}