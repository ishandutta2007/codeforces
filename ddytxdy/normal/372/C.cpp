#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=300050,M=310;
int n,m,d,q[N],l,r,nn;LL dp[2][N],ans=-1e18;
struct node{
	int a,b,t;
}a[M];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].t);
	memset(dp,0xcf,sizeof(dp));
	for(int i=1;i<=n;i++)dp[0][i]=0;
	for(int i=1;i<=m;i++){
		int k=min(1ll*(a[i].t-a[i-1].t)*d,1ll*n),now=0,l=1,r=0;
		nn^=1;
		memset(dp[nn],0xcf,sizeof(dp[nn]));
		for(int j=1;j<=n;j++){
			while(now<j+k){now++;
				while(l<=r&&dp[nn^1][q[r]]<dp[nn^1][now])r--;
				q[++r]=now;
			}
			if(l<=r&&q[l]<j-k)l++;
			if(l<=r)dp[nn][j]=dp[nn^1][q[l]]+a[i].b-abs(a[i].a-j);
		}
	}
	for(int i=1;i<=n;i++)ans=max(ans,dp[nn][i]);
	cout<<ans;
	return 0;
}