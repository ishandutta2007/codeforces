#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<set>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,s[MAXN],m[MAXN],r[MAXN],t[MAXN],num[MAXN],cnt,root[MAXN],pcnt;
struct seg_tree
{
	int l,r;
	ll maxn,val;
}tree[MAXN*21];
#define ls(x) (tree[x].l)
#define rs(x) (tree[x].r)
void up(int x)
{
	tree[x].maxn=tree[ls(x)].maxn+tree[rs(x)].maxn;
	tree[x].val=tree[ls(x)].val+tree[rs(x)].val;
}
void xg(int l,int r,int zone,int vm,int vr,int pre,int &x)
{
	x=++pcnt;
	if(l==r)
	{
		tree[x].maxn=tree[pre].maxn+vm;
		tree[x].val=tree[pre].val+vr;
		return;
	}
	int mid=(l+r)>>1;
	if(zone<=mid)
	{
		tree[x].r=rs(pre);
		xg(l,mid,zone,vm,vr,ls(pre),ls(x));
	}
	else
	{
		tree[x].l=ls(pre);
		xg(mid+1,r,zone,vm,vr,rs(pre),rs(x));
	}
	up(x);
}
ll cx_maxn(int l,int r,int L,int R,int pre,int x)
{
	if(L<=l && r<=R) return tree[x].maxn-tree[pre].maxn;
	int mid=(l+r)>>1;
	ll bck=0;
	if(L<=mid) bck=cx_maxn(l,mid,L,R,ls(pre),ls(x));
	if(mid<R) bck+=cx_maxn(mid+1,r,L,R,rs(pre),rs(x));
	return bck;
}
ll cx_val(int l,int r,int L,int R,int pre,int x)
{
	if(L<=l && r<=R) return tree[x].val-tree[pre].val;
	int mid=(l+r)>>1;
	ll bck=0;
	if(L<=mid) bck=cx_val(l,mid,L,R,ls(pre),ls(x));
	if(mid<R) bck+=cx_val(mid+1,r,L,R,rs(pre),rs(x));
	return bck;
}
struct data
{
	int l,r,st;
	data(int _l=0,int _r=0,int _st=0) {l=_l,r=_r,st=_st;}
	bool operator <(const data &Z)const {return l<Z.l || (l==Z.l && r<Z.r);}
};
set<data> T;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		s[i]=read(),m[i]=read(),r[i]=read();
		if(r[i]) num[i]=t[i]=(m[i]?(m[i]-1)/r[i]+1:0);
		else num[i]=t[i]=1e9+10;
	}
	num[n+1]=1e9+10;
	sort(num+1,num+n+2);
	cnt=unique(num+1,num+n+2)-num-1;
	for(int i=1;i<=n;++i)
	{
		t[i]=lower_bound(num+1,num+cnt+1,t[i])-num;
		xg(1,cnt,t[i],m[i],r[i],root[i-1],root[i]);
	}
	for(int i=1;i<=n;++i) T.insert(data(i,i,-1));
	q=read();
	while(q--)
	{
		int tim=read(),L=read(),R=read();
		ll ans=0;
		set<data> :: iterator id=T.lower_bound(data(L+1,0,0));
		--id;
		while(id->l<=R && id!=T.end())
		{
			data u=*id;
			//cout<<id->l<<" "<<id->r<<" "<<id->st<<endl;
			++id;
			T.erase(u);
			if(L<=u.l && u.r<=R)
			{
				if(u.st==-1) ans+=min((ll)m[u.l],s[u.l]+(ll)tim*r[u.l]);
				else
				{
					int lim=upper_bound(num+1,num+cnt+1,tim-u.st)-num;
					if(lim!=1) ans+=cx_maxn(1,cnt,1,lim-1,root[u.l-1],root[u.r]);
					ans+=cx_val(1,cnt,lim,cnt,root[u.l-1],root[u.r])*(tim-u.st);
				}
			}
			else if(u.l<L && R<u.r)
			{
				T.insert(data(u.l,L-1,u.st));
				T.insert(data(R+1,u.r,u.st));
				int lim=upper_bound(num+1,num+cnt+1,tim-u.st)-num;
				if(lim!=1) ans+=cx_maxn(1,cnt,1,lim-1,root[L-1],root[R]);
				ans+=cx_val(1,cnt,lim,cnt,root[L-1],root[R])*(tim-u.st);
			}
			else if(u.l<L)
			{
				T.insert(data(u.l,L-1,u.st));
				int lim=upper_bound(num+1,num+cnt+1,tim-u.st)-num;
				if(lim!=1) ans+=cx_maxn(1,cnt,1,lim-1,root[L-1],root[u.r]);
				ans+=cx_val(1,cnt,lim,cnt,root[L-1],root[u.r])*(tim-u.st);
			}
			else
			{
				T.insert(data(R+1,u.r,u.st));
				int lim=upper_bound(num+1,num+cnt+1,tim-u.st)-num;
				if(lim!=1) ans+=cx_maxn(1,cnt,1,lim-1,root[u.l-1],root[R]);
				ans+=cx_val(1,cnt,lim,cnt,root[u.l-1],root[R])*(tim-u.st);
			}
		}
		T.insert(data(L,R,tim));
		printf("%lld\n",ans);
	}
	return 0;
}
//ore no turn,draw!