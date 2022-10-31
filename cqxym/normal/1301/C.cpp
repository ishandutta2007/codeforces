#include<stdio.h>
#define R register int
#define L long long
inline L Calc(int x){
	return (L)x*(x+1)>>1;
}
inline void Solve(){
	int n,m,q,r;
	scanf("%d%d",&n,&m);
	q=(n-m)/(m+1);
	r=(n-m)%(m+1);
	printf("%lld\n",Calc(n)-Calc(q+1)*(r)-Calc(q)*(m+1-r));
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}