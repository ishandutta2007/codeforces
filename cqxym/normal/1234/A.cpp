#include<stdio.h>
#define R register int
void Solve(){
	int n,s=0,x;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d",&x);
		s+=x;
	}
	printf("%d\n",(n+s-1)/n);
}
int main(){
	int q;
	scanf("%d",&q);
	for(R i=0;i<q;i++){
		Solve();
	}
	return 0;
}