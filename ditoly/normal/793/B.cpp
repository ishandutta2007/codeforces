#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 1000
#define MQ 4000000
char s[MN+5][MN+5];
const int o[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,f[MN+5][MN+5][4],qx[MQ+5],qy[MQ+5],qt[MQ+5],ql=1,qr;
inline int ok(int x,int y){return f[x][y][0]||f[x][y][1]||f[x][y][2]||f[x][y][3];}
void renew(int x,int y,int t){if(!f[x][y][t])++qr,f[qx[qr]=x][qy[qr]=y][qt[qr]=t]=1;}
void solve()
{
	for(;ql<=qr;++ql)
	{
		int xx=qx[ql]+o[qt[ql]][0],yy=qy[ql]+o[qt[ql]][1];
		if(s[xx][yy]=='.')renew(xx,yy,qt[ql]);
	}
}
void change()
{
	int i,j,k;
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(ok(i,j))for(k=0;k<4;++k)renew(i,j,k);
}
int main()
{
	int i,j,k,tx,ty,xx,yy;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)
	{
		if(s[i][j]=='S')for(k=0;k<4;++k)renew(i,j,k);
		if(s[i][j]=='T')s[i][j]='.',tx=i,ty=j;
	}
	solve();change();solve();change();solve();
	puts(ok(tx,ty)?"YES":"NO");
}