#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,a[101][101],mem[10001][3],cnt;
char s[1001];
int calc(int x,int y)
{
	a[x][y]^=1;
	return (x-1)*m+y;
}
void print(int v)
{
	int x=v/m;
	if(v%m)
		printf("%d %d ",x+1,v-x*m);
	else
		printf("%d %d ",x,m);
}
void P(int x,int y)
{
	mem[++cnt][0]=calc(x,y);
	mem[cnt][1]=calc(3-x,y);
	mem[cnt][2]=calc(x,3-y);
}
void solve()
{
	int v=a[1][1]+a[1][2]+a[2][1]+a[2][2];
	if(!v)
		return;
	if(v==1)
	{
		int x,y,f=1;
		for(x=1;x<=2;++x)
		{
			for(y=1;y<=2;++y)
				if(a[x][y])
				{
					f=0;
					break;
				}
			if(!f)
				break;
		}
		P(x,y);
		P(3-x,y);
		P(x,3-y);
	}
	if(v==2)
	{
		int x3,y3,x4,y4,f=1;
		for(x3=1;x3<=2;++x3)
		{
			for(y3=1;y3<=2;++y3)
				if(!a[x3][y3])
				{
					f=0;
					break;
				}
			if(!f)
				break;
		}
		f=1;
		for(x4=1;x4<=2;++x4)
		{
			for(y4=1;y4<=2;++y4)
				if(!a[x4][y4] && (x4!=x3 || y4!=y3))
				{
					f=0;
					break;
				}
			if(!f)
				break;
		}
		if(x3==x4 || y3==y4)
		{
			P(x3,y3);
			P(x4,y4);
		}
		else
		{
			P(3-x3,y3);
			P(3-x4,y4);
		}
	}
	if(v==3)
	{
		int x,y,f=1;
		for(x=1;x<=2;++x)
		{
			for(y=1;y<=2;++y)
				if(!a[x][y])
				{
					f=0;
					break;
				}
			if(!f)
				break;
		}
		P(3-x,3-y);
	}
	if(v==4)
	{
		P(1,1);
		P(1,2);
		P(2,1);
		P(2,2);
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s);
			for(int j=1;j<=m;++j)
				a[i][j]=s[j-1]-'0';
		}
		cnt=0;
		for(int i=n;i>2;--i)
		{
			for(int j=1;j<m;++j)
				if(a[i][j])
				{
					mem[++cnt][0]=calc(i,j);
					mem[cnt][1]=calc(i-1,j);
					mem[cnt][2]=calc(i-1,j+1);
				}
			if(a[i][m])
			{
				mem[++cnt][0]=calc(i,m);
				mem[cnt][1]=calc(i-1,m);
				mem[cnt][2]=calc(i-1,m-1);
			}
		}
		for(int i=m;i>2;--i)
		{
			if(!a[1][i] && !a[2][i])
				continue;
			if(a[1][i])
			{
				if(a[2][i])
				{
					mem[++cnt][0]=calc(1,i);
					mem[cnt][1]=calc(2,i);
					mem[cnt][2]=calc(1,i-1);
				}
				else
				{
					mem[++cnt][0]=calc(1,i);
					mem[cnt][1]=calc(1,i-1);
					mem[cnt][2]=calc(2,i-1);
				}
			}
			else
			{
				mem[++cnt][0]=calc(2,i);
				mem[cnt][1]=calc(2,i-1);
				mem[cnt][2]=calc(1,i-1);
			}
		}
		solve();
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i)
		{
			print(mem[i][0]),print(mem[i][1]),print(mem[i][2]);
			putchar('\n');
		}
	}
	return 0;
}