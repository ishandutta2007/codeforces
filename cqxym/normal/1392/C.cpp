#include<stdio.h>
#define R register int
inline void Solve(){
	int n,x,h=0,y;
	scanf("%d",&n);
	long long ans=0;
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		if(h>x){
			ans+=h-x;
		}
		h=x;
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