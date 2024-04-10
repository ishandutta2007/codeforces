#include<stdio.h>
#define R register int
int a[100000];
inline int Max(int a,int b){
	return a>b?a:b;
}
inline int Min(int a,int b){
	return a<b?a:b;
}
inline void Solve(){
	int n,ans=0,mx=0,mn=1e9;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=1;i!=n;i++){
		if(a[i]!=-1){
			if(a[i-1]==-1){
				mx=Max(mx,a[i]);
				mn=Min(mn,a[i]);
			}else{
				ans=Max(Max(ans,a[i]-a[i-1]),a[i-1]-a[i]);
			}
		}
	}
	for(R i=n-2;i!=-1;i--){
		if(a[i]!=-1){
			if(a[i+1]==-1){
				mx=Max(mx,a[i]);
				mn=Min(mn,a[i]);
			}
		}
	}
	printf("%d %d\n",Max(ans,mx-mn+1>>1),mn+mx>>1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}