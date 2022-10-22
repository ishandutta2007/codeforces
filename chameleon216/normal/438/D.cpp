#include <cstdio> //test
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=100100;

int N,M;

struct SegmentTree
{
	ll v;
	int w;
}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
inline void PushUp(int i)
{
	T[i].v=T[li].v+T[ri].v;
	T[i].w=max(T[li].w,T[ri].w);
}
void Build(int i,int l,int r)
{
	if(l==r)
	{
		scanf("%d",&T[i].w),T[i].v=T[i].w;
		return;
	}
	Build(li,l,mid);
	Build(ri,mid+1,r);
	PushUp(i);
}
void Modify(int i,int l,int r,int a,int b,int x)
{
	if(T[i].w<x)return;
	if(l==r){T[i].w=T[i].v%=x;return;}
	if(a<=mid)Modify(li,l,mid,a,b,x);
	if(b>mid)Modify(ri,mid+1,r,a,b,x);
	PushUp(i);
}
void Change(int i,int l,int r,int a,int x)
{
	if(l==r){T[i].w=T[i].v=x;return;}
	if(a<=mid)Change(li,l,mid,a,x);
	else Change(ri,mid+1,r,a,x);
	PushUp(i);
}
ll Ask(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return T[i].v;
	ll res=0;
	if(a<=mid)res+=Ask(li,l,mid,a,b);
	if(b>mid)res+=Ask(ri,mid+1,r,a,b);
	return res;
}


int main()
{
	scanf("%d%d",&N,&M);
	Build(1,1,N);
	int o,l,r,x;
	Fr(i,1,M)
	{
		scanf("%d",&o);
		if(o==1)scanf("%d%d",&l,&r),printf("%lld\n",Ask(1,1,N,l,r));
		else if(o==2)scanf("%d%d%d",&l,&r,&x),Modify(1,1,N,l,r,x);
		else scanf("%d%d",&l,&x),Change(1,1,N,l,x);
	}
	return 0;
}