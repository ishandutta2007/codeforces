#include<stdio.h>
#define R register int
int a[50000];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	if(a[0]+a[1]<=a[n-1]){
		printf("1 2 %d\n",n);
	}else{
		puts("-1");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}