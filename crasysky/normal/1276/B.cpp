#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; 
int n,m,e[N][2],tg[N],fa[N],s[2][N];
int getfa(int u){ return fa[u]==u?u:fa[u]=getfa(fa[u]); }
ll calc(int x){
	rep(i,1,n) fa[i]=i;
	rep(i,1,m){
		int u=e[i][0],v=e[i][1];
		if (u!=x&&v!=x) u=getfa(u),v=getfa(v),fa[u]=v;
	}
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int a,b; scanf("%d%d%d%d",&n,&m,&a,&b);
		rep(i,1,m) scanf("%d%d",&e[i][0],&e[i][1]);
		calc(a);
		int tot[2]; tot[0]=tot[1]=0;
		rep(i,1,n) 
			if (i!=a&&i!=b) ++tot[tg[i]=getfa(i)==getfa(b)];
		calc(b);
		rep(i,1,n) s[0][i]=s[1][i]=0;
		rep(i,1,n)
			if (i!=a&&i!=b) ++s[tg[i]][getfa(i)];
		ll ans=0;
		rep(i,1,n) ans+=(ll)s[0][i]*(tot[1]-s[1][i]);
		printf("%lld\n",ans);
	}
	return 0;
}