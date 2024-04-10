#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int SIG = 26;

int nxt[400005][SIG], par[400005], dep[400005], cnt;

void init()
{
	memset(nxt, -1, sizeof(nxt));
	memset(par, -1, sizeof(par));
	memset(dep, 0, sizeof(dep));
	cnt = 1;
}

int n;
char ch[200005];

int append(int cur, int dat)
{
	int ret = cnt ++;
	dep[ret] = dep[cur] + 1;
	
	for(; ; ) {
		if(nxt[cur][dat] != -1) {
			int nc = nxt[cur][dat];
			if(dep[nc] == dep[cur] + 1) par[ret] = nc;
			else {
				int nc1 = cnt ++;
				rep(i, SIG) nxt[nc1][i] = nxt[nc][i];
				dep[nc1] = dep[cur] + 1;
				par[nc1] = par[nc];
				par[nc] = nc1;
				while(nxt[cur][dat] == nc) {
					nxt[cur][dat] = nc1;
					if(cur == 0) break;
					cur = par[cur];
				}
				par[ret] = nc1;
			}
			return ret;
		}
		if(cur == 0) break;
		nxt[cur][dat] = ret;
		cur = par[cur];
	}
	nxt[cur][dat] = ret;
	par[ret] = cur;
	return ret;
}

int tn[200005];

struct tnode
{
	int dat;
	tnode* lson;
	tnode* rson;
	tnode(int cd = 0)
	{
		dat = cd;
		lson = rson = NULL;
	}
};

tnode* modify(tnode* ori, int id, int val, int cl = 0, int cr = 524287)
{
	if(cl == cr) return new tnode((ori == NULL ? 0 : ori->dat) + val);
	tnode* ndat = new tnode((ori == NULL ? 0 : ori->dat) + val);
	if(ori != NULL) {
		ndat->lson = ori->lson;
		ndat->rson = ori->rson;
	}
	int mid = cl + cr >> 1;
	if(id <= mid) ndat->lson = modify(ndat->lson, id, val, cl, mid);
	else ndat->rson = modify(ndat->rson, id, val, mid + 1, cr);
	return ndat;
}

int query(tnode* cur, int l, int r, int cl = 0, int cr = 524287)
{
	if(cur == NULL) return 0;
	if(r < cl || l > cr) return 0;
	if(l <= cl && r >= cr) return cur->dat;
	int mid = cl + cr >> 1;
	return query(cur->lson, l, r, cl, mid) + query(cur->rson, l, r, mid + 1, cr);
}

tnode* tre[200005];

vector<int> sons[400005];

int dfn[400005], edn[400005], cid[400005], tot;
int pre[400005][20];
int dp[400005];

void dfs(int v)
{
	dfn[v] = tot ++;
	rep(i, sons[v].size()) {
		int u = sons[v][i];
		dfs(u);
		cid[v] = cid[u];
	}
	edn[v] = tot - 1;
}

void gen_dp(int v)
{
	int cv = v;
	for(int i = 19; i >= 0; i --) {
		if(pre[cv][i] == -1) continue;
		int nv = pre[cv][i];
		if(query(tre[cid[v]], dfn[nv], edn[nv]) == query(tre[cid[v] - dep[v] + dep[nv]], dfn[nv], edn[nv])) cv = nv;
	}
	cv = par[cv];
	dp[v] = cv == -1 ? v != 0 : dp[cv] + 1;
	
	rep(i, sons[v].size()) {
		int u = sons[v][i];
		gen_dp(u);
	}
}

int main()
{
	init();
	
	scanf("%d%s", &n, ch);
	rep(i, n) ch[i] -= 'a';
	
	rep(i, n) tn[i] = append(i == 0 ? 0 : tn[i - 1], ch[i]);
	
	rep1(i, cnt - 1) sons[par[i]].push_back(i);
	rep(i, n) cid[tn[i]] = i;
	
	dfs(0);
	rep(i, 20) rep(j, cnt)
	pre[j][i] = i == 0 ? par[j] : (pre[j][i - 1] == -1 ? -1 : pre[pre[j][i - 1]][i - 1]);
	
	rep(i, n) tre[i + 1] = modify(tre[i], dfn[tn[i]], 1);
	
	gen_dp(0);
	
	int ans = 0;
	rep(i, cnt) ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}