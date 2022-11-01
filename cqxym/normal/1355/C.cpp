#include<stdio.h>
#define L long long
inline L Calc(int x){
	return (L)x*(x+1)>>1;
}
int main(){
	int A,B,C,D;
	scanf("%d%d%d%d",&A,&B,&C,&D);
	L ans=0;
	for(register int i=C;i<=D;i++){
		if(B+C>i){
			if(A+B>i){
				ans+=(L)(C-B+1)*(B-A+1);
			}else{
				int y=i-B,x=i-C;
				ans+=Calc(C-y);
				if(y<B){
					ans-=Calc(B-y-1);
				}
				if(x<A){
					ans-=Calc(A-x-1);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}