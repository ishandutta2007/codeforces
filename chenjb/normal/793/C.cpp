#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#define LL long long 
#define eps 1e-14
using namespace std;
struct node
{
	double x,y,vx,vy;
	double a,b;
}a[110000];
int n;
int flag;
double x1,y1,x2,y2;
void get(int ii)
{
	node x=a[ii];
	double tmp[5];
	memset(tmp,0,sizeof(tmp));
	double t,nowy,nowx;
	int tt=0;
	int inside;
	if (x.vx==0&&(x.x<=x1||x.x>=x2)){flag=0; return; }
	if (x.vy==0&&(x.y<=y1||x.y>=y2)){flag=0; return; }

	if (x.x>x1&&x.x<x2&&x.y>y1&&x.y<y2)inside=1; else inside=0;
	if (x.vx==0&&x.vy==0)
	{
		if (inside)a[ii].a=0,a[ii].b=2147483647474747;
		else flag=0;
		return;
	}
	if (x.vx!=0)
	{
		t=(x1-x.x)/x.vx;
		nowy=x.y+t*x.vy;
		if (t>=0&&nowy>=y1&&nowy<=y2)tmp[++tt]=t;
		t=(x2-x.x)/x.vx;
		nowy=x.y+t*x.vy;
		if (t>=0&&nowy>=y1&&nowy<=y2)tmp[++tt]=t;
	}
	if (x.vy!=0)
	{
		t=(y1-x.y)/x.vy;
		nowx=x.x+t*x.vx;
		if (t>=0&&nowx>=x1&&nowx<=x2)tmp[++tt]=t;
		t=(y2-x.y)/x.vy;
		nowx=x.x+t*x.vx;
		if (t>=0&&nowx>=x1&&nowx<=x2)tmp[++tt]=t;
	}
	if (tt==0){flag=0; return;}
	sort(tmp+1,tmp+tt+1);
	a[ii].a=a[ii].b=-1;
	if (inside)a[ii].a=0,a[ii].b=tmp[1];
	else 
	for(int i=1;i<tt;i++)
		if (tmp[i+1]-tmp[i]>eps)
		{
			a[ii].a=tmp[i]+eps;
			a[ii].b=tmp[i+1]-eps;
			break;
		}
	if (a[ii].a==-1)flag=0;
}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	flag=1;
	double l=-1000000;
	double r=2147483647474747;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].vx,&a[i].vy);
		get(i);
		l=max(l,a[i].a);
		r=min(r,a[i].b);
	}
	if (l>r||flag==0)cout<<"-1"<<endl;
	else printf("%.20lf\n",l);
	return 0;
}