#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
#define ND 2000000
vector<int> v[MN+5];
int a[MN+5],rt[MN+5],tn;
struct node{int l,r,s;}t[ND+5];
int add(int k,int l,int r,int x)
{
	int p=++tn,mid=l+r>>1;
	t[p].s=t[k].s+1;
	if(l==r)return p;
	if(x<=mid)t[p].l=add(t[k].l,l,mid,x),t[p].r=t[k].r;
	else t[p].l=t[k].l,t[p].r=add(t[k].r,mid+1,r,x);
	return p;
}
int query(int k,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)return t[k].s;
	int mid=l+r>>1;
	if(qr<=mid)return query(t[k].l,l,mid,ql,qr);
	if(ql>mid)return query(t[k].r,mid+1,r,ql,qr);
	return query(t[k].l,l,mid,ql,mid)+query(t[k].r,mid+1,r,mid+1,qr);
}
int main()
{
	int n,k,i,l,r,ls=0;
	n=read();k=read();
	for(i=1;i<=n;++i)
	{
		rt[i]=rt[i-1];
		v[a[i]=read()].push_back(i);
		if(v[a[i]].size()>k)rt[i]=add(rt[i],1,n,v[a[i]][v[a[i]].size()-1-k]);
	}
	for(i=read();i--;)
	{
		l=(read()+ls)%n+1;r=(read()+ls)%n+1;
		if(l>r)swap(l,r);
		printf("%d\n",ls=(r-l+1-query(rt[r],1,n,l,r)+query(rt[l-1],1,n,l,r)));
	}
}