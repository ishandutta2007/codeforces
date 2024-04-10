#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<queue>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,r,c,x,y,map[2001][2001],ans,vis[2001][2001],change[4][2]={{0,1},{0,-1},{1,0},{-1,0}},h,t,len;
char s[2001];
struct data
{
	int x,y,l,r;
	data(int _x=0,int _y=0,int _l=0,int _r=0){x=_x,y=_y,l=_l,r=_r;}
}dl[4000001];
int main()
{
	n=read(),m=read();
	r=read(),c=read();
	x=read(),y=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j) map[i][j]=(s[j]=='.');
	}
	/*for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j) cout<<map[i][j]<<" ";
		cout<<endl;
	}*/
	h=t=0;
	dl[++t]=data(r,c,x,y);
	len=n*m+1;
	vis[r][c]=1;
	while(h!=t)
	{
		h=h%len+1;
		data u=dl[h];
		//cout<<"cao "<<u.x<<" "<<u.y<<" "<<u.l<<" "<<u.r<<endl;
		++ans;
		for(int i=0;i<4;++i)
		{
			int nx=u.x+change[i][0];
			int ny=u.y+change[i][1];
			int nl=u.l;
			int nr=u.r;
			if(i==1) --nl;
			if(i==0) --nr;
			if(nx<0 || ny<0 || nx>n || ny>m || nl<0 || nr<0 || vis[nx][ny] || !map[nx][ny]) continue;
			vis[nx][ny]=1;
			if(i<=1)
			{
				t=t%len+1;
				dl[t]=data(nx,ny,nl,nr);
			}
			else
			{
				dl[h]=data(nx,ny,nl,nr);
				h=(h==1?len:h-1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}