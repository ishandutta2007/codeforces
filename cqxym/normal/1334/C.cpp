#include<stdio.h>
#define R register int
#define L long long
L a[300000],b[300000];
inline void Solve(){
	int n,l;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%lld%lld",a+i,b+i);
	}
	L ans=0,mn=1e18;
	for(R i=0;i!=n;i++){
		l=i!=0?i-1:n-1;
		if(a[i]>b[l]){
			ans+=a[i]-b[l];
			a[i]=b[l];
		}
		if(a[i]<mn){
			mn=a[i];
		}
	}
	printf("%lld\n",ans+mn);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}