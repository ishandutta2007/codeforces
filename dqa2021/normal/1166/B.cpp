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
	if (flg) x=-x;
	return x;
}

int n;
char ans[2010][2010];
char bin[10]={'a','e','i','o','u'};
void solve(int x,int y)
{
//	printf("%d %d\n",x,y);
	for (int i=1;i<=y;i++)
	{
		for (int j=1;j<=5;j++) ans[j][i]=bin[(i+j)%5];
	}
	for (int i=6;i<=x;i++)
	{
		for (int j=1;j<=5;j++) ans[i][j]=bin[j-1];
		for (int j=6;j<=y;j++) ans[i][j]=bin[0];
	}
	for (int i=1;i<=x;i++)
		for (int j=1;j<=y;j++)
			putchar(ans[i][j]);
	puts("");
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
		if (n%i==0)
		{
			if (n/i<5||i<5) continue;
			solve(i,n/i);
			return 0;
		}
	puts("-1");
	return 0;
}