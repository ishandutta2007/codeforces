#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do c=getchar();while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#include<iostream>
using namespace std;
#define MAXN 3000
#define MAXM 9000
#define ll long long
#define INF (1LL<<62)
struct edge{int t,c,nx;ll w;}e[MAXM*2+5];
int a[MAXN+5],h[MAXN+5],en=1;
void ins(int x,int y,ll w,int c)
{
	e[++en].nx=h[x];h[x]=en;e[en].t=y;e[en].w=w;e[en].c=c;
	e[++en].nx=h[y];h[y]=en;e[en].t=x;e[en].w=0;e[en].c=-c;
}
int q[MAXN+5],hd,tl,d[MAXN+5],inq[MAXN+5],z[MAXN+5];ll mc;
bool spfa()
{
	int i,x,y;
	for(i=0;i<=MAXN;i++){d[i]=0x7fffffff;inq[i]=0;}
	d[q[hd=0]=0]=0;
	for(tl=1;hd!=tl;hd<MAXN?hd++:hd=0)
	{
		x=q[hd];
		for(i=h[x];i;i=e[i].nx)
		{
			y=e[i].t;
			if(e[i].w&&e[i].c+d[x]<d[y])
			{
				d[y]=e[i].c+d[x];z[y]=i;
				if(!inq[y]){inq[y]=1;q[tl++]=y;if(tl>MAXN)tl=0;}
			}
		}
		inq[x]=0;
	}
	return d[1]!=0x7fffffff;
}
int min(int a,int b){return a<b?a:b;}
void mcmf()
{
	int i;ll mn;
	while(spfa())
	{
		mn=INF; 
		for(i=z[1];i;i=z[e[i^1].t])mn=min(mn,e[i].w);
		for(i=z[1];i;i=z[e[i^1].t])
		{
			e[i].w-=mn;
			e[i^1].w+=mn;
		}
		mc+=mn*d[1];
	}
}
int main()
{
	int n,i;ll x;
	read(n); 
	for(i=1;i<=n;i++)read(a[i]);
	ins(0,2,INF,1);ins(0,n,INF,1);
	for(i=2;i<=n;i++)
	{
		x=a[i]-a[i-1]-1;
		if(x<0)ins(i,1,-x,0);
		if(x>0)ins(0,i,x,0);
		if(i>2){ins(i-1,i,INF,1);ins(i,i-1,INF,1);}
	}
	if(n>1)mcmf();
	cout<<mc;
}