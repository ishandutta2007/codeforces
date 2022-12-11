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
void print(int x)
{
	if (x>9) print(x/10); putchar(x%10+48);
}

int n,m,q;
bool tab[1010][1010];
short st[1002][10][1002][10];  //caution bounds  //caution usage of short
int bt[1010];
short getmax(int xl,int yl,int xr,int yr)
{
	int tmpx=bt[xr-xl+1],tmpy=bt[yr-yl+1];
	return max(st[xl][tmpx][yl][tmpy],max(st[xr-(1<<tmpx)+1][tmpx][yl][tmpy],
			max(st[xl][tmpx][yr-(1<<tmpy)+1][tmpy],st[xr-(1<<tmpx)+1][tmpx][yr-(1<<tmpy)+1][tmpy])));
}
int main()
{
	n=read(),m=read();
	for (int i=2;i<=n||i<=m;i++) bt[i]=bt[i>>1]+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			tab[i][j]=read();
	for (int i=n;i;i--)
		for (int j=m;j;j--)
			if (tab[i][j])
				st[i][0][j][0]=min(st[i+1][0][j][0],min(st[i][0][j+1][0],st[i+1][0][j+1][0]))+1;
	for (int u=1;u<10;u++)
		for (int i=1;i+(1<<u)-1<=n;i++)
			for (int j=1;j<=m;j++)
				st[i][u][j][0]=max(st[i][u-1][j][0],st[i+(1<<u-1)][u-1][j][0]);
	for (int v=1;v<10;v++)
		for (int u=0;u<10;u++)
			for (int i=1;i+(1<<u)-1<=n;i++)
				for (int j=1;j+(1<<v)-1<=m;j++)
					st[i][u][j][v]=max(st[i][u][j][v-1],st[i][u][j+(1<<v-1)][v-1]);
	q=read();
	while (q--)
	{
		int xl=read(),yl=read(),xr=read(),yr=read();
		if (!getmax(xl,yl,xr,yr)){puts("0");continue;}
		int l=1,r=min(xr-xl,yr-yl)+1,mid;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (getmax(xl,yl,xr-mid+1,yr-mid+1)>=mid) l=mid;
			else r=mid-1;
		}
		print(l); putchar('\n');
	}
	return 0;
}