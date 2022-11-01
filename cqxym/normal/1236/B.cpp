#include<stdio.h>
int PowMod(int a,int b){
	int s=1;
	while(b>0){
		if((b&1)>0){
			s=1ll*s*a%1000000007;
		}
		b>>=1;
		a=1ll*a*a%1000000007;
	}
	return s;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",PowMod(PowMod(2,m)-1,n));
	return 0;
}