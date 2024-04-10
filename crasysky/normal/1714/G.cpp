#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6;
struct edge{ int v,a,b; }; vector<edge> G[N];
int r[N],tp; ll s[N],st[N];
void dfs(int u){
	rep0(i,G[u].size()){
		int v=G[u][i].v;
		s[v]=s[u]+G[u][i].a;
		ll val=st[tp]; st[++tp]=val+G[u][i].b;
		r[v]=upper_bound(st+1,st+1+tp,s[v])-st-1;
		dfs(v);
        --tp;
	}
}
int main(){
	int T; cin>>T;
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) G[i].clear();
		rep(i,2,n){
			int f,a,b; scanf("%d%d%d",&f,&a,&b);
			G[f].push_back((edge){i,a,b});
		}
		dfs(1);
		rep(i,2,n) printf("%d ",r[i]);
		putchar('\n');
	}
	return 0;
}