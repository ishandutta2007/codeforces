#include<stdio.h>
#include<algorithm>
#define R register int
#define L long long
#define N 400001
int d[N];
L h[N],sum[N],hs[N];
inline void Max(L&x,L y){
	x=x>y?x:y;
}
int main(){
	int n;
	L x;
	scanf("%d",&n);
	scanf("%lld",&x);
	for(R i=1;i<=n;i++){
		scanf("%d",d+i);
		h[i]=(L)(d[i]+1)*d[i]>>1;
		sum[i]=sum[i-1]+d[i];
		hs[i]=hs[i-1]+h[i];
	}
	for(R i=n+1;i<=n<<1;i++){
		d[i]=d[i-n];
		h[i]=(L)(d[i]+1)*d[i]>>1;
		sum[i]=sum[i-1]+d[i];
		hs[i]=hs[i-1]+h[i];
	}
	L ans=x;
	n<<=1;
	for(R i=n;i!=n>>1;i--){
		int t=std::upper_bound(sum+1,sum+n+1,sum[i]-x)-sum;
		int tem=sum[i]-sum[t-1]-x;
		Max(ans,hs[i]-hs[t-1]-(L)tem*(tem+1)/2);
	}
	printf("%lld",ans);
	return 0;
}