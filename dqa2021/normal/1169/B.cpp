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

int n,m;
int a[300010],b[300010];
int pos;
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		a[i]=read(),b[i]=read();
		if (a[i]>b[i]) swap(a[i],b[i]);
	}
	for (int i=2;i<=m;i++)
	{
		if (!(a[i]==a[1]||a[i]==b[1]||b[i]==a[1]||b[i]==b[1])){pos=i;break;}
	}
	if (!pos) return puts("YES"),0;
	bool flg=true;
	for (int i=1;i<=m;i++)
	{
		if (a[i]==a[1]||a[i]==a[pos]||b[i]==a[1]||b[i]==a[pos]) continue;
		flg=false;
		break;
	}
	if (flg) return puts("YES"),0;
	flg=true;
	for (int i=1;i<=m;i++)
	{
		if (a[i]==b[1]||a[i]==a[pos]||b[i]==b[1]||b[i]==a[pos]) continue;
		flg=false;
		break;
	}
	if (flg) return puts("YES"),0;
	flg=true;
	for (int i=1;i<=m;i++)
	{
		if (a[i]==a[1]||a[i]==b[pos]||b[i]==a[1]||b[i]==b[pos]) continue;
		flg=false;
		break;
	}
	if (flg) return puts("YES"),0;
	flg=true;
	for (int i=1;i<=m;i++)
	{
		if (a[i]==b[1]||a[i]==b[pos]||b[i]==b[1]||b[i]==b[pos]) continue;
		flg=false;
		break;
	}
	if (flg) return puts("YES"),0;
	puts("NO"); return 0;
}