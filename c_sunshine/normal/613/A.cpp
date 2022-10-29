#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct point
{
	double x,y;
	point(){}
	point(double xx,double yy):x(xx),y(yy){}
	point operator+(const point &o)const{return point(x+o.x,y+o.y);}
	point operator-(const point &o)const{return point(x-o.x,y-o.y);}
	double operator*(const point &o)const{return x*o.y-y*o.x;}
}p[100005];

double dist(point p)
{return sqrt(p.x*p.x+p.y*p.y);}

bool dif(double a,double b)
{return a<0&&b>0||a>0&&b<0;}

int main()
{
	int n;
	double xx,yy;
	scanf("%d%lf%lf",&n,&xx,&yy);
	double l=1e15,r=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].x-=xx,p[i].y-=yy;
		r=max(r,dist(p[i]));
		l=min(l,dist(p[i]));
	}
	p[n+1]=p[1];
	for(int i=1;i<=n;i++)
	{
		point t=p[i]-p[i+1];
		t=point(-t.y,t.x);
		if(dif(t*p[i],t*p[i+1]))l=min(l,fabs(p[i]*p[i+1]/dist(p[i]-p[i+1])));
	}
	printf("%.14lf\n",double(acosl(-1.0)*(r*r-l*l)));
	return 0;
}