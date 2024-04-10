//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
const ll s[]={1,42,1764,74088,3111696,130691232,5489031744,230539333248,9682651996416,406671383849472,17080198121677824,717368321110468608,0x7fffffffffffffff};
//13 numbers
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll a[100003];
struct seg
{
	ll tag,mn,cov=-1;
}f[400003];
void build(int l,int r,int x)
{ 
	if(l==r) 
	{
		f[x].cov=a[l],f[x].mn=*lower_bound(s,s+13,a[l])-a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,(x<<1)+1);
	f[x].mn=min(f[x<<1].mn,f[(x<<1)+1].mn);
}
void push_down(int x)
{
	if(~f[x].cov) 
		f[x<<1].cov=f[(x<<1)+1].cov=f[x].cov,
		f[x<<1].mn=f[(x<<1)+1].mn=f[x].mn,
		f[x].cov=-1,f[(x<<1)].tag=f[(x<<1)+1].tag=0;
	else
		(~f[x<<1].cov)
		?(f[x<<1].cov+=f[x].tag,f[x<<1].mn=*lower_bound(s,s+13,f[x<<1].cov)-f[x<<1].cov)
		:(f[x<<1].mn-=f[x].tag,f[x<<1].tag+=f[x].tag),
		(~f[(x<<1)+1].cov)
		?(f[(x<<1)+1].cov+=f[x].tag,f[(x<<1)+1].mn=*lower_bound(s,s+13,f[(x<<1)+1].cov)-f[(x<<1)+1].cov)
		:(f[(x<<1)+1].mn-=f[x].tag,f[(x<<1)+1].tag+=f[x].tag),
		f[x].tag=0;
	return ;
}
ll query(int l,int r,int d,int x)
{
	if(~f[x].cov) return f[x].cov;
	int mid=(l+r)>>1;
	push_down(x);
	if(d<=mid) return query(l,mid,d,x<<1);
	else return query(mid+1,r,d,(x<<1)+1);
}
void cover(int nl,int nr,int l,int r,int x,int k)
{
	if(nr<l||r<nl) return ;
	if(l<=nl&&nr<=r)
	{
		f[x].tag=0,f[x].cov=k,f[x].mn=*lower_bound(s,s+13,k)-k;
		return ;
	}
	int mid=(nl+nr)>>1;
	push_down(x),
	cover(nl,mid,l,r,x<<1,k),
	cover(mid+1,nr,l,r,(x<<1)+1,k),
	f[x].mn=min(f[x<<1].mn,f[(x<<1)+1].mn);
	return ;
}
void update(int nl,int nr,int l,int r,int x,int k)
{
	if(nr<l||r<nl) return ;
	int mid=(nl+nr)>>1;
	if(l<=nl&&nr<=r)
	{
		if(~f[x].cov)
		{
			// printf("- %d %d\n",nl,nr);
			f[x].cov+=k,f[x].mn=*lower_bound(s,s+13,f[x].cov)-f[x].cov;
			return ;
		}
		else if(f[x].mn>=k)
		{
			// printf("%d %d\n",nl,nr);
			f[x].tag+=k,f[x].mn-=k;
			return ;
		}
		else
		{
			// printf("* %d %d\n",nl,nr);
			push_down(x),
			update(nl,mid,l,r,x<<1,k),
			update(mid+1,nr,l,r,(x<<1)+1,k),
			f[x].mn=min(f[x<<1].mn,f[(x<<1)+1].mn);
			return ;
		}
	}
	push_down(x),
	update(nl,mid,l,r,x<<1,k),
	update(mid+1,nr,l,r,(x<<1)+1,k),
	f[x].mn=min(f[x<<1].mn,f[(x<<1)+1].mn);
	return ;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	build(1,n,1);
	for(int op,x,y,k; m--;)
	{
		op=read();
		if(op==1) printf("%lld\n",query(1,n,read(),1));
		else if(op==2) x=read(),y=read(),k=read(),cover(1,n,x,y,1,k);
		else 
		{
			x=read(),y=read(),k=read();
			update(1,n,x,y,1,k);
			while(f[1].mn==0) update(1,n,x,y,1,k);
		}
	}
	
	return 0;
}