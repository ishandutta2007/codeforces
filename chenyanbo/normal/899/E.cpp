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

struct node
{
	int l, r, v; //node()  /// node nod
	bool operator < (const node & a)const
	{
		if(v!=a.v)return v>a.v;
		if(l!=a.l)return l<a.l;
		return r<a.r ;/// // //// //
	}
};
//y0 y1
int v_,l,r,l1,r1,v1,l2,v2,r2,v,u,n, a[N] ,pr[N],ne[N],c[N],d[N],g[N],h[N];
set<node>::iterator it;  //c++11auto
set<node> s;  //>_> <_< //_
int ans; //0 =0
int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	pr[1]=1;
	for(int i=2; i<=n; ++i)
	{
		if(a[i]!=a[i-1])
		{
			s.insert((node){pr[i-1],i-1,i-pr[i-1]});
		    pr[i]=i;
		    h[i-1]=i-pr[i-1];
		    ne[pr[i-1]]=i-1;
		    g[pr[i-1]]=i-pr[i-1];
		    c[pr[i-1]]=a[i-1];
		    d[i-1]=a[i-1];
		}
		else pr[i]=pr[i-1];
	}
	s.insert((node){pr[n],n,n-pr[n]+1}); h[n]=n-pr[n]+1; ne[pr[n]]=n; g[pr[n]]=n-pr[n]+1;
	c[pr[n]]=a[n]; d[n]=a[n];
	
	
	//ne pr   g h  c d
	
	while(!s.empty()) 
	{
		it=s.begin();
		++ans;
		l=(*it).l;
		r=(*it).r;
		v=(*it).v;
		s.erase(it);
		
		if(l==1)
		{
			if(r==n)break;
			l2=r+1;
			r2=ne[r+1];
			v2=g[l2];
			
			g[l]=v2;
			ne[l]=r2;
			pr[r2]=l;
			c[l]=c[l2];
			
			s.erase((node){l2,r2,v2}); 
			s.insert((node){l,r2,v2});
			continue;
		}
		
		if(r==n)
		{
			r1=l-1;
			l1=pr[r1];
			v1=h[r1];
			
			h[r]=v1; 
			pr[r]=l1;
			ne[l1]=r;
			d[n]=d[r1];
			
			s.erase((node){l1,r1,v1}); 
			s.insert((node){l1,r,v1});
			continue;
		}
		
		r1=l-1;
		l1=pr[r1];
		v1=h[r1];
		l2=r+1;
		r2=ne[l2];
		v2=g[l2];
		
		u=d[r1]; v_=c[l2];
		if(u==v_)
		{
			g[l1]=v1+v2;
			h[r2]=v1+v2;
			c[l1]=c[l2];
			d[r2]=c[l2];  // u v //l 1
			pr[r2]=l1;
			ne[l1]=r2;
			s.erase((node){l1,r1,v1});//again //kong erase //empty
			s.erase((node){l2,r2,v2});
			s.insert((node){l1,r2,v1+v2}); //,}  ={}  //,}
			continue;
		}
		
		ne[l1]=r;
		pr[r]=l1;
		d[r]=u;
		h[r]=v1;
		s.erase((node){l1,r1,v1});
		s.insert((node){l1,r,v1});
	}
	printf("%d\n",ans); //uoj \n  //_ //   ll l ull  int  //...ll
}