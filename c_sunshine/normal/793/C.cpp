#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}

const double eps=1e-11;
int n;
int x1,x2,y1,y2;
double L=0,R=1e100;

void up(int a,int b,int v)
{
	if(v==0)
	{
		if(a<0&&b>0)return;
		R=-1;
	}
	double p,q;
	p=(double)a/v,q=(double)b/v;
	if(p>q)swap(p,q);
	L=max(L,p);
	R=min(R,q);
}

int main()
{
	scanf("%d",&n);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)
	{
		int rx,ry,vx,vy;
		scanf("%d%d%d%d",&rx,&ry,&vx,&vy);
		up(x1-rx,x2-rx,vx);
		up(y1-ry,y2-ry,vy);
	}
	if(L+eps>R)puts("-1");
	else printf("%.10lf\n",L);
	return 0;
}