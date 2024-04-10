#include<stdio.h>
#include<algorithm>
#define R register int
int x[100000];
inline long long Calc(int x){
	return x<3?0:(long long)(x-1)*(x-2)>>1;
}
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(R i=0;i!=n;i++){
		scanf("%d",x+i);
	}
	long long s=0;
	for(R i=0;i!=n;i++){
		int t=std::upper_bound(x+i,x+n,x[i]+d)-x;
		s+=Calc(t-i);
	}
	printf("%lld",s);
	return 0;
}