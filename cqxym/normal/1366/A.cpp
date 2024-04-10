#include<stdio.h>
inline void Solve(){
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=(a+b)/3;
	a=a<b?a:b;
	printf("%d\n",a<c?a:c);
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}