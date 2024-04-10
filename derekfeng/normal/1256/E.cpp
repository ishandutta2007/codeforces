#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,ans[200005];
int dp[200005],fr[200005],cnt;
pii a[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a[i]={x,i};
	}
	sort(a+1,a+n+1);
	pii s={1e9+1,-1};
	dp[1]=dp[2]=1e9;
	for(int i=3;i<=n;i++){
		s=min(s,{dp[i-3]-a[i-2].fi,i-3});
		dp[i]=s.fi+a[i].fi,fr[i]=s.se;
	}
	for(int i=n;i;i=fr[i]){
		++cnt;
		for(int j=fr[i]+1;j<=i;j++)ans[a[j].se]=cnt;
	}
	printf("%d %d\n",dp[n],cnt);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}