#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define G 12
#define L (k<<1)
#define R (k<<1|1)
struct node{ll x,z,mk;}t[MN*4+5];
ll pw[G+5],a[MN+5];
ll cal(ll x)
{
	int l=1,r=G,mid,res;
	while(l<=r)if(pw[mid=l+r>>1]<x)l=mid+1;else res=mid,r=mid-1;
	return pw[res]-x;
}
void up(int k)
{
	t[k].x=min(t[L].x,t[R].x);
	t[k].z=t[L].z==t[R].z?t[L].z:0;
}
void change(int k,ll x)
{
	t[k].x=cal(t[k].z=x);
	t[k].mk=0;
}
void add(int k,ll x)
{
	t[k].x-=x;
	if(t[k].z)t[k].z+=x;else t[k].mk+=x;
}
void down(int k)
{
	if(t[k].mk)add(L,t[k].mk),add(R,t[k].mk),t[k].mk=0;
	if(t[k].z)change(L,t[k].z),change(R,t[k].z);
}
void build(int k,int l,int r)
{
	if(l==r){t[k].x=cal(t[k].z=a[l]);return;}
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);up(k);
}
void change(int k,int l,int r,int ql,int qr,int x)
{
	if(l==ql&&r==qr){change(k,x);return;}
	int mid=l+r>>1;down(k);
	if(qr<=mid)change(L,l,mid,ql,qr,x);
	else if(ql>mid)change(R,mid+1,r,ql,qr,x);
	else change(L,l,mid,ql,mid,x),change(R,mid+1,r,mid+1,qr,x);
	up(k);
}
void solve(int k)
{
	if(t[k].x>=0)return;
	if(t[k].z){t[k].x=cal(t[k].z);return;}
	down(k);solve(L);solve(R);up(k);
}
void add(int k,int l,int r,int ql,int qr,int x)
{
	if(l==ql&&r==qr){add(k,x);solve(k);return;}
	int mid=l+r>>1;down(k);
	if(qr<=mid)add(L,l,mid,ql,qr,x);
	else if(ql>mid)add(R,mid+1,r,ql,qr,x);
	else add(L,l,mid,ql,mid,x),add(R,mid+1,r,mid+1,qr,x);
	up(k);
}
ll query(int k,int l,int r,int x)
{
	if(t[k].z)return t[k].z;
	int mid=l+r>>1;down(k);
	return x>mid?query(R,mid+1,r,x):query(L,l,mid,x);
} 
int main()
{
	int n,q,i,o,l,r,x;
	n=read();q=read();
	for(pw[0]=i=1;i<=G;++i)pw[i]=pw[i-1]*42;
	for(i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	while(q--)
	{
		o=read();l=read();
		if(o==1)printf("%I64d\n",query(1,1,n,l));
		else r=read(),x=read();
		if(o==2)change(1,1,n,l,r,x);
		if(o==3)do add(1,1,n,l,r,x);while(!t[1].x);
	}
}