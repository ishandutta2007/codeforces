#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[20];
int suf[1<<15][15],sum[1<<15];
int dp[1<<15][16][15],id[15];
pair<int,int>from[1<<15][16][15];
int main()
{
	for(int i=1;i<1<<15;++i)
	{
		suf[i][14]=i>>14&1?14:15;
		for(int j=13;~j;--j)suf[i][j]=i>>j&1?j:suf[i][j+1];
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=1;i<1<<n;++i)sum[i]=sum[i^(1<<suf[i][0])]+a[suf[i][0]];
		for(int i=0;i<1<<n;++i)memset(dp[i],0x3f,sizeof(dp[i]));
		dp[0][0][0]=0;
		for(int i=0;i<1<<n;++i)
		{
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k)
				{
					if(dp[i][j][k]==0x3f3f3f3f)continue;
					int c=(1<<n)-1-i;
					for(int ad=c;;ad=(ad-1)&c)
					{
						if(dp[i][j][k]<sum[ad]&&suf[ad][k]<n&&sum[ad]<dp[i|ad][j+1][suf[ad][k]])
						{
							dp[i|ad][j+1][suf[ad][k]]=sum[ad];
							from[i|ad][j+1][suf[ad][k]]=make_pair(i,k);
						}
						if(!ad)break;
					}
				}
		}
		int cur=(1<<n)-1,ccnt=0,cpos=0;
		bool flag=1;
		for(int i=n;~i;--i)
		{
			for(int j=0;j<n;++j)
				if(dp[(1<<n)-1][i][j]!=0x3f3f3f3f)
				{
					ccnt=i,cpos=j,flag=0;
					break;
				}
			if(!flag)break;
		}
		printf("%d\n",n-ccnt);
		for(int i=0;i<n;++i)id[i]=i+1;
		while(cur)
		{
			int nxt=from[cur][ccnt][cpos].first,np=from[cur][ccnt][cpos].second;
			for(int i=0;i<n;++i)
				if((cur^nxt)>>i&1&&i!=cpos)
				{
					printf("%d %d\n",id[i],id[cpos]);
					for(int j=i+1;j<n;++j)--id[j];
				}
			cur=nxt,--ccnt,cpos=np;
		}
	}
	return 0;
}