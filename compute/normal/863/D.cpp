#include<bits/stdc++.h>
using namespace std;
struct Treap{
	Treap *l,*r;
	int val,sz,prior;
	bool rev;
	Treap(int _val):l(NULL),r(NULL),val(_val),sz(1),prior(rand()),rev(false){}
};
typedef Treap* pt;
int size(pt cur)
{return cur?cur->sz:0;}
void update(pt cur)
{
	if(!cur) return;
	cur->sz=size(cur->l)+size(cur->r)+1;
}
void pushdown(pt cur)
{
	if(cur->rev)
	{
		swap(cur->l,cur->r);
		if(cur->l) cur->l->rev=!cur->l->rev;
		if(cur->r) cur->r->rev=!cur->r->rev;
		cur->rev=false;
	}
}
pt root=NULL;
void split(pt rt,int k,pt &l,pt&r)
{
	if(size(rt)==k)
	{
		l=rt,r=NULL;
		return ;
	}
	pushdown(rt);
	if(k<size(rt->l))
		split(rt->l,k,l,rt->l),r=rt;
	else if(k==size(rt->l))
		l=rt->l,r=rt,rt->l=NULL;
	else split(rt->r,k-size(rt->l)-1,rt->r,r),l=rt;
	update(rt);
}
void merge(pt &rt,pt l,pt r)
{
	if(!l||!r){rt=l?l:r;return ;}
	pushdown(l);
	pushdown(r);
	if(l->prior>r->prior) merge(l->r,l->r,r),rt=l;
	else merge(r->l,l,r->l),rt=r;
	update(rt);
}
void reverse(pt &rt,int st,int ed)
{
	pt l,r,mid;
	split(rt,st,l,mid);
	split(mid,ed-st,mid,r);
	mid->rev=!mid->rev;
	merge(mid,mid,r);
	merge(rt,l,mid);
}
void cycle(pt &rt,int st,int ed)
{
	pt l,mid,r,solo;
	split(rt,st,l,r);
	split(r,ed-st,mid,r);
	split(mid,ed-st-1,mid,solo);
	merge(l,l,solo);
	merge(l,l,mid);
	merge(rt,l,r);
}
int Find(pt rt,int pos)
{
	pushdown(rt);
	if(pos<size(rt->l)) return Find(rt->l,pos);
	else if(pos==size(rt->l)) return rt->val;
	else return Find(rt->r,pos-size(rt->l)-1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,m;
	cin>>n>>q>>m;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		merge(root,root,new Treap(temp));
	}
	int type,st,ed;
	while(q--)
	{
		cin>>type>>st>>ed;
		if(type==2)
			reverse(root,st-1,ed);
		else cycle(root,st-1,ed);
	}
	int tar;
	for(int i=0;i<m;i++)
	{
		cin>>tar;
		cout<<Find(root,tar-1)<<" ";
	}
	cout<<endl;
	
}