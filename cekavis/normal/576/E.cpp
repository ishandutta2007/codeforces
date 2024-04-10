#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005, K = 52;
int n, m, k, q, u[N], v[N], x[N], y[N], now[N];
vector<int> a[N];
vector<int> s[N<<2];
struct bipartite{
	int f[N], siz[N];
	bool w[N];
	vector<int> a;
	void init(){ for(int i=1; i<=n; ++i) f[i]=i, siz[i]=1;}
	bool link(int x, int y){
		bool s=0;
		while(f[x]!=x) s^=w[x], x=f[x];
		while(f[y]!=y) s^=w[y], y=f[y];
		if(x==y) return a.push_back(0), s;
		else{
			if(siz[x]>siz[y]) swap(x, y);
			a.push_back(x), f[x]=y, w[x]=s^1, siz[y]+=siz[x];
			return 1;
		}
	}
	void undo(){
		int x=a.back();
		if(x) siz[f[x]]-=siz[x], f[x]=x;
		a.pop_back();
	}
} f[K];
void insert(int l, int r, int t, int L, int R, int x){
	if(L>R) return;
	if(L<=l && r<=R) return s[t].push_back(x);
	int mid=(l+r)>>1, k=t<<1;
	if(L<=mid) insert(l, mid, k, L, R, x);
	if(R>mid) insert(mid+1, r, k|1, L, R, x);
}
void solve(int l, int r, int t){
	for(int i:s[t]) assert(f[now[i]].link(u[i], v[i]));
	if(l==r){
		a[x[l]].pop_back();
		if(f[y[l]].link(u[x[l]], v[x[l]])) puts("YES"), now[x[l]]=y[l];
		else puts("NO");
		if(now[x[l]]) insert(1, q, 1, l+1, a[x[l]].empty()?q:a[x[l]].back()-1, x[l]);
		f[y[l]].undo();
	}
	else{
		int mid=(l+r)>>1, k=t<<1;
		solve(l, mid, k), solve(mid+1, r, k|1);
	}
	for(int i:s[t]) f[now[i]].undo();
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i=1; i<=m; ++i) scanf("%d%d", u+i, v+i);
	for(int i=1; i<=q; ++i) scanf("%d%d", x+i, y+i), a[x[i]].push_back(i);
	for(int i=1; i<=k; ++i) f[i].init();
	for(int i=1; i<=m; ++i) reverse(a[i].begin(), a[i].end());
	solve(1, q, 1);
	return 0;
}