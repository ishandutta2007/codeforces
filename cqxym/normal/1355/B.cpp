#include<stdio.h>
#include<algorithm>
#define R register int
int e[300000];
inline void Solve(){
	int n,lt=-1,mx=0,ans=0;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",e+i);
	}
	std::sort(e,e+n);
	for(R i=0;i!=n;i++){
		if(e[i]>mx){
			mx=e[i];
		}
		if(i-lt>=mx){
			ans++;
			lt=i;
			mx=0;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}