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
struct ii
{
	int l,r,t,id,op,ans;
}qu[200005];
int n,m,i,j,tr[800005],id[800005];
vector<int> all;
bool cmp(ii x,ii y)
{
	if (x.l<y.l) return 1;
	if (x.l>y.l) return 0;
	if (x.t>y.t) return 1;
	if (x.t<y.t) return 0;
	return x.op<y.op;
}
bool cmp2(ii x,ii y)
{
	return x.id<y.id;
}
void pushup(int x)
{
	tr[x]=max(tr[x*2],tr[x*2+1]);
}
void insert(int x,int qr,int qid)
{
	x+=262143;
	//cerr<<x<<endl;
	tr[x]=qr;
	id[x]=qid;
	x/=2;
	while (x)
	{
		pushup(x);
		x/=2;
	}
}
int query(int x,int l,int r,int qt,int qr)
{
	if (tr[x]<qr) return -1;
	if (l==r) return id[x];
	int ans=-1;
	if ((l+r)/2>=qt) ans=query(x*2,l,(l+r)/2,qt,qr);
	if (ans==-1) ans=query(x*2+1,(l+r)/2+1,r,qt,qr);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&qu[i].l,&qu[i].r,&qu[i].t);
		all.push_back(qu[i].t);
		qu[i].id=i;
		qu[i].op=1;
	}
	for (i=n+1;i<=n+m;i++)
	{
		scanf("%d%d%d",&qu[i].l,&qu[i].r,&qu[i].t);
		all.push_back(qu[i].t);
		qu[i].id=i;
		qu[i].op=2;
	}
	sort(all.begin(),all.end());
	if (!all.empty())
	{
		vector<int> all2;
		all2.push_back(all[0]);
		for (int i=1;i<all.size();i++) if (all[i]!=all[i-1]) all2.push_back(all[i]);
		all=all2;
	}
	//for (i=0;i<all.size();i++) cerr<<all[i]<<' ';cerr<<endl;
	sort(qu+1,qu+n+m+1,cmp);
	for (i=1;i<=n+m;i++)
	{
		//cerr<<upper_bound(all.begin(),all.end(),qu[i].t)-all.begin()<<endl;
		if (qu[i].op==1)
		{
			insert(upper_bound(all.begin(),all.end(),qu[i].t)-all.begin(),qu[i].r,qu[i].id);
		}
		else
		{
			qu[i].ans=query(1,1,262144,upper_bound(all.begin(),all.end(),qu[i].t)-all.begin(),qu[i].r);
		}
	}
	sort(qu+1,qu+n+m+1,cmp2);
	for (i=n+1;i<=n+m;i++) printf("%d ",qu[i].ans);
	return 0;
}