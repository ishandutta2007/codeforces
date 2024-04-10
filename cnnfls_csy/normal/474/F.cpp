#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,num[100005],l,r,cas;
struct seg
{
	struct nd
	{
		int l,r,mi,gcd,cnt;
	}tr[400005];
	void pushup(int x)
	{
		if (tr[x*2].mi==tr[x*2+1].mi)
		{
			tr[x].mi=tr[x*2].mi;
			tr[x].cnt=tr[x*2].cnt+tr[x*2+1].cnt;
		}
		if (tr[x*2].mi<tr[x*2+1].mi)
		{
			tr[x].mi=tr[x*2].mi;
			tr[x].cnt=tr[x*2].cnt;
		}
		if (tr[x*2].mi>tr[x*2+1].mi)
		{
			tr[x].mi=tr[x*2+1].mi;
			tr[x].cnt=tr[x*2+1].cnt;
		}
		tr[x].gcd=__gcd(tr[x*2].gcd,tr[x*2+1].gcd);
	}
	void build(int x,int l,int r)
	{
		tr[x].l=l;
		tr[x].r=r;
		if (l==r)
		{
			tr[x].mi=tr[x].gcd=num[l];
			tr[x].cnt=1;
			return;
		}
		build(x*2,l,(l+r)/2);
		build(x*2+1,(l+r)/2+1,r);
		pushup(x);
	}
	int querygcd(int x,int l,int r)
	{
		if (tr[x].l>r||tr[x].r<l) return 0;
		if (tr[x].l>=l&&tr[x].r<=r) return tr[x].gcd;
		return __gcd(querygcd(x*2,l,r),querygcd(x*2+1,l,r));
	}
	pair<int,int> querymin(int x,int l,int r)
	{
		if (tr[x].l>r||tr[x].r<l) return make_pair(0x7f222222,0);
		if (tr[x].l>=l&&tr[x].r<=r) return make_pair(tr[x].mi,tr[x].cnt);
		pair<int,int> ans1=querymin(x*2,l,r),ans2=querymin(x*2+1,l,r);
		if (ans1.first==ans2.first)
		{
			return make_pair(ans1.first,ans1.second+ans2.second);
		}
		if (ans1.first<ans2.first)
		{
			return make_pair(ans1.first,ans1.second);
		}
		if (ans1.first>ans2.first)
		{
			return make_pair(ans2.first,ans2.second);
		}
	}
}tr;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	//if (num[1]==325334250) printf("%d\n",num[19537]);
	tr.build(1,1,n);
	scanf("%d",&m);
	while (m--)
	{
		cas++;
		scanf("%d%d",&l,&r);
		/*if (l==r)
		{
			puts("0");
			continue;
		}*/
		pair<int,int> ans=tr.querymin(1,l,r);
		//if (num[1]==325334250&&cas==536) printf("%d,%d\n",ans.first,tr.querygcd(1,l,r));
		//cerr<<tr.querygcd(1,l,r)<<' '<<ans.first<<' '<<ans.second<<endl;
		if (ans.first!=tr.querygcd(1,l,r)) printf("%d\n",r-l+1); else printf("%d\n",r-l+1-ans.second);
	}
	return 0;
}