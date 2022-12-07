#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 200100;
int tot, root, last, par[maxn * 2], go[maxn * 2][27], val[maxn * 2];
int n;
int fa[maxn * 2][20];
int ls[maxn * 40], rs[maxn * 40], rt[maxn * 2];
int rig[maxn * 2];
int f[maxn * 2];
vector<int> g[maxn * 2];
char s[maxn];
int ans;

void extend(int w){
	int p = last;
	int np = ++tot; val[np] = val[p] + 1;
	while(p && !go[p][w]) go[p][w] = np, p = par[p];
	if(!p) par[np] = root;
	else{
		int q = go[p][w];
		if(val[p] + 1 == val[q]) par[np] = q;
		else{
			int nq = ++tot; val[nq] = val[p] + 1;
			memcpy(go[nq], go[q], sizeof(go[q]));
			par[nq] = par[q];
			par[q] = nq;
			par[np] = nq;
			while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
		}
	}
	last = np;
}

int merge(int a, int b){
	if(!a || !b) return a | b;
	int t = ++tot;
	ls[t] = merge(ls[a], ls[b]);
	rs[t] = merge(rs[a], rs[b]);
	return t;
}

void insert(int &t, int l, int r, int x){
	t = ++tot;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(x <= mid) insert(ls[t], l, mid, x);
	else insert(rs[t], mid + 1, r, x);
}

void dfs(int t){
	if(rig[t]) insert(rt[t], 1, n, rig[t]);
	for(int i = 1; fa[t][i - 1]; ++i)
		fa[t][i] = fa[fa[t][i - 1]][i - 1];
	for(int v : g[t]) dfs(v), rt[t] = merge(rt[t], rt[v]);
}

int findpre(int t, int l, int r, int x){
	if(!t) return 0;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(x <= mid) return findpre(ls[t], l, mid, x);
	int res = findpre(rs[t], mid + 1, r, x);
	return res ? res : findpre(ls[t], l, mid, x);
}

void dp(int t){
	int x = findpre(rt[t], 1, n, n);
	int u = t;
	f[t] = t > 1 ? 1 : 0;
	if(x > 1){
		for(int i = 18; i >= 0; --i){
			int y = findpre(rt[fa[u][i]], 1, n, x - 1);
			if(y && y - val[fa[u][i]] < x - val[t]) u = fa[u][i]; 
		}
		u = fa[u][0];
		if(u)	f[t] = f[u] + 1;
	}
	ans = max(ans, f[t]);
	for(int v : g[t]) dp(v);
}

int main(){
	last = root = tot = 1;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i){
		extend(s[i] - 'a');
		rig[last] = i;
	}
	for(int i = 2; i <= tot; ++i)
		g[par[i]].pb(i), fa[i][0] = par[i];
	dfs(1);
	dp(1);
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}