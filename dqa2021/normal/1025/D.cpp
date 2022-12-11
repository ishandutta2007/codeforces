#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}

int n,w[710];
bool ok[710][710],L[710][710],R[710][710];
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1;i<=n;i++)
	{
		ok[i][0]=ok[i][n+1]=ok[i][i]=true;
		for (int j=i+1;j<=n;j++) if (gcd(w[i],w[j])^1) ok[i][j]=ok[j][i]=true;
	}
	for (int i=n;i;i--)
	{
		for (int j=i;j<=n;j++)
		{
			for (int u=i;u<=j;u++)
				if (ok[u][j+1]&&(u==i||L[i][u-1])&&(u==j||R[u+1][j]))
				{
					L[i][j]=true; break;
				}
			for (int u=i;u<=j;u++)
				if (ok[u][i-1]&&(u==i||L[i][u-1])&&(u==j||R[u+1][j]))
				{
					R[i][j]=true; break;
				}
		}
	}
	puts(L[1][n]?"Yes":"No");
	return 0;
}