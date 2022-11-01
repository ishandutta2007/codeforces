#include<stdio.h>
#define R register int
#define L long long
inline void Solve(){
	L a1,k;
	scanf("%lld%lld",&a1,&k);
	int mn,mx;
	for(R i=1;i!=k;i++){
		L t=a1;
		mx=0;
		mn=9;
		while(t!=0){
			int tem=t%10;
			if(tem>mx){
				mx=tem;
			}
			if(tem<mn){
				mn=tem;
			}
			t/=10;
		}
		if(mn==0){
			printf("%lld\n",a1);
			return;
		}
		a1+=mn*mx;
	}
	printf("%lld\n",a1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}