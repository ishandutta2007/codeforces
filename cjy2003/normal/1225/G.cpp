#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
int n,k,a[20],sum,b[20];
vector<int>a1,b1,a2,b2;
bitset<2001>dp[1<<16];
void dfs(int mask,int w,int cnt)
{
	if(!mask)return;
	do
	{
		for(int i=mask;i;i-=(i&-i))
		{
			int x=__builtin_ctz(i&-i);
			if(w<a[x])continue;
			if(dp[mask-(1<<x)][w-a[x]])
			{
				b[x]=cnt;
				return dfs(mask-(1<<x),w-a[x],cnt);
			}
		}
		w*=k;++cnt;
	}while(1);
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i)scanf("%d",&a[i]),sum+=a[i];
	dp[0].set(0);
	for(int i=1;i<1<<n;++i)
	{
		for(int j=i;j;j-=(j&-j))
		{
			int x=__builtin_ctz(j&-j);
			dp[i]|=dp[i-(1<<x)]<<a[x];
		}
		for(int j=sum/k;j;--j)if(dp[i][j*k])dp[i][j]=1;
	}
	if(!dp[(1<<n)-1][1])return printf("NO"),0;
	printf("YES\n");
	dfs((1<<n)-1,1,0);
	for(int i=0;i<n;++i)a1.emplace_back(a[i]),b1.emplace_back(b[i]);
	while((int)a1.size()>1)
	{
		a2.clear(),b2.clear();
		int mx=0;
		for(int i=0;i<(int)b1.size();++i)mx=max(mx,b1[i]);
		int s=0;
		for(int i=0;i<(int)a1.size();++i)
			if(b1[i]!=mx)a2.emplace_back(a1[i]),b2.emplace_back(b1[i]);
			else
			{
				if(s)printf("%d %d\n",s,a1[i]);
				s+=a1[i];
			}
		while(s%k==0)s/=k,--mx;
		a2.emplace_back(s),b2.emplace_back(mx);
		a1=a2,b1=b2;
	}
	return 0;
}