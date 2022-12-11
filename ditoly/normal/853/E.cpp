#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MK 10
#define MN 100000
#define ps(x) (upper_bound(c+1,c+cn+1,x)-c-1)
struct vec{int x,y;}v[MK+5];
struct work{double a;int x,y,z;}w[MN*2+5];
bool cmpv(const vec&a,const vec&b){return atan2(a.y,a.x)<atan2(b.y,b.x);}
bool cmpw(const work&a,const work&b){return fabs(a.a-b.a)<1e-7?a.z<b.z:a.a<b.a;}
int x[MN+5],y[MN+5],a[MN+5],c[MN+5],cn,sx,sy,px[MN+5],py[MN+5],t[MN+5];
ll ans[MN+5],s[MN+5];
void add(int k,int x){for(;k<=MN;k+=k&-k)s[k]+=x;}
ll sum(int k){ll res=0;for(;k;k-=k&-k)res+=s[k];return res;}
int main()
{
	int k,n,q,i,j;
	k=read();n=read();q=read();
	for(i=1;i<=k;++i)
	{
		v[i].x=read();v[i].y=read();
		if(v[i].x<0)v[i].x=-v[i].x,v[i].y=-v[i].y;
		if(!v[i].x&&v[i].y<0)v[i].y=-v[i].y;
		sx+=v[i].x;sy+=v[i].y;
	}
	sort(v+1,v+k+1,cmpv);
	for(i=1;i<=n;++i)c[i]=x[i]=read(),y[i]=read(),a[i]=read();
	sort(c+1,c+n+1);cn=unique(c+1,c+n+1)-c-1;
	for(i=1;i<=q;++i)px[i]=read(),py[i]=read(),t[i]=read(),px[i]-=sx*t[i],py[i]-=sy*t[i],t[i]<<=1;
	for(i=1;i<=k;++i)
	{
		if(!v[i].x){for(j=1;j<=q;++j)py[j]+=v[i].y*t[j];continue;}
		for(j=1;j<=n;++j)w[j]=(work){y[j]-(double)x[j]*v[i].y/v[i].x,x[j],a[j],0};
		for(j=1;j<=q;++j)w[n+j]=(work){py[j]-(double)px[j]*v[i].y/v[i].x,px[j],px[j]+v[i].x*t[j],-j},
			px[j]+=v[i].x*t[j],py[j]+=v[i].y*t[j];
		sort(w+1,w+n+q+1,cmpw);
		memset(s,0,sizeof(s));
		for(j=1;j<=n+q;++j)
			if(w[j].z)ans[-w[j].z]-=sum(ps(w[j].y))-sum(ps(w[j].x-(i<2)));
			else add(ps(w[j].x),w[j].y);
	}
	for(i=1;i<=k;++i)
	{
		if(!v[i].x)break;
		for(j=1;j<=n;++j)w[j]=(work){y[j]-(double)x[j]*v[i].y/v[i].x,x[j],a[j],0};
		for(j=1;j<=q;++j)w[n+j]=(work){py[j]-(double)px[j]*v[i].y/v[i].x,px[j]-v[i].x*t[j],px[j],j},
			px[j]-=v[i].x*t[j],py[j]-=v[i].y*t[j];
		sort(w+1,w+n+q+1,cmpw);
		memset(s,0,sizeof(s));
		for(j=1;j<=n+q;++j)
			if(w[j].z)ans[w[j].z]+=sum(ps(w[j].y-(i>1)))-sum(ps(w[j].x-1));
			else add(ps(w[j].x),w[j].y);
	}
	for(i=1;i<=q;++i)printf("%I64d\n",ans[i]);
}