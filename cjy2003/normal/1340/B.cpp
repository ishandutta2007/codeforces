#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,r,b[2020],f[10],w[2020][10],dp[2020][2020],from[2020][2020],cnt[10];
void print(int i,int j)
{
	printf("%d",w[i][from[i][j]]);
	if(i!=n)print(i+1,j-from[i][j]);
}
int main()
{
	f[0]=0b1110111;cnt[0]=6;
	f[1]=0b0100100;cnt[1]=2;
	f[2]=0b1011101;cnt[2]=5;
	f[3]=0b1101101;cnt[3]=5;
	f[4]=0b0101110;cnt[4]=4;
	f[5]=0b1101011;cnt[5]=5;
	f[6]=0b1111011;cnt[6]=6;
	f[7]=0b0100101;cnt[7]=3;
	f[8]=0b1111111;cnt[8]=7;
	f[9]=0b1101111;cnt[9]=6;
	scanf("%d %d",&n,&r);
	for(int i=1;i<=n;++i)
	{
		int c=0;
		char x;
		for(int j=0;j<7;++j)
		{
			scanf(" %c",&x);
			if(x=='1')b[i]|=1<<j,++c;
		}
		for(int k=0;k<=7;++k)w[i][k]=0xc0c0c0c0;
		for(int k=0;k<=9;++k)if((b[i]&f[k])==b[i])w[i][cnt[k]-c]=k;
	//	for(int k=0;k<=7;++k)printf("%d ",w[i][k]);printf("\n");
	}
	dp[n+1][0]=1;
	for(int i=n;i;--i)
		for(int j=0;j<=r;++j)
		{
			int mx=-1;
			for(int k=0;k<=7&&k<=j;++k)
				if(dp[i+1][j-k]==1&&w[i][k]>mx)dp[i][j]=1,mx=w[i][k],from[i][j]=k;
		}
	if(dp[1][r]==0)return printf("-1"),0;
	print(1,r);
	return 0;
}