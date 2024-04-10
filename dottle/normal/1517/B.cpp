#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
const int N = 200005;

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
int n,m,line[200][200],A[N],B[N],tot,vis[N],per[N];
int sum;
bool cmp1(int a,int b)
{
	return a<b;
}

struct dege{
	int val;
	int u;int v; 
	bool operator <(const dege &t) const
	{
		return val<t.val;
	}
}temp[N];

signed main()
{
	int T=read();
	while(T--)
	{
		memset(line,0,sizeof line);
		tot=0;sum=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				temp[++tot].u=i;temp[tot].val=read();
			}
		}
		sort(temp+1,temp+n*m+1);
//		for(int i=1;i<=m;i++)sum+=temp[i].val;
		for(int i=1;i<=m;i++)
		{
			line[temp[i].u][i]=temp[i].val;
		}
		for(int i=m+1;i<=n*m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(!line[temp[i].u][j])
				{
					line[temp[i].u][j]=temp[i].val;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)//1 2 3 3 4 5
		{
			for(int j=1;j<=m;j++)
			{
				printf("%lld ",line[i][j]);
			}
			puts("");
		}
	}
	return 0;
}