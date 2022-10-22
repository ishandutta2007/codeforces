#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,cnt,tot,top;
struct vec
{
	int x,y;
	vec(int _x=0,int _y=0) {x=_x,y=_y;}
	bool operator <(const vec &Z) const {return x==Z.x?y<Z.y:x<Z.x;}
	vec operator -(const vec &Z) const {return vec(x-Z.x,y-Z.y);}
}P[MAXN*8],ans[MAXN*8],z[MAXN*8];
ll times(vec x,vec y) {return (ll)x.x*y.y-(ll)x.y*y.x;}
double dist(vec x) {return hypot(x.x,x.y);}
double S(vec x,vec y,vec z) {return (double)abs(times(y-x,z-x))/2;}
double calc(vec x,vec y,vec z) {return dist(x-y)*dist(x-z)*dist(y-z)/S(x,y,z);}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read(),v=read();
		if(y-v<0)
		{
			int lx=x-(v-y),rx=x+(v-y);
			lx=max(lx,0);
			rx=min(rx,100000);
			P[++cnt]=vec(lx,0);
			P[++cnt]=vec(rx,0);
		}
		else P[++cnt]=vec(x,y-v);
		if(y+v>1e5)
		{
			int lx=x-(v+y-1e5),rx=x+(v+y-1e5);
			lx=max(lx,0);
			rx=min(rx,100000);
			P[++cnt]=vec(lx,1e5);
			P[++cnt]=vec(rx,1e5);
		}
		else P[++cnt]=vec(x,y+v);
		if(x-v<0)
		{
			int ly=y-(v-x),ry=y+(v-x);
			ly=max(ly,0);
			ry=min(ry,100000);
			P[++cnt]=vec(0,ly);
			P[++cnt]=vec(0,ry);
		}
		else P[++cnt]=vec(x-v,y);
		if(x+v>1e5)
		{
			int ly=y-(v+x-1e5),ry=y+(v+x-1e5);
			ly=max(ly,0);
			ry=min(ry,100000);
			P[++cnt]=vec(1e5,ly);
			P[++cnt]=vec(1e5,ry);
		}
		else P[++cnt]=vec(x+v,y);
	}
	sort(P+1,P+cnt+1);
	//----
	z[++top]=P[1];
	for(int i=2;i<=cnt;++i)
	{
		while(top>1 && times(P[i]-z[top-1],z[top]-z[top-1])<=0) --top;
		z[++top]=P[i];
	}
	for(int i=2;i<=top;++i) ans[++tot]=z[i];
	//----
	top=0;
	z[++top]=P[cnt];
	for(int i=cnt-1;i>=1;--i)
	{
		while(top>1 && times(P[i]-z[top-1],z[top]-z[top-1])<=0) --top;
		z[++top]=P[i];
	}
	for(int i=2;i<=top;++i) ans[++tot]=z[i];
	//---
	int ans1=-1;
	double ans2=-1;
	ans[tot+1]=ans[1];
	ans[tot+2]=ans[2];
	for(int i=1;i<=tot;++i)
	{
		double R=calc(ans[i],ans[i+1],ans[i+2]);
		if(R>ans2) ans2=R,ans1=i;
	}
	/*cout<<calc(vec(0,2),vec(0,99372),vec(172,99952))<<endl;
	cout<<calc(vec(0,0),vec(0,99372),vec(172,99952))<<endl;*/
	for(int i=0;i<3;++i) printf("%d %d\n",ans[ans1+i].x,ans[ans1+i].y);
	//if(ans[ans1].x==0 && ans[ans1].y==2) cout<<ans[3].x<<" "<<ans[3].y<<" "<<ans1<<" "<<tot<<endl;
	return 0;
}
//tetu no isi to hagane no tuyosa