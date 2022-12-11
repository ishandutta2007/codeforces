#include<cstdio>
#include<cmath>
inline double dis(double x,double y){return sqrt(x*x+y*y);}
int main()
{
	int x1,x2,y1,y2,v,t,vx,vy,wx,wy,i;double l,r,mid;
	scanf("%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&v,&t,&vx,&vy,&wx,&wy);
	for(l=0,r=1e9,i=1;i<=100;++i)
	{
		mid=(l+r)/2;
		if(dis(x1+(mid<t?vx*mid:vx*t+wx*(mid-t))-x2,y1+(mid<t?vy*mid:vy*t+wy*(mid-t))-y2)<v*mid)r=mid;else l=mid;
	}
	printf("%.10lf",mid);
}