#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
long long n,m,i,j,a[1111111],sf[1111111],ans[1111111],sum;
void solve(int x){
	int i;
	rep(i,x-1){
		ans[i]=i;
	}
	ans[m+1]=n+1;
	for(i=m;i>=x;i--){
		ans[i]=ans[i+1]-a[i];
	}
	rep(i,m){
		if(i<m&&ans[i]>=ans[i+1]){
			puts("-1");
			return;
		}
		if(ans[i]+a[i]-1>n){
			puts("-1");
			return;
		}
	}
	rep(i,m){
		printf("%I64d ",ans[i]);
	}
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	rep(i,m){
		scanf("%I64d",&a[i]);
	}
	for(i=m;i>=1;i--){
		sf[i]=sf[i+1]+a[i];
	}
	if(sf[1]<n){
		puts("-1");
		return 0;
	}
	rep(i,m+1){
		if(sf[i]+(i-1)<=n){
			solve(i);
			return 0;
		}
	}
	puts("-1"); 
	return 0;
}