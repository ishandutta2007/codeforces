#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define K 500
struct query{int x,y,d;}q[MN+5];
int a[MN+5],b[MN+5],s[MN+5],ans[MN+5],z[MN+5],zn;
double p[MN+5];
inline int id(int x){return (x-1)/K;}
bool cmp(const query&a,const query&b)
{
	return id(a.y)==id(b.y)?a.y-a.x>b.y-b.x:id(a.y)<id(b.y);
}
double cal(int x,int y)
{
	return (double)(b[y]-b[x])/(a[x]-a[y]);
}
int main()
{
	int n,m,i,j,k;
	for(n=read(),i=1;i<=n;++i)s[i]=s[i-1]+(a[i]=read());
	for(i=1;i<=n;++i)b[i]=a[i]*i-s[i];
	for(m=read(),i=1;i<=m;++i)
	{
		q[i].x=read();q[i].y=read();ans[q[i].d=i]=1e9;
		for(j=q[i].y;j>q[i].y-q[i].x&&j>id(q[i].y)*K;--j)
			ans[i]=min(ans[i],s[q[i].y]+a[j]*(q[i].x-q[i].y)+b[j]);
	}
	sort(q+1,q+m+1,cmp);
	for(i=0,j=1;i<MN/K;++i)for(zn=0,k=i*K;j<=m&&id(q[j].y)==i;++j)
	{
		for(;k>q[j].y-q[j].x;--k)if(!zn||a[k]<a[z[zn]])
		{
			while(zn>1&&cal(k,z[zn])<=p[zn])--zn;
			z[++zn]=k;p[zn]=cal(k,z[zn-1]);
		}
		if(zn)
		{
			int l=2,r=zn,mid,res=1;
			while(l<=r)
			{
				mid=l+r>>1;
				if(q[j].x-q[j].y>=p[mid])res=mid,l=mid+1;
				else r=mid-1;
			}
			ans[q[j].d]=min(ans[q[j].d],s[q[j].y]+a[z[res]]*(q[j].x-q[j].y)+b[z[res]]);
		}
	}
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
}