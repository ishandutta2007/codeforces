#include<stdio.h>
#define R register int
int ct[30];
inline void Solve(){
	int n,x;
	scanf("%d",&n);
	for(R i=0;i!=30;i++){
		ct[i]=0;
	}
	long long ans=0;
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		int t=-1;
		while(x!=0){
			x>>=1;
			t++;
		}
		ans+=ct[t];
		ct[t]++;
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