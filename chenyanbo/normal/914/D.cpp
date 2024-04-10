#include<bits/stdc++.h>
#define N 2100005
using namespace std;
//
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}


int gcd(int a, int b)
{
	if(!(a%b))return b;
	return gcd(b,a%b);
}

//bool
int x,l,r,op,g[N],a[N],fl,q,o,oo,n;

//
void build(int p, int l, int r)
{
	if(l==r)
	{
	    g[p]=a[l];
	    return;
	}
	int mid=(l+r)>>1;//-9 >>1 /2
	build(p<<1,l,mid);
	build((p<<1)|1,mid+1,r);
	g[p]=gcd(g[p<<1],g[(p<<1)|1]);
}

void ch(int p ,int l, int r, int x, int v)
{
	if(l==r)
	{
		g[p]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ch(p<<1,l,mid,x,v);
	else ch((p<<1)|1,mid+1,r,x,v);
	g[p]=gcd(g[p<<1],g[(p<<1)|1]);
}

int que(int p, int l, int r, int x,int y, int oo)
{
	if(fl)return 2;
	int s=0,mid=(l+r)>>1;
	if(x<=l&&y>=r)
	{
		if(g[p]%o)
		{
			if(oo==1)
			{
				fl=1;
				return 1;
			}
			if(l==r)return 1;
			s=que(p<<1,l,mid,x,mid,2);
			if(s==2)
			{
				fl=1;
			     return 2;
			 }
			if(s==1)
			{
			    s+=que((p<<1)|1,mid+1,r,mid+1,y,1);
			    if(s==2)
			    {
			    	fl=1;
			    	return 2;
				}
				return 1;
			}
			if(!s)
			{
				s+=que((p<<1)|1,mid+1,r,mid+1,y,2);
				if(s==2)
			    {
			    	fl=true;
			    	return 2;
				}
				return s;
			}
		}
		else return 0;
	}
	
	if(y<=mid)return que(p<<1,l,mid,x,y,oo);
	if(x>mid)return que((p<<1)|1,mid+1,r,x,y,oo);
	s=que(p<<1,l,mid,x,mid,oo);
	if(s==oo)
	{
		fl=false;
		return s;
	}
	s+=que((p<<1)|1,mid+1,r,mid+1,y,oo-s);
	if(s==oo)fl=false;
	return s;
}

int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	build(1,1,n);
	q=read();
	while(q--)
	{
		op=read();
		if(op==1)
		{
			l=read(); r=read(); o=read();
//			s=0;
fl=0;
			oo=que(1,1,n,l,r,2);
			if(!fl&&oo<=1)puts("YES");else puts("NO");
//			if(s>1)
		}
		else
		{
			l=read(); x=read();
			ch(1,1,n,l,x);
		}
	}
}