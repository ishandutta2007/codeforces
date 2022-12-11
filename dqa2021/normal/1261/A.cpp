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

int n,k;
char s[2010],t[2010];
void init()
{
	
}
void solve()
{
	n=read(),k=read();
	scanf("%s",s+1);
	int tmp=0;
	for (int i=1;i<=k;i++)
	{
		int j=(i==1?n/2-k+1:1);
		for (int u=1;u<=j;u++) t[++tmp]='(';
		for (int u=1;u<=j;u++) t[++tmp]=')';
	}
	//puts(t+1);
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
	{
		int pos=-1;
		for (int j=i;j<=n;j++) if (s[j]==t[i])
		{
			pos=j; break;
		}
		printf("%d %d\n",i,pos);
		reverse(s+i,s+pos+1);
		//puts(s+1);
	}
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}