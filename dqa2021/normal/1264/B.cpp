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

int A,B,C,D;
int ans[1000010],anstot;
int a[1000010],atot;
int b[1000010],btot;
int c[1000010],ctot;
int d[1000010],dtot;
int main()
{
	A=read(),B=read(),C=read(),D=read();
	if (!A&&!C)
	{
		if (B+D!=1) return puts("NO"),0;
		puts("YES");
		if (B) puts("1 ");
		else puts("3 ");
		return 0;
	}
	anstot=(A+C)<<1|1;
	for (int i=1;i<=anstot;i++)
	{
		if (!(i&1)) ans[i]=((i>>1)<=A?0:2);
		else ans[i]=-1;
	}
	for (int i=1;i<=anstot;i+=2)
	{
		if (i==1) {if (ans[i+1]==0) d[++dtot]=i; else b[++btot]=i;}
		else if (i==anstot) {if (ans[i-1]==0) d[++dtot]=i; else b[++btot]=i;}
		else {if (ans[i-1]==0||ans[i+1]==0) c[++ctot]=i; else a[++atot]=i;}
	}
	while (D--)
	{
		if (atot){ans[a[atot--]]=3;continue;}
		if (btot){ans[b[btot--]]=3;continue;}
		return puts("NO"),0;
	}
	while (B--)
	{
		if (atot){ans[a[atot--]]=1;continue;}
		if (ctot){ans[c[ctot--]]=1;continue;}
		if (btot){ans[b[btot--]]=1;continue;}
		if (dtot){ans[d[dtot--]]=1;continue;}
		return puts("NO"),0;
	}
	if (atot||ctot) return puts("NO"),0;
	puts("YES");
	for (int i=1;i<=anstot;i++)
	{
		if (ans[i]==-1) continue;
		printf("%d ",ans[i]);
	}
	putchar('\n');
	return 0;
}