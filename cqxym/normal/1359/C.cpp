#include<stdio.h>
#include<cmath>
#define R register int
inline void Solve(){
	int H,C,T;
	scanf("%d%d%d",&H,&C,&T);
	if(T>=H){
		puts("1");
		return;
	}
	if(T<=H+C>>1){
		puts("2");
		return;
	}
	long long l=0,r=4e18,mid,ans2;
	long double ans1=1e6;
	while(l<=r){
		mid=l+r>>1;
		long double tem=(long double)((H+C)*mid+H)/(mid<<1|1),g;
		g=fabs(tem-T);
		if(g<ans1-1e-16){
			ans1=fabs(tem-T);
			ans2=mid;
		}else if(g<ans1+1e-16&&mid<ans2){
			ans2=mid;
		}
		if(tem>T){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld\n",ans2<<1|1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}