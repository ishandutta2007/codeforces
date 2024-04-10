#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
int a[N],n;
int solve(int a1){
	int x=lower_bound(a+1,a+n+1,a1)-a,cnt=0;
	while(x!=n+1){
		++cnt;
		int y=lower_bound(a+x+1,a+n+1,2*a[x]-a1)-a;
		x=y;
	}
	return cnt;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		int ans=0;
		for(int x=1;x<=n;++x)
			if(x==1||a[x]>a[x-1]) ans=max(ans,solve(a[x]));
		printf("%d\n",n-ans);
	}	
	return 0;
}