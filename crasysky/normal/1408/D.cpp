#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e3+3,V=1e6,S=4e6+6; 
int a[N],b[N],c[N],d[N],x[S],y[S],cx[S],cy[S],rk[S],p[S],x2[S],y2[S];
signed main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
	rep(i,1,m) scanf("%d%d",&c[i],&d[i]);
	int k=0;
	rep(i,1,n)
		rep(j,1,m)
			if (a[i]<=c[j]&&b[i]<=d[j])
				x[++k]=c[j]-a[i],y[k]=d[j]-b[i];
	if (k==0){ puts("0"); return 0; }
	rep(i,1,k) ++cy[y[i]]; rep(i,1,V) cy[i]+=cy[i-1];
	rep(i,1,k) rk[cy[y[i]]--]=i;
	rep(i,1,k) ++cx[x[i]]; rep(i,1,V) cx[i]+=cx[i-1];
	per(i,k,1) p[cx[x[rk[i]]]--]=rk[i];
	int mx=-1,k2=0;
	per(i,k,1){
		int j=p[i];
		if (y[j]>mx) x2[++k2]=x[j],y2[k2]=mx=y[j];
	}
	int ans=min(y2[k2]+1,x2[1]+1);
	rep(i,2,k2) ans=min(ans,y2[i-1]+x2[i]+2); 
	printf("%d\n",ans);
	return 0;
}