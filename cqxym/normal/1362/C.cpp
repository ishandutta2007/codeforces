#include<stdio.h>
#define R register int
#define L long long
inline void Solve(){
	L n,ans=0;
	scanf("%lld",&n);
	for(R i=1;i!=61;i++){
		L t=n>>i-1;
		ans+=(t+1>>1)*i;
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}