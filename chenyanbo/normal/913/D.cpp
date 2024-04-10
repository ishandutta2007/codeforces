#include<bits/stdc++.h>
#define N 200050

using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int mid,oo,n,T,l,r,ans,o,gg,g,t,b[N],c[N];

struct node
{
	int a, t ,id;
	bool operator < (const node & x)const
	{
		if(t!=x.t)return t<x.t;
	   //
		return id<x.id;
	}
}a[N];

int main()
{
	n=read(); T=read();
	for(int i=1; i<=n; ++i)a[i].a=read(),a[i].t=read(),a[i].id=i; 
	sort(a+1,a+n+1);
	l=1; r=n;
	while(l<=r)
	{
		t=0; g=0;
		mid=(l+r)>>1;
		for(int i=1; i<=n; ++i)if(a[i].a>=mid)
		{
			t+=a[i].t;
			if(t>T)break;
			b[++g]=a[i].id;
			if(g==mid)break;
		}
		if(g>=mid) 
		{
			ans=mid;
			for(int i=1; i<=g; ++i)c[i]=b[i];  //meecpy se  n+1
			oo=g;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	printf("%d\n",oo);
	for(int i=1; i<=oo; ++i)printf("%d ",c[i]);
}