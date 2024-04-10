#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int k, n, s[300005];
vector<int> hv[300005];
int par[300005], dat[300005], cnt[300005][2], ans;

int root(int x)
{
	if(x == par[x]) return x;
	int cp = par[x];
	par[x] = root(cp);
	dat[x] ^= dat[cp];
	return par[x];
}

void unite(int u, int v, int w)
{
	root(u);
	root(v);
	w ^= dat[u] ^ dat[v];
	u = par[u]; v = par[v];
	if(u == v) return;
	if(u == 0) swap(u, v);
	ans -= min(u == 0 ? INF : cnt[u][0], cnt[u][1]);
	ans -= min(v == 0 ? INF : cnt[v][0], cnt[v][1]);
	par[u] = v;
	dat[u] = w;
	cnt[v][0] += cnt[u][w];
	cnt[v][1] += cnt[u][w ^ 1];
	ans += min(v == 0 ? INF : cnt[v][0], cnt[v][1]);
}

int main()
{
	scanf("%d%d", &n, &k);
	rep(i, n + 1) scanf("%c", &s[i]);
	rep1(i, n) s[i] -= '0';
	rep1(i, k) {
		int c, x;
		scanf("%d", &c);
		rep(j, c) {
			scanf("%d", &x);
			hv[x].push_back(i);
		}
	}
	rep1(i, n) while(hv[i].size() < 2) hv[i].push_back(0);
	
	rep(i, k + 1) {
		par[i] = i;
		cnt[i][0] = 1;
	}
	
	rep1(i, n) {
		unite(hv[i][0], hv[i][1], s[i] ^ 1);
		printf("%d\n", ans);
	}
	return 0;
}