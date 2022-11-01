#include<stdio.h>
#define R register int
inline void Solve(){
	int n,m,l,r,ansl,ansr;
	scanf("%d%d%d",&n,&ansr,&m);
	ansl=ansr;
	for(R i=0;i!=m;i++){
		scanf("%d%d",&l,&r);
		if(ansl<=l&&l<=ansr||l<=ansl&&ansl<=r){
			ansl=ansl<l?ansl:l;
			ansr=ansr>r?ansr:r;
		}
	}
	printf("%d\n",ansr-ansl+1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}