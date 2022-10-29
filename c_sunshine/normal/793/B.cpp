#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define next next_
typedef long long LL;
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}

template<class T> inline void readi(T &x)
{char c;bool fl;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));
if(c=='-')fl=1,x=0;else fl=0,x=c-'0';
while(c=getchar(),c>=0&&c<='9')x=x*10+c-'0';
if(fl)x=-x;}
const int maxp=4000005;
const int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int n,m;
char s[1005][1005];
int vs[1005][1005],vt[1005][1005];
int sx,sy,tx,ty;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
			if(s[i][j]=='S')sx=i,sy=j;
			else if(s[i][j]=='T')tx=i,ty=j;
	}
	for(int k=0;k<4;k++)
	{
		int x=sx,y=sy;
		while(x>0&&x<=n&&y>0&&y<=m)
		{
			if(s[x][y]=='*')break;
			vs[x][y]=1;
			x+=dx[k];
			y+=dy[k];
		}
	}
	for(int k=0;k<4;k++)
	{
		int x=tx,y=ty;
		while(x>0&&x<=n&&y>0&&y<=m)
		{
			if(s[x][y]=='*')break;
			vt[x][y]=1;
			x+=dx[k];
			y+=dy[k];
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool ss=0,tt=0;
		for(int j=1;j<=m;j++)
		{
			if(vs[i][j])ss=1;
			if(vt[i][j])tt=1;
			if(s[i][j]=='*')ss=tt=0;
			if(ss&&tt){puts("YES");return 0;}
		}
	}
	for(int j=1;j<=m;j++)
	{
		bool ss=0,tt=0;
		for(int i=1;i<=n;i++)
		{
			if(vs[i][j])ss=1;
			if(vt[i][j])tt=1;
			if(s[i][j]=='*')ss=tt=0;
			if(ss&&tt){puts("YES");return 0;}
		}
	}
	puts("NO");
	return 0;
}