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
int n,m,i,j,rt[200005],x,y,z,l,r,mid,ans,cnt,len[200005],lst;
struct ii
{
	int id,hi;
}num[200005];
struct seg
{
	int l,r,lch,rch,pre,suf,len;
}tr[6000005];
void pushup(int x)
{
	tr[x].pre=tr[tr[x].lch].pre;
	if (tr[tr[x].lch].pre==tr[tr[x].lch].r-tr[tr[x].lch].l+1) tr[x].pre+=tr[tr[x].rch].pre;
	tr[x].suf=tr[tr[x].rch].suf;
	if (tr[tr[x].rch].suf==tr[tr[x].rch].r-tr[tr[x].rch].l+1) tr[x].suf+=tr[tr[x].lch].suf;
	tr[x].len=max(tr[tr[x].lch].len,tr[tr[x].rch].len);
	tr[x].len=max(tr[x].len,tr[tr[x].lch].suf+tr[tr[x].rch].pre);
}
void build(int x,int l,int r)
{
	if (l==r)
	{
		tr[x]={l,r,0,0,0,0,0};
		return;
	}
	tr[x]={l,r,0,0,0,0,0};
	tr[x].lch=++cnt;
	tr[x].rch=++cnt;
	build(tr[x].lch,l,(l+r)/2);
	build(tr[x].rch,(l+r)/2+1,r);
	pushup(x);
}
void update(int x,int y)
{
	if (y<tr[x].l||y>tr[x].r) return;
	if (tr[x].l==tr[x].r)
	{
		 tr[x]={tr[x].l,tr[x].r,0,0,1,1,1};
		 return;
	}
	tr[++cnt]=tr[tr[x].lch];
	tr[x].lch=cnt;
	tr[++cnt]=tr[tr[x].rch];
	tr[x].rch=cnt;
	update(tr[x].lch,y);
	update(tr[x].rch,y);
	pushup(x);
}
int query(int x,int l,int r)
{
	int ans=0;
	if (l>tr[x].r||r<tr[x].l) return 0;
	if (l<=tr[x].l&&r>=tr[x].r)
	{
		ans=max(ans,tr[x].len);
		lst+=tr[x].pre;
		ans=max(ans,lst);
		if (tr[x].len!=tr[x].r-tr[x].l+1)
		{
			lst=tr[x].suf;
			ans=max(ans,lst);
		}
	    //cout<<tr[x].l<<' '<<tr[x].r<<' '<<ans<<endl;
		return ans;
	}
	ans=query(tr[x].lch,l,r);
	ans=max(ans,query(tr[x].rch,l,r));
	return ans;
}
bool cmp(ii x,ii y)
{
	return x.hi>y.hi;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		num[i].id=i;
		scanf("%d",&num[i].hi);
	}
	sort(num+1,num+n+1,cmp);
	build(0,1,n); 
	rt[0]=0;
	for (i=1;i<=n;i++)
	{
		tr[rt[i]=++cnt]=tr[rt[i-1]];
		update(rt[i],num[i].id);
	}
/*	for (i=0;i<=cnt;i++)
	{
	    cout<<i<<":\n";
	    cout<<"l "<<tr[i].l<<endl;
	    cout<<"r "<<tr[i].r<<endl;
	    cout<<"lch "<<tr[i].lch<<endl;
	    cout<<"rch "<<tr[i].rch<<endl;
	    cout<<"pre "<<tr[i].pre<<endl;
	    cout<<"suf "<<tr[i].suf<<endl;
	    cout<<"len "<<tr[i].len<<endl;
	}*/
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		l=0;r=n+1;
		while (l<r)
		{
			mid=(l+r+1)/2;
			lst=0;
			//cout<<i<<' '<<mid<<' '<<query(rt[mid],x,y)<<endl;
			if (query(rt[mid],x,y)>=z)
			{
				r=mid-1;
				ans=mid;
			}
			else l=mid;
		}
		//cout<<ans<<endl;
		printf("%d\n",num[ans].hi);
	}
	return 0;
}