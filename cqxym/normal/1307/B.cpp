#include<stdio.h>
#define R register int
inline void Solve(){
	int n,x,d,ans=2e9;
	scanf("%d%d",&n,&d);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		if(x==d){
			ans=1;
		}else if(x>d){
			if(ans>2){
				ans=2;
			}
		}else{
			if(ans>(d+x-1)/x){
				ans=(d+x-1)/x;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}