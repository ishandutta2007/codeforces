#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
const long long inf=1e18;
int n,i,j;
long long r1,r2,r3,d,a[1000005],b[1000005],c[1000005];
long long f[1000005],g[1000005][2],ans=inf;
int main(){
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	rep(i,n){
		scanf("%lld",&a[i]);
		b[i]=r1*a[i]+r3;
		c[i]=min(r1*a[i]+min(r1+r1,r3),r2+r1);
	}
	f[0]=0;
	f[1]=min(b[1],c[1]+d+d);
	for(i=2;i<=n;i++){
		f[i]=f[i-1]+d+b[i];
		f[i]=min(f[i],f[i-1]+d+c[i]+d+d);
		if(i>=2){
			f[i]=min(f[i],f[i-2]+d*(4-(i==2))+c[i-1]+c[i]);
		}
		if(i>=3){
			f[i]=min(f[i],f[i-3]+d*(7-(i==3))+c[i-2]+c[i-1]+c[i]);
		}
	}
	g[n+1][0]=g[n+1][1]=0;
	g[n][0]=b[n];g[n][1]=c[n]+d+d;
	g[n-1][0]=b[n]+b[n-1]+d;g[n-1][1]=min(c[n-1]+c[n]+d*4,g[n][0]+c[n-1]+d*2);
	for(i=n-2;i>=1;i--){
		g[i][0]=min(inf,g[i+1][0]+b[i]+d);
		g[i][1]=min(g[i+1][1],g[i+1][0])+c[i]+d*3;
		if(i+2<n) g[i][1]=min(g[i][1],min(g[i+2][1],g[i+2][0])+c[i]+c[i+1]+d*4);
		if(i+3<n) g[i][1]=min(g[i][1],min(g[i+3][1],g[i+3][0])+c[i]+c[i+1]+c[i+2]+d*6);
		if(i+2<=n) g[i][1]=min(g[i][1],min(g[i+2][1],g[i+2][0])+c[i]+c[i+1]+d*6);
		if(i+3<=n) g[i][1]=min(g[i][1],min(g[i+3][1],g[i+3][0])+c[i]+c[i+1]+c[i+2]+d*8);
	}
	rep(i,n+1){
		ans=min(ans,min(g[i][0],g[i][1])+f[i-1]+(1<=i-1&&i<=n)*d);
	}
	cout<<ans<<endl;
	return 0;
}