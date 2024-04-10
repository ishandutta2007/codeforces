#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct node
{
	int l,r,flip,full,empty;
}st[10000010];
int n,opt[100010],tot,root;
long long l[100010],r[100010],b[200010];
void cover(int &p,int le,int ri,int opt)
{
	if(!p)
	{
		p=++tot;
		st[p].empty=1;
	}
	if(st[p].flip&&le<ri&&opt==3)
	{
		cover(st[p].l,le,(le+ri)>>1,st[p].flip);
		cover(st[p].r,((le+ri)>>1)+1,ri,st[p].flip);
		st[p].flip=0;
	}
	st[p].flip=opt;
	if(opt==1)
	{
		st[p].full=1;
		st[p].empty=0;
	}
	else if(opt==2)
	{
		st[p].full=0;
		st[p].empty=1;
	}
	else swap(st[p].full,st[p].empty);
}
void maintain(int p)
{
	st[p].full=st[st[p].l].full&&st[st[p].r].full;
	st[p].empty=st[st[p].l].empty&&st[st[p].r].empty;
}
void modify(int &p,int le,int ri,int ll,int rr,int opt)
{
	if(!p)
	{
		p=++tot;
		st[p].empty=1;
	}
	if(le==ll&&ri==rr)
	{
		cover(p,le,ri,opt);
		return;
	}
	long long mid=(le+ri)>>1;
	if(st[p].flip)
	{
		cover(st[p].l,le,mid,st[p].flip);
		cover(st[p].r,mid+1,ri,st[p].flip);
		st[p].flip=0;
	}
	if(rr<=mid)modify(st[p].l,le,mid,ll,rr,opt);
	else if(ll>mid)modify(st[p].r,mid+1,ri,ll,rr,opt);
	else
	{
		modify(st[p].l,le,mid,ll,mid,opt);
		modify(st[p].r,mid+1,ri,mid+1,rr,opt);
	}
	maintain(p);
}
int query(int p,int le,int ri)
{
	if(!p)return le;
	if(le==ri)return le;
	long long mid=(le+ri)>>1;
	if(st[p].flip)
	{
		cover(st[p].l,le,mid,st[p].flip);
		cover(st[p].r,mid+1,ri,st[p].flip);
		st[p].flip=0;
	}
	if(st[st[p].l].full)return query(st[p].r,mid+1,ri);
	else return query(st[p].l,le,mid);
	maintain(p);
}
int main()
{
	st[0].empty=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%I64d%I64d",&opt[i],&l[i],&r[i]);
		r[i]++;
		b[2*i]=l[i];
		b[2*i+1]=r[i];
	}
	b[1]=1;
	sort(b+1,b+2*n+2);
	for(int i=1;i<=n;i++)
	{
		int ll=lower_bound(b+1,b+2*n+1,l[i])-b,rr=lower_bound(b+1,b+2*n+1,r[i])-b;
		modify(root,1,2*n+1,ll,rr-1,opt[i]);
		printf("%I64d\n",b[query(root,1,2*n+1)]);
	}
	return 0;
}