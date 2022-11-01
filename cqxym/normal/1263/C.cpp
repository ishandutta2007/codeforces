#include<stdio.h>
#define R register int
int ans[1000000];
inline Solve(){
	int n,x,s=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i=x+1){
		x=n/(n/i);
		ans[s]=x;
		s++;
	}
	printf("%d\n0",s+1);
	for(R i=0;i<s;i++){
		printf(" %d",ans[i]);
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}