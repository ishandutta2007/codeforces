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

int n,a,x,b,y;
int ta[110],tb[110];
int main()
{
	n=read(),a=read(),x=read(),b=read(),y=read();
	if (x<a) x+=n; if (b<y) b+=n;
	for (int i=a,j=1;i<=x;i++,j++)
	{
		ta[i>n?i-n:i]=j;
	}
	for (int i=b,j=1;i>=y;i--,j++)
	{
		tb[i>n?i-n:i]=j;
	}
	for (int i=1;i<=n;i++) if (ta[i]&&tb[i]&&ta[i]==tb[i]) return puts("YES"),0;
	puts("NO"); return 0;
}