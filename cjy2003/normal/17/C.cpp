#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=51123987;
int n,dp[155][55][55][55],mx;
int nxt[155][3];
char s[155];
int ans;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	mx=(n+2)/3;
	for(int i=1;i<=n;++i)s[i]-='a';
	dp[1][0][0][0]=1;
	nxt[n+1][0]=nxt[n+1][1]=nxt[n+1][2]=n+1;
	for(int i=n;i>=1;--i)
	{
		nxt[i][0]=nxt[i+1][0],nxt[i][1]=nxt[i+1][1],nxt[i][2]=nxt[i+1][2];
		nxt[i][s[i]]=i;
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=mx;++j)
			for(int k=0;k<=mx&&k<=n-j;++k)
				for(int l=0;l<=mx&&l<=n-j-k;++l)
					if(dp[i][j][k][l])
					{
					//	printf("%d %d %d %d %d\n",i,j,k,l,dp[i][j][k][l]);
						if(j+k+l==n)
						{
							if(abs(j-k)<=1&&abs(j-l)<=1&&abs(k-l)<=1)(ans+=dp[i][j][k][l])>=mod?ans-=mod:0;	
						}
						else
						{
							(dp[nxt[i][0]][j+1][k][l]+=dp[i][j][k][l])>=mod?dp[nxt[i][0]][j+1][k][l]-=mod:0;
							(dp[nxt[i][1]][j][k+1][l]+=dp[i][j][k][l])>=mod?dp[nxt[i][1]][j][k+1][l]-=mod:0;
							(dp[nxt[i][2]][j][k][l+1]+=dp[i][j][k][l])>=mod?dp[nxt[i][2]][j][k][l+1]-=mod:0;
						//	if(i==3&&j==0&&k==2&&l==1)
						//		printf("%d %d %d %d %d\n",nxt[i][0],j+1,k,l,dp[nxt[i][0]][j+1][k][l]);
						}
					}
	printf("%d",ans);
	return 0;
}