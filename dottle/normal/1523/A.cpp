#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//#define int long long
const int N = 1e6;

inline int read()
{
	int X=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){X=(X<<1)+(X<<3)+ch-'0';ch=getchar();}
	if(flag)return X;
	return ~(X-1);
}

inline void write(int X)
{
	if(X<0){X=~(X-1);putchar('-');}
	if(X>9){write(X/10);}
	putchar(X%10+'0');
}

int n,m,T,cnt,num,ans;
int ze[N];
bool vis[N];
char a[N];
signed main()
{
	T=read();
	while(T--)
	{
		cnt=1,ans=0;
		memset(a,0,sizeof a);
		memset(ze,0,sizeof ze);
		memset(vis,0,sizeof vis);
		n=read(),m=read();
		cin>>a+1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!='1')ze[cnt]++,vis[i]=true;
			else if(a[i]=='1'&&a[i]!=a[i+1])cnt++;
			else continue;
		}
		int maxn=-1;
		if(cnt==1)
		{
			printf("%s\n",a+1);
			continue;
		}
		maxn=max(ze[1],ze[cnt]);
		for(int i=2;i<=cnt-1;i++)maxn=max(ze[i]/2,maxn);
		int tot=0;
		maxn=min(maxn,m);
		for(int i=1;i<=maxn;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j+1]==a[j-1]&&vis[j+1]==vis[j-1])continue;
				else if(a[j+1]=='1'&&!vis[j+1])a[j]='1';
				else if(a[j-1]=='1'&&!vis[j-1])a[j]='1';
			}
			for(int j=1;j<=n;j++)if(a[j]=='1')vis[j]=0;	
		}
		printf("%s\n",a+1);
	}
	return 0;
}