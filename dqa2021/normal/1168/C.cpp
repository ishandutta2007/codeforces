#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
//const int INF=0x7fffffff;

int n,q,w[300010];
int f[300010][19],g[19];
int main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=0;i<19;i++) f[n][i]=g[i]=(((w[n]>>i)&1)?n:n+1);
	for (int i=n-1;i;i--)
	{
		for (int j=0;j<19;j++)
		{
			if ((w[i]>>j)&1){f[i][j]=i;continue;}
			f[i][j]=n+1;
			for (int u=0;u<19;u++) if (((w[i]>>u)&1)&&g[u]<=n) f[i][j]=min(f[i][j],f[g[u]][j]);
		}
		for (int j=0;j<19;j++) if ((w[i]>>j)&1) g[j]=i;
	}
	for (int i=1,x,y;i<=q;i++)
	{
		x=read(),y=read();
		bool flg=false;
		for (int j=0;j<19;j++)
			if (((w[y]>>j)&1)&&f[x][j]<=y)
			{
				flg=true; break;
			}
		puts(flg?"Shi":"Fou");
	}
	return 0;
}