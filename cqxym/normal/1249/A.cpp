#include<stdio.h>
#include<algorithm>
#define R register int
int a[101];
inline void Solve(){
	int n,s=0;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	for(R i=1;i<n;i++){
		if(a[i]-a[i-1]==1){
			puts("2");
			return;
		}
	}
	puts("1");
}
int main(){
	int q;
	scanf("%d",&q);
	for(R i=0;i<q;i++){
		Solve();
	}
	return 0;
}