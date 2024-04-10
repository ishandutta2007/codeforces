#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,l[300005],r[300005],k[300005];
vector<int> all;
struct treedot
{
	int l,r,sl,sr;
	long long sum,del;
	void update(long long x)
	{
		del=x;
		sum=(sr-sl)*x;
	}
};
treedot c[2400005];
void pushdown(int id)
{
	if (c[id].del!=-1)
	{
		c[id*2].update(c[id].del);
		c[id*2+1].update(c[id].del);
		c[id].del=-1;
	}
}
void pushup(int id)
{
	c[id].sum=c[id*2].sum+c[id*2+1].sum;
}
void build(int id,int l,int r)
{
	c[id].l=l; 
	c[id].r=r;
	c[id].sl=all[l]; 
	c[id].sr=all[r+1];
	c[id].sum=0; 
	c[id].del=-1;
	if(l==r) c[id].sum=0;
	else
	{
		int mid=l+(r-l)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		pushup(id);
	}
}
void update(int id,int le,int ri,int x)
{
	if (le>c[id].r||ri<c[id].l) return;
	if (le<=c[id].l&&c[id].r<=ri)
	{
		c[id].update(x);
		return;
	}
	pushdown(id);
	update(id*2,le,ri,x);
	update(id*2+1,le,ri,x);
	pushup(id);
}
long long query(int id,int le,int ri)
{
	if (ri<c[id].l||c[id].r<le) return 0;
	if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;
	long long ans=0;
	pushdown(id);
	ans+=query(id*2,le,ri);
	ans+=query(id*2+1,le,ri);
	pushup(id);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l[i],&r[i],&k[i]);
		all.push_back(l[i]);
		all.push_back(r[i]+1);
	}
	all.push_back(1);
	all.push_back(n+1);
	vector<int> all2;
	sort(all.begin(),all.end());
	all2.push_back(0);
	all2.push_back(all[0]);
	for (i=1;i<all.size();i++) if (all[i]!=all[i-1]) all2.push_back(all[i]);
	all=all2;
	build(1,1,all.size()-2);
	update(1,1,all.size()-2,1);
	for (i=1;i<=m;i++)
	{
		update(1,upper_bound(all.begin(),all.end(),l[i])-all.begin()-1,upper_bound(all.begin(),all.end(),r[i]+1)-all.begin()-2,k[i]-1);
		printf("%d\n",query(1,1,all.size()-2));
	}
	return 0;
}