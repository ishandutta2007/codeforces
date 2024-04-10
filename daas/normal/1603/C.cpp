#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int SQRN=400;
const int MAXN=1e5+10;
const int mod=998244353;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int Test,n,a[MAXN],id[MAXN],dp[2][SQRN*2];
vector<int> mem[2];
int main()
{
	Test=read();
	while(Test--)
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		int ans=0,val=0,bj=0;
		mem[0].clear();
		mem[1].clear();
		memset(dp,0,sizeof(dp));
		mem[bj^1].push_back(a[n]);
		dp[bj^1][0]=1;
		for(int i=n-1;i>=1;--i,bj^=1)
		{
			mem[bj].clear();
			memset(dp[bj],0,sizeof(dp[bj]));
			for(int l=1,r;l<=a[i];l=r+1)
			{
				r=a[i]/(a[i]/l);
				mem[bj].push_back(a[i]/l);
				id[a[i]/l]=mem[bj].size()-1;
			}
			dp[bj][0]=1;
			for(int j=0;j<mem[bj^1].size();++j)
			{
				int minn=mem[bj^1][j];
				int num=a[i]/minn+(a[i]%minn!=0);
				val=MOD(val+(ll)dp[bj^1][j]*(num-1)%mod-mod);
				dp[bj][id[a[i]/num]]=MOD(dp[bj][id[a[i]/num]]+dp[bj^1][j]-mod);
			}
			ans=MOD(ans+val-mod);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!