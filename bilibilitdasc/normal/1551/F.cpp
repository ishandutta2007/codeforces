#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define perk(i,a,b) for(int i=(a);i>=(b);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,k,u,v;
vector<int> con[105];
int dp[105][105];
int cnt[105][105];
int par[105];
int res,mx;
int dfs(int i,int p=-1)
{
	par[i]=p;
	int ret=-1;
	for(int j=0,l=con[i].size();j<l;++j)
	if(con[i][j]!=p)
	ret=max(ret,dfs(con[i][j],i));
	return ++ret;
}
int cnts(int i,int d)
{
	if(cnt[i][d]!=-1) return cnt[i][d];
	if(d==0) return cnt[i][d]=1;
	int ret=0;
	for(int j=0,l=con[i].size();j<l;++j)
	if(con[i][j]!=par[i])
	ret+=cnts(con[i][j],d-1);
	return cnt[i][d]=ret;
}
void Q()
{
	cin>>n>>k;
	res=0;
	rep1(i,n) con[i].clear();
	for(int i=1;i<n;++i)
	{
		cin>>u>>v;
		con[u].pb(v);
		con[v].pb(u);
	}
	if(k==2)
	{
		cout<<1ll*(n-1)*n/2%mod2<<endl;
		return ;
	}
	for(int r=1;r<=n;++r)
	{
		memset(cnt,-1,sizeof(cnt));
		mx=dfs(r);
		for(int d=1;d<=mx;++d)
		{
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			for(int i=0,l=con[r].size();i<=l;++i)
			for(int j=0;j<=i&&j<=k;++j)
			{
				//if(r==2) 
				//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
				dp[i+1][j]+=dp[i][j];if(dp[i+1][j]>=mod2) dp[i+1][j]-=mod2;
				if(i!=l)
				{
					dp[i+1][j+1]+=1ll*dp[i][j]*cnts(con[r][i],d-1)%mod2;if(dp[i+1][j+1]>=mod2) dp[i+1][j+1]-=mod2;
				}
			}
			res+=dp[con[r].size()][k];
			//printf("dp[%d]=%d\n",r,dp[con[r].size()][k]);
			if(res>=mod2) res-=mod2;
		}
	}
	cout<<res<<endl;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	Q();
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/