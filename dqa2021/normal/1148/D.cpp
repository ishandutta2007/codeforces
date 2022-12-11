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
struct Node{
	int x,y,pos;
}a[300010],b[300010];
bool cmp1(Node x,Node y)
{
	return x.x<y.x;
}
bool cmp2(Node x,Node y)
{
	return x.x>y.x;
}
int main()
{
	int tmp=read();
	for (int i=1,x,y;i<=tmp;i++)
	{
		x=read(),y=read();
		if (x<y) a[++n]=(Node){x,y,i};
		else b[++m]=(Node){x,y,i};
	}
	sort(a+1,a+n+1,cmp2);
	sort(b+1,b+m+1,cmp1);
	if (n>m)
	{
		printf("%d\n",n);
		for (int i=1;i<=n;i++) printf("%d ",a[i].pos); puts("");
	}
	else
	{
		printf("%d\n",m);
		for (int i=1;i<=m;i++) printf("%d ",b[i].pos); puts("");
	}
	return 0;
}