#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
struct query{int l,r,id;}q[MN+5];
bool cmp(const query&a,const query&b){return a.l/K==b.l/K?a.r<b.r:a.l<b.l;}
int a[MN+5],u[MN+5],o[MN+5],p[MN+5],t[MN+5],z[MN+5];
int qx[MN+5],qxl,qxr,qy[MN+5],qyl,qyr,f[MN+5],ans[MN+5];
vector<int> v;
void rev(int x)
{
	int&k=t[a[x]];
	--z[k];++z[(o[x]^=1)?++k:--k];
}
int front(){return min(qxl>qxr?1e9:qx[qxl],qyl>qyr?1e9:qy[qyl]);}
void pop(){qxl<=qxr&&front()==qx[qxl]?++qxl:++qyl;}
void push(int x,int k){if(qyl>qyr||qy[qyr]<x)qy[++qyr]=x;f[x]+=k;}
int main()
{
	int n=read(),m,i,x,y,l=1,r=0;
	for(i=1;i<=n;++i)if(++u[a[i]=read()]==K)v.push_back(a[i]);
	memset(u,0,sizeof(u));
	for(m=read(),i=1;i<=m;++i)q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1,cmp);
	for(i=1;i<=m;++i)
	{
		while(l<q[i].l)rev(l++);
		while(l>q[i].l)rev(--l);
		while(r<q[i].r)rev(++r);
		while(r>q[i].r)rev(r--);
		qxl=qyl=1;qxr=qyr=0;
		for(x=1;x<K;++x)if(z[x])f[qx[++qxr]=x]=z[x],u[x]=i;y=qxr;
		for(u[x=0]=i;x<v.size();++x)if(u[t[v[x]]]<i)f[qx[++qxr]=t[v[x]]]=z[t[v[x]]],u[t[v[x]]]=i;
		sort(qx+y+1,qx+qxr+1);
		while(true)
		{
			x=front();pop();
			if(f[x]>1)ans[q[i].id]+=(x<<1)*(f[x]>>1),push(x<<1,f[x]>>1),f[x]&=1;
			if(f[x])
			{
				while((y=front())==x)pop();if(y==1e9){f[x]=0;break;}
				ans[q[i].id]+=x+y,push(x+y,1),--f[x],--f[y];
			}
		}
	}
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
}