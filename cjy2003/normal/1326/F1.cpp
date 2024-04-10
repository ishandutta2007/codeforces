#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char mp[20][20];
int C[20][20];
long long *dp[14][1<<14];
int n,cnt[1<<14],id[1<<14],idnum[15],s[15][1<<14];
int main()
{
	for(int i=0;i<20;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%s",mp[i]);
	for(int i=1;i<1<<n;++i)
	{
		cnt[i]=cnt[i>>1]+(i&1);
		for(int j=0;j<n;++j)dp[j][i]=new long long[1<<cnt[i]-1],memset(dp[j][i],0,4<<cnt[i]);
	}
	for(int i=0;i<n;++i)dp[i][1<<i][0]=1;
//	printf("\n");
	for(int i=1;i<1<<n;++i)
		for(int p=0;p<n;++p)
			for(int j=0;j<1<<cnt[i]-1;++j)
				if(dp[p][i][j])
					for(int l=0;l<n;++l)
						if(!(i>>l&1))
						{
							int c=mp[l][p]=='1';
							dp[l][i|(1<<l)][j<<1|c]+=dp[p][i][j];
						}
//	printf("!!!\n");
	for(int i=0;i<1<<(n-1);++i)
	{
		long long res=0;
		for(int j=0;j<n;++j)res+=dp[j][(1<<n)-1][i];
		printf("%lld ",res);
	}
	return 0;
}