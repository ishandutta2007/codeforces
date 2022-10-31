#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct Sgt{
	long long sum,mx;
};
Sgt seg[maxn*4];
void pushup(int rt)
{
	seg[rt].sum=seg[rt*2].sum+seg[rt*2+1].sum;
	seg[rt].mx=max(seg[rt*2].mx,seg[rt*2+1].mx);
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%lld",&seg[rt].sum);
		seg[rt].mx=seg[rt].sum;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}
long long query(int l,int r,int L,int R,int rt)
{
	if(l<=L&&r>=R)
	{
		return seg[rt].sum;
	}
	int mid=L+R>>1;
	long long ret=0;
	if(l<=mid) ret+=query(l,r,L,mid,rt*2);
	if(r>mid) ret+=query(l,r,mid+1,R,rt*2+1);
	return ret;
}
void update(int p,int val,int L,int R,int rt)
{
	if(L==R)
	{
		seg[rt].sum=val;
		seg[rt].mx=val;
		return;
	}
	int mid=L+R>>1;
	if(p<=mid) update(p,val,L,mid,rt*2);
	else update(p,val,mid+1,R,rt*2+1);
	pushup(rt);
}
void mod(int l,int r,int p,int L,int R,int rt)
{
	if(seg[rt].mx<p) return;
	if(l<=L&&r>=R&&L==R)
	{
		seg[rt].sum%=p;
		seg[rt].mx%=p;
		return;
	}
	int mid=L+R>>1;
	if(l<=mid) mod(l,r,p,L,mid,rt*2);
	if(r>mid) mod(l,r,p,mid+1,R,rt*2+1);
	pushup(rt);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r,1,n,1));
		}
		else if(op==2)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			mod(l,r,x,1,n,1);
		}
		else{
			int k,x;
			scanf("%d%d",&k,&x);
			update(k,x,1,n,1);
		}
	}
}