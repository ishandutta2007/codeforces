#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e17;
const int N=200000,M=200000;
int n,m,n0,m0;
int l[N+1],r[N+1];
int safe[M+1];
int dp[N+1][2];
signed main(){
	cin>>n>>m>>n0>>m0;
	for(int i=1;i<=n;i++)l[i]=inf;
	while(n0--){
		int x,y;
		cin>>x>>y;
		l[x]=min(l[x],y);r[x]=max(r[x],y);
	}
	int now=0,mn=inf,mx=0;
	for(int i=1;i<=n;i++)if(r[i])l[++now]=l[i],r[now]=r[i],mn=min(mn,i),mx=max(mx,i);
	for(int i=1;i<=m0;i++)cin>>safe[i];
	sort(safe+1,safe+m0+1);
	int to=mn>1?safe[1]:1;
	dp[1][0]=abs(1-to)+abs(to-r[1])+r[1]-l[1];dp[1][1]=abs(1-to)+abs(to-l[1])+r[1]-l[1];
	for(int i=2;i<=now;i++){
		dp[i][0]=dp[i][1]=inf;
		int *fd,mnn,mxx;
		
		mnn=min(r[i],l[i-1]);mxx=max(r[i],l[i-1]);
		fd=lower_bound(safe+1,safe+m0+1,mnn);
		dp[i][0]=min(dp[i][0],dp[i-1][0]+min(fd>safe+1?mnn+mxx-2**(fd-1):inf,fd<=safe+m0?*fd-mnn+abs(*fd-mxx):inf));

		mnn=min(r[i],r[i-1]);mxx=max(r[i],r[i-1]);
		fd=lower_bound(safe+1,safe+m0+1,mnn);
		dp[i][0]=min(dp[i][0],dp[i-1][1]+min(fd>safe+1?mnn+mxx-2**(fd-1):inf,fd<=safe+m0?*fd-mnn+abs(*fd-mxx):inf));

		mnn=min(l[i],l[i-1]);mxx=max(l[i],l[i-1]);
		fd=lower_bound(safe+1,safe+m0+1,mnn);
		dp[i][1]=min(dp[i][1],dp[i-1][0]+min(fd>safe+1?mnn+mxx-2**(fd-1):inf,fd<=safe+m0?*fd-mnn+abs(*fd-mxx):inf));

		mnn=min(l[i],r[i-1]);mxx=max(l[i],r[i-1]);
		fd=lower_bound(safe+1,safe+m0+1,mnn);
		dp[i][1]=min(dp[i][1],dp[i-1][1]+min(fd>safe+1?mnn+mxx-2**(fd-1):inf,fd<=safe+m0?*fd-mnn+abs(*fd-mxx):inf));
		
		dp[i][0]+=r[i]-l[i];dp[i][1]+=r[i]-l[i];
	}
//	for(int i=1;i<=now;i++)for(int j=0;j<=1;j++)printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
	cout<<min(dp[now][0],dp[now][1])+mx-1;
	return 0;
}
/*1
3 3 3 2
1 1
2 1
3 1
2 3
*/