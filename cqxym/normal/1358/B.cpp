#include<stdio.h>
#include<algorithm>
#define R register int
int a[100001];
inline void Solve(){
	int n,x,ans=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	std::sort(a+1,a+n+1);
	for(R i=1;i<=n;i++){
		if(a[i]<=i){
			ans=i;
		}
	}
	printf("%d\n",ans+1);
}
int main(){
	int t,n,m;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}