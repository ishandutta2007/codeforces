#include<stdio.h>
inline void Solve(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%lld\n",(long long)(c-a)*(d-b)+1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}