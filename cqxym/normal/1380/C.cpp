#include<stdio.h>
#include<algorithm>
#define R register int
int a[100000];
inline void Solve(){
	int n,x;
	scanf("%d%d",&n,&x);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	std::sort(a,a+n);
	int r=n-1,ans=0;
	for(R i=r;i!=-1;i--){
		int tem=(x-1)/a[i];
		if(i+tem==r){
			ans++;
			r=i-1;
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