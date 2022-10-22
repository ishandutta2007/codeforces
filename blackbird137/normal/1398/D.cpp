#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=205;
int A,B,C,a[N],b[N],c[N],dp[N][N][N],ans;

bool cmp(int a,int b)
{
	return a>b;
}

signed main()
{
	A=read();B=read();C=read();
	for(int i=1;i<=A;++i)
		a[i]=read();
	for(int i=1;i<=B;++i)
		b[i]=read();
	for(int i=1;i<=C;++i)
		c[i]=read();
	sort(a+1,a+1+A,cmp);
	sort(b+1,b+1+B,cmp);
	sort(c+1,c+1+C,cmp);
	for(int i=0;i<=A;++i)
		for(int j=0;j<=B;++j)
			for(int k=0;k<=C;++k)
			{
				dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+a[i+1]*b[j+1]);
				dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+b[j+1]*c[k+1]);
				dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+a[i+1]*c[k+1]);
				ans=max(ans,dp[i][j][k]);
			}
	printf("%d\n",ans);
	return 0;
}