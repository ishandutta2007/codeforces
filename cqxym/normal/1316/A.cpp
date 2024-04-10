#include<stdio.h>
#define R register int
inline void Solve(){
	int n,m,x,s=0;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		s+=x;
	}
	printf("%d\n",m>s?s:m);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}