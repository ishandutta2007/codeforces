#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (!flg) return x; return -x;
}

int n;
bool dp[1010][3010];
bool vis[10010]; int prm[10010];
int rec[1010],id[1010];
bool cmp(int x,int y)
{
	return rec[x]<rec[y];
}
int main()
{
	
	for (int i=2;i<=10000;i++)
	{
		if (!vis[i]) prm[++*prm]=i;
		for (int j=1;j<=(*prm)&&i*prm[j]<=10000;j++)
		{
			vis[i*prm[j]]=true;
			if (i%prm[j]==0) break;
		}
	}
	
	n=read();
	dp[0][0]=true;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=3000;j++)
		{
			if (j>=2) dp[i][j]=dp[i-1][j-2];
			if (j>=3) dp[i][j]|=dp[i-1][j-3];
		}
	}
	int pos;
	for (int j=4;j<=3000;j+=2)
		if (dp[n][j]&&!vis[j/2])
		{
			pos=j; break;
		}
	printf("%d\n",pos/2);
	for (int i=n;i;i--)
	{
		if (pos>=2&&dp[i-1][pos-2]) rec[++*rec]=2,pos-=2;
		else if (pos>=3&&dp[i-1][pos-3]) rec[++*rec]=3,pos-=3;
		id[i]=i;
//		else puts("Err");
	}
//	for (int i=1;i<=n;i++) printf("%d ",rec[i]); puts("");
	for (int i=1;i<=n;i++)
	{
		sort(id+1,id+n+1,cmp);
		for (int j=n-1;rec[id[n]]&&j;j--)
			if (rec[id[j]])
			{
				rec[id[n]]--; rec[id[j]]--;
				printf("%d %d\n",id[n],id[j]);
			}
	}
	return 0;
}