#include<stdio.h>
#define R register int
#define L long long
int a[250001];
L premin[250001];
inline void Min(L&x,L y){
	x=x<y?x:y;
}
int main(){
	int n,m,x;
	scanf("%d",&n);
	m=n+1>>1;
	L sum=0,presum=0;
	for(R i=1;i<=m;i++){
		scanf("%d",a+i);
		presum+=a[i];
	}
	scanf("%d",&x);
	for(R i=2;i<=m;i++){
		sum+=x-a[i-1];
		premin[i]=premin[i-1];
		Min(premin[i],sum);
	}
	premin[m+1]=premin[m];
	Min(premin[m+1],-a[m]);
	for(R i=m;i<=n;i++){
		if(presum+premin[n-i+1]>0){
			printf("%d",i);
			return 0;
		}
		presum+=x;
	}
	printf("-1");
	return 0;
}