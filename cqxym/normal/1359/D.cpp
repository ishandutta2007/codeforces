#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define N 1000002
int a[N],stk[N];
L presum[N],sufsum[N],rtmax[N],lfmax[N],maxsum[N];
I void Max(L&x,L y){
	x=x>y?x:y;
}
I void Solve(){
	int n,ct=0;
	scanf("%d",&n);
	L tem;
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		presum[i]=presum[i-1]+a[i];
		tem=-1e18;
		while(ct!=0&&a[stk[ct]]<a[i]){
			Max(tem,maxsum[ct]);
			rtmax[stk[ct]]=tem;
			ct--;
		}
		if(ct!=0){
			Max(maxsum[ct],tem);
		}
		ct++;
		stk[ct]=i;
		maxsum[ct]=presum[i];
	}
	tem=-1e18;
	while(ct!=0){
		Max(tem,maxsum[ct]);
		rtmax[stk[ct]]=tem;
		ct--;
	}
	sufsum[n+1]=0;
	for(R i=n;i!=0;i--){
		sufsum[i]=sufsum[i+1]+a[i];
		tem=-1e18;
		while(ct!=0&&a[stk[ct]]<a[i]){
			Max(tem,maxsum[ct]);
			lfmax[stk[ct]]=tem;
			ct--;
		}
		if(ct!=0){
			Max(maxsum[ct],tem);
		}
		ct++;
		stk[ct]=i;
		maxsum[ct]=sufsum[i];
	}
	tem=-1e18;
	while(ct!=0){
		Max(tem,maxsum[ct]);
		lfmax[stk[ct]]=tem;
		ct--;
	}
	tem=0;
	for(R i=1;i<=n;i++){
		Max(tem,lfmax[i]+rtmax[i]-sufsum[i]-presum[i]);
	}
	printf("%lld\n",tem);
}
int main(){
	Solve();
	return 0;
}
/*
2
8
3 -2 5 -5 1 0 -4 1
5
1 4 5 2 3
*/