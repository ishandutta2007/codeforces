#include<stdio.h>
#include<algorithm>
#define R register int
int a[100];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	std::sort(a,a+n);
	for(R i=n-1;i!=-1;i--){
		printf("%d ",a[i]);
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}