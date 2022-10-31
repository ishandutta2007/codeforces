#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<double,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; const double pi=acos(-1.0);
int x[N],y[N],a[N],fa[N],c[N],ans[N][2],k; pr v[N];
int getfa(int u){ return fa[u]==u?u:fa[u]=getfa(fa[u]); }
void push(int u,int v){
	ans[++k][0]=u,ans[k][1]=v,swap(a[u],a[v]);
}
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) fa[i]=i;
	rep(i,1,n){
		scanf("%d%d%d",&x[i],&y[i],&a[i]);
		fa[i]=getfa(a[i]);
	}
	rep(i,1,n) ++c[getfa(i)];
	int o=0;
	rep(i,1,n) if (c[i]>1){ o=i; break; }
	if (!o){ puts("0"); return 0; }
	int m=0;
	rep(i,1,n) 
		if (i!=o) v[++m]=mp(atan2(y[i]-y[o],x[i]-x[o]),i);
	sort(v+1,v+1+m);
	v[m+1]=mp(v[1].fi+2*pi,v[1].se);
	rep(i,1,m)
		if (v[i+1].fi-v[i].fi<pi&&getfa(v[i].se)!=getfa(v[i+1].se)){
			fa[getfa(v[i].se)]=getfa(v[i+1].se);
			push(v[i].se,v[i+1].se);
		}
	while (a[o]!=o) push(o,a[o]);
	printf("%d\n",k);
	rep(i,1,k) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}
/*
1
7
2 1 1 1 1 1 0
*/