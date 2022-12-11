#include<cstdio>
#include<algorithm>
using namespace std;
#define eps 1e-12
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main()
{
	int n=read(),x1,y1,x2,y2,rx,ry,vx,vy;
	double t1=0,t2=1e18;
	x1=read();y1=read();x2=read();y2=read();
	if(x1==x2||y1==y2)return 0*puts("-1");
	while(n--)
	{
		rx=read();ry=read();vx=read();vy=read();
		if(vx>0)t1=max(t1,(double)(x1-rx)/vx),t2=min(t2,(double)(x2-rx)/vx);
		if(vx<0)t1=max(t1,(double)(x2-rx)/vx),t2=min(t2,(double)(x1-rx)/vx);
		if(!vx&&(rx<=x1||rx>=x2))return 0*puts("-1");
		if(vy>0)t1=max(t1,(double)(y1-ry)/vy),t2=min(t2,(double)(y2-ry)/vy);
		if(vy<0)t1=max(t1,(double)(y2-ry)/vy),t2=min(t2,(double)(y1-ry)/vy);
		if(!vy&&(ry<=y1||ry>=y2))return 0*puts("-1");
	}
	if(t2-t1<eps)puts("-1");
	else printf("%.10lf",t1);
}