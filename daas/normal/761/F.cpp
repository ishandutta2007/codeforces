#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,K,mem[300001][5],sum[26][1010][1010],cnt[1010][1010],map[1001][1001];
ll pre[26],ori[1001][1001],ans[26][1001][1001];
char s[1001];
int main()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		for(int j=1;j<=m;++j)
			map[i][j]=s[j-1]-'a';
	}
	for(int i=1;i<=K;++i)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		scanf("%s",s);
		int col=s[0]-'a';
		sum[col][x1][y1]++;
		sum[col][x1][y2+1]--;
		sum[col][x2+1][y1]--;
		sum[col][x2+1][y2+1]++;
		cnt[x1][y1]++;
		cnt[x1][y2+1]--;
		cnt[x2+1][y1]--;
		cnt[x2+1][y2+1]++;
		mem[i][0]=x1,mem[i][1]=y1,mem[i][2]=x2,mem[i][3]=y2;
		mem[i][4]=col;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
	for(int col=0;col<26;++col)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				sum[col][i][j]+=sum[col][i-1][j]+sum[col][i][j-1]-sum[col][i-1][j-1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			sum[map[i][j]][i][j]+=K-cnt[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int num=0;
			for(int k=1;k<26;++k)
			{
				num+=sum[k-1][i][j];
				pre[k]=pre[k-1]+num;
			}
			num=0;
			for(int k=24;k>=0;--k)
			{
				num+=sum[k+1][i][j];
				ans[k][i][j]=ans[k+1][i][j]+num;
			}
			for(int k=0;k<26;++k)
				ans[k][i][j]+=pre[k];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ori[i][j]=ori[i-1][j]+ori[i][j-1]-ori[i-1][j-1]+ans[map[i][j]][i][j];
	for(int col=0;col<26;++col)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				ans[col][i][j]+=ans[col][i-1][j]+ans[col][i][j-1]-ans[col][i-1][j-1];
	ll ANS=26ll*n*m*K;
	for(int i=1;i<=K;++i)
	{
		int x1=mem[i][0],y1=mem[i][1],x2=mem[i][2],y2=mem[i][3],col=mem[i][4];
		ANS=min(ANS,ori[n][m]-(ori[x2][y2]-ori[x1-1][y2]-ori[x2][y1-1]+ori[x1-1][y1-1])+(ans[col][x2][y2]-ans[col][x1-1][y2]-ans[col][x2][y1-1]+ans[col][x1-1][y1-1]));
	}
	printf("%I64d\n",ANS);
	return 0;
}