#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
typedef pair<long long ,long long> PLL;
long long a[20],p[20];
long long l,r,k;
PLL dp[20][1<<10];
bool vis[20][1<<10];
PLL dfs(int pos,int state,bool limit,bool lead)
{
	if(pos==-1)
		return make_pair(1,0);
	if(vis[pos][state]&&!limit&&!lead) return dp[pos][state];
	PLL ret={0,0};
	int up=limit?a[pos]:9;
	for(int i=0;i<=up;i++)
	{
		int nst;
		if(i==0&&lead) nst=0;
		else nst=state|(1<<i);
		if(__builtin_popcount(nst)>k) continue;
		PLL temp=dfs(pos-1,nst,limit&&i==up,lead&&i==0);
		ret.first=(ret.first+temp.first)%mod;
		ret.second=(ret.second+temp.second+i*1LL*p[pos]%mod*temp.first%mod)%mod;
	}
	if(!vis[pos][state]&&!limit&&!lead) vis[pos][state]=1,dp[pos][state]=ret;
//	cout<<ret.first<<" "<<ret.second<<endl;
	return ret;
}
long long solve(long long n)
{
	int pos=0;
	do{
		a[pos++]=n%10;
	}while(n/=10);
	PLL ret=dfs(pos-1,0,1,1);
	return ret.second;
	
}
int main()
{
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	p[0]=1;
	for(int i=1;i<20;i++)
	{
		p[i]=p[i-1]*10%mod;
	}	
	cin>>l>>r>>k;
	printf("%lld\n",(solve(r)-solve(l-1)+mod)%mod);
}