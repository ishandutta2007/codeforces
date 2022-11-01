#include<stdio.h>
inline void Solve(){
	int a,b,x,n;
	scanf("%d%d%d%d",&n,&x,&a,&b);
	if(a>b){
		int t=a;
		a=b;
		b=t;
	}
	b-=a-1-x;
	printf("%d\n",(n<b?n:b)-1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}