#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
const int N = 500005;
int n, cnt, last, pl, pr, idfn, ans, f[N], g[N], dfn[N<<1], rdfn[N<<1], fa[N<<1], len[N<<1], w[N<<3], ch[N<<1][26];
bool vis[N<<1];
char s[N];
vector<int> e[N<<1];
inline void extend(int c){
	int p=last, np=++cnt;
	last=cnt, len[np]=len[p]+1;
	while(p && !ch[p][c]) ch[p][c]=np, p=fa[p];
	if(!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if(len[q]==len[p]+1) fa[np]=q;
		else{
			int nq=++cnt;
			len[nq]=len[p]+1, memcpy(ch[nq], ch[q], 26<<2);
			fa[nq]=fa[q], fa[q]=fa[np]=nq;
			while(ch[p][c]==q) ch[p][c]=nq, p=fa[p];
		}
	}
}
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return (void)(w[t]=max(w[t], x));
	int mid=l+r>>1, k=t<<1;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
}
int query(int l, int r, int t, int x){
	// printf("query:%d %d %d %d %d\n", l, r, t, L, R);
	if(l==r) return w[t];
	int mid=l+r>>1, k=t<<1;
	return max(w[t], x<=mid?query(l, mid, k, x):query(mid+1, r, k|1, x));
}
inline bool check(int x){
	// printf("check:%d %d\n", dfn[pr], pr);
	return query(1, cnt, 1, dfn[pl])>=x-1 || query(1, cnt, 1, dfn[pr])>=x-1;
}
inline void dfs(int x){
	dfn[x]=++idfn;
	for(int i:e[x]) dfs(i);
	rdfn[x]=idfn;
}
inline void solve(int x){
	if(vis[x] || x<=1) return;
	vis[x]=1;
	change(1, cnt, 1, dfn[x], rdfn[x], len[x]);
	solve(fa[x]);
}
int main() {
	scanf("%d%s", &n, s+1);
	last=cnt=1;
	for(int i=n; i; --i) extend(s[i]-'a');
	for(int i=2; i<=cnt; ++i) e[fa[i]].push_back(i);
	dfs(1);
	g[n+1]=pl=pr=1;
	for(int i=n; i; --i){
		pr=pl, pl=ch[pl][s[i]-'a'];

		f[i]=f[i+1]+1;
		while(!check(f[i])){
			--f[i];
			change(1, cnt, 1, dfn[g[i+f[i]]], rdfn[g[i+f[i]]], f[i+f[i]]);
			solve(fa[g[i+f[i]]]);
			// printf("change:%d %d %d %d\n", i+f[i], dfn[g[i+f[i]]], rdfn[g[i+f[i]]], g[i+f[i]]);
		}
		ans=max(ans, f[i]);
		g[i]=ch[g[i+1]][s[i]-'a'];
		while(len[fa[g[i]]]>=f[i]) g[i]=fa[g[i]];
		// printf(">>%d\n", f[i]);
	}
	return printf("%d", ans), 0;
}