#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
double R,r;
double k;
double dist(double x1,double y1,double x2,double y2)
{
  double dx=x1-x2,dy=y1-y2;
  return sqrt(dx*dx+dy*dy);
}
double dist(double dx,double dy)
{
  return sqrt(dx*dx+dy*dy);
}
void res(double &x,double &y)
{
  double d=dist(x,y),d_;
  d_=1/d;
  x=x/d*d_;
  y=y/d*d_;
}
void work()
{
  double rr,roy,rox,x1,y1,x2,y2;
  rr=(0.5/r-0.5/R)/2.0;
  rox=(0.5/r+0.5/R)/2.0;
  roy=rr*2.0*k;
  double d0=dist(rox,roy);
  x1=rox-rr*rox/d0;
  y1=roy-rr*roy/d0;
  x2=rox*2-x1;
  y2=roy*2-y1;
  res(x1,y1);
  res(x2,y2);
  printf("%.12lf\n",dist(x1,y1,x2,y2)/2);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    scanf("%lf%lf%lf",&R,&r,&k);
    work();
  }
  return 0;
}