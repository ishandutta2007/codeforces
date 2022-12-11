#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
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
char s[1000010];
int w[1000010],p[1000010];
inline int gethash(int x,int y)
{
	return (x-1)*m+y;
}
inline void work(int *A,int a,int b,int c,int d)  //(a,b) (c,d)
{
	//if (A==p) printf("work %d %d %d %d\n",a,b,c,d);
	A[gethash(a,b)]++;
	if (c<n) A[gethash(c+1,b)]--;
	if (d<m) A[gethash(a,d+1)]--;
	if (c<n&&d<m) A[gethash(c+1,d+1)]++;
}
int& ww(int x,int y)
{
	if (x<=n&&x>=1&&y<=m&&y>=1) return w[gethash(x,y)];
	return w[0];
}
int& pp(int x,int y)
{
	if (x<=n&&x>=1&&y<=m&&y>=1) return p[gethash(x,y)];
	return p[0];
}
bool check(int x)
{
	//printf("check %d\n",x);
	memset(w,0,sizeof w);
	memset(p,0,sizeof p);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[gethash(i,j)]=='.')
				work(w,max(1,i-x),max(1,j-x),min(n,i+x),min(m,j+x));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			ww(i,j)+=ww(i-1,j)+ww(i,j-1)-ww(i-1,j-1);
			if (i-x>0&&i+x<=n&&j-x>0&&j+x<=m&&!ww(i,j)) work(p,max(1,i-x),max(1,j-x),min(n,i+x),min(m,j+x));
			//if (i-x>0&&i+x<=n&&j-x>0&&j+x<=m&&!ww(i,j)) printf("get %d %d\n",i,j);
		}
//	for (int i=1;i<=n;i++,puts(""))
//		for (int j=1;j<=m;j++)
//			printf("%d ",pp(i,j));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			pp(i,j)+=pp(i-1,j)+pp(i,j-1)-pp(i-1,j-1);
			//printf("%d ",pp(i,j));
			if (s[gethash(i,j)]=='X'&&!pp(i,j)) return false;
		}
	return true;
}
void print(int x)
{
	//printf("check %d\n",x);
	memset(w,0,sizeof w);
	//memset(p,0,sizeof p);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[gethash(i,j)]=='.')
				work(w,max(1,i-x),max(1,j-x),min(n,i+x),min(m,j+x));
	for (int i=1;i<=n;i++,putchar('\n'))
		for (int j=1;j<=m;j++)
		{
			ww(i,j)+=ww(i-1,j)+ww(i,j-1)-ww(i-1,j-1);
			if (i-x>0&&i+x<=n&&j-x>0&&j+x<=m&&!ww(i,j)) putchar('X');
			else putchar('.');
		}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) scanf("%s",s+(i-1)*m+1);
	int l=0,r=1000000,mid;
	while (l<r)
	{
		mid=l+r+1>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	print(l);
	return 0;
}