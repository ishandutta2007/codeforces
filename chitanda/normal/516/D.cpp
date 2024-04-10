#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100100;
int n;
vector<pii> g[maxn];
int cal[maxn], tag[maxn];
ll t1[maxn], t2[maxn];
int sta[maxn], top;
int root;
ll len;

void dfs(int t, int fa){
	for(auto e : g[t]){
		int v = e.fi, w = e.se;
		if(v == fa) continue;
		dfs(v, t);
		if(t1[v] + w > t1[t]) t2[t] = t1[t], t1[t] = t1[v] + w;
		else t2[t] = max(t2[t], t1[v] + w);
	}
}

void dfs2(int t, int fa){
	for(auto e : g[t]){
		int v = e.fi, w = e.se;
		if(v == fa) continue;
		ll x = t1[v] + w == t1[t] ? t2[t] + w : t1[t] + w;
		if(x > t1[v]) t2[v] = t1[v], t1[v] = x;
		else t2[v] = max(t2[v], x);
		dfs2(v, t);
	}
}

int dfs(int t, int fa, int last){
	sta[++top] = t;
	int l = last - 1, r = top;
	while(l + 1 < r){
		int d = (l + r + 1) >> 1;
		if(t1[t] - t1[sta[d]] <= len) r = d;
		else l = d;
	}
	--tag[sta[l]];
	
	int cnt = 0;
	for(auto e : g[t]){
		int v = e.fi;
		if(v == fa) continue;
		cnt += dfs(v, t, r);		
	}
	cnt += tag[t];
	--top;
	return cal[t] = ++cnt;
}

int work(){
	memset(cal, 0, sizeof(cal));
	memset(tag, 0, sizeof(tag));
	dfs(root, 0, 1);
	int res = 0;
	for(int i = 1; i <= n; ++i)
		res = max(res, cal[i]);
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		static int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(mkp(v, w));
		g[v].pb(mkp(u, w));
	}

	dfs(1, 0);
	dfs2(1, 0);
	root = 1;
	for(int i = 1; i <= n; ++i)
		if(t1[i] < t1[root]) root = i;
	
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%lld", &len);
		if(n == 2) printf("2\n");
		else printf("%d\n", work());
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}