#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int t,n,m,i,ans[200005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,n+m+1)ans[i-1]=0;
		for(i=0;i<=n;i++){
			if(i>(n+m+1)/2) continue;
			if(n-i>(n+m)/2) continue;
			if(((n+m+1)/2-i)>m) continue;
			ans[i+(m-((n+m+1)/2-i))]=1;
		}
		for(i=0;i<=n;i++){
			if(i>(n+m)/2) continue;
			if(n-i>(n+m+1)/2) continue;
			if(((n+m)/2-i)>m) continue;
			ans[i+(m-((n+m)/2-i))]=1;
		}
		vector<int> res;
		for(i=0;i<=n+m;i++){
			if(ans[i])res.push_back(i);
		}
		printf("%d\n",res.size());
		for(i=0;i<res.size();i++){
			printf("%d",res[i]);
			if(i+1==res.size())puts("");else putchar(' ');
		}
	}
	return 0;
}