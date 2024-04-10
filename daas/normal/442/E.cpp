#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
const double Delta=0.995;
const double eps=1e-15;
const double pi=acos(-1);
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int W,H,n;
double maxn;
struct vec
{
	double x,y;
	vec(double _x=0,double _y=0){x=_x,y=_y;}
}a[1001],ans;
vec operator +(vec x,vec y){return vec(x.x+y.x,x.y+y.y);}
vec operator -(vec x,vec y){return vec(x.x-y.x,x.y-y.y);}
double dist(vec x,vec y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));}
double calc(vec p)
{
	double minn=0x3f3f3f3f,sec=0x3f3f3f3f;
	for(int i=1;i<=n;++i)
	{
		double dis=dist(p,a[i]);
		if(dis<minn) sec=minn,minn=dis;
		else if(dis<sec) sec=dis;
	}
	return sec;
}
void SA()
{
	double t=sqrt((double)W*W+(double)H*H),cnt=3,NOW;
	ans=vec((rand()%1000/1000.0)*W,(rand()%1000/1000.0)*H);
	NOW=calc(ans);
	while(t>eps)
	{
		//if(--cnt==0) cnt=3,t*=Delta;
		double ang=(rand()%100/100.0)*2.0*pi;
		double nx=ans.x+cos(ang)*t,ny=ans.y+sin(ang)*t;
		t*=Delta;
		if(nx<0 || nx>W || ny<0 || ny>H) continue;
		//double nx=ans.x+(double)rand()/RAND_MAX*W*t,ny=ans.y+(double)rand()/RAND_MAX*H*t;
		//if(nx<0 || nx>W || ny<0 || ny>H) continue;
		double v=calc(vec(nx,ny));
		if(v>NOW) NOW=v,ans=vec(nx,ny);
		//else if(exp((NOW-v)/t)*RAND_MAX>=rand()) ans=vec(nx,ny);
	}
	maxn=max(maxn,NOW);
}
int main()
{
	//int C=0;
	//for(double t=3000;t>eps;t*=Delta) ++C;
	//cout<<C<<endl;
	srand(time(NULL));
	srand(rand());
	W=read(),H=read(),n=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	int cas=30;
	while(cas--) SA();
	printf("%.15lf\n",maxn);
	return 0;
}/*YYLAKIOI*/