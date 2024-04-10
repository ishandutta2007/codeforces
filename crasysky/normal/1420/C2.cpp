#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6; int n,a[N];
int q(int i){
	if (i==0||i==n+1) return 0;
	if (a[i]>=a[i-1]&&a[i]>=a[i+1]) return a[i];
	if (a[i]<a[i-1]&&a[i]<a[i+1]) return -a[i];
	return 0;
}
signed main(){
	int T; scanf("%d",&T);
	while (T--){
		int m; scanf("%d%d",&n,&m);
		a[0]=a[n+1]=0; rep(i,1,n) scanf("%d",&a[i]);
		ll ans=0; rep(i,1,n) ans+=q(i);
		printf("%lld\n",ans);
		while (m--){
			int x,y; scanf("%d%d",&x,&y);
			ans-=q(x-1)+q(x)+q(x+1);
			int t=a[x]; a[x]=a[y];
			ans+=q(x-1)+q(x)+q(x+1);
			ans-=q(y-1)+q(y)+q(y+1);
			a[y]=t;
			ans+=q(y-1)+q(y)+q(y+1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}