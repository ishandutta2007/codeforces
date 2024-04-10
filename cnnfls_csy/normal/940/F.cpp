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
int n,m,i,j,cnt[200005],cnt2[200005],op,x,y,num[100005],now[100005],mx,l=1,r,ti;
vector<int> all;
struct query
{
	int l,r,ti,id,ans;
	long long f;
};
vector<query> qu;
struct upd
{
	int x,fr,to;
};
vector<upd> up;
bool cmp(query x,query y)
{
	return x.f<y.f;
}
bool cmp2(query x,query y)
{
	return x.id<y.id;
}
struct bit
{
	int sum[200005];
	void add(int x,int y)
	{
		if (x<=0) return;
		int i;
		for (i=x;i<=mx;i+=(i&(-i)))
		{
			sum[i]+=y;
		}
	}
	int query()
	{
		int i,ans=0;
		for (i=12;i>=0;i--)
		{
			if (ans+(1<<i)<=mx&&sum[ans+(1<<i)]==(1<<i)) ans+=(1<<i);
		}
		return ans;
	}
}cntofcnt;
void inc(int x)
{
	cnt2[x]++;
	if (cnt2[x]==1) cntofcnt.add(x,1);
}
void dec(int x)
{
	if (cnt2[x]==1) cntofcnt.add(x,-1);
	cnt2[x]--;
}
int main()
{
	scanf("%d%d",&n,&m);
	mx=sqrt(n)*2+5;
	for (i=1;i<=n;i++)
	{
		scanf("%d",num+i);
		all.push_back(num[i]);
		now[i]=num[i];
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&x,&y);
		if (op==1)
		{
			qu.push_back({x,y,up.size(),i,0,x/2154ll*2154ll*2154ll*2154ll+y/2154ll*2154ll*2154ll+up.size()});
		}
		if (op==2)
		{
			up.push_back({x,now[x],y});
			all.push_back(y);
			now[x]=y;
		}
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for (i=1;i<=n;i++)
	{
		num[i]=now[i]=upper_bound(all.begin(),all.end(),num[i])-all.begin();
	}
	for (i=0;i<up.size();i++)
	{
		up[i].fr=upper_bound(all.begin(),all.end(),up[i].fr)-all.begin();
		up[i].to=upper_bound(all.begin(),all.end(),up[i].to)-all.begin();
	}
	sort(qu.begin(),qu.end(),cmp);
	for (i=0;i<qu.size();i++)
	{
		while (l>qu[i].l)
		{
			l--;
			dec(cnt[now[l]]);
			cnt[now[l]]++;
			inc(cnt[now[l]]);
		}
		while (r<qu[i].r)
		{
			r++;
			dec(cnt[now[r]]);
			cnt[now[r]]++;
			inc(cnt[now[r]]);
		}
		while (l<qu[i].l)
		{
			dec(cnt[now[l]]);
			cnt[now[l]]--;
			inc(cnt[now[l]]);
			l++;
		}
		while (r>qu[i].r)
		{
			dec(cnt[now[r]]);
			cnt[now[r]]--;
			inc(cnt[now[r]]);
			r--;
		}
		while (ti<qu[i].ti)
		{
			if (up[ti].x>=l&&up[ti].x<=r)
			{
				dec(cnt[up[ti].fr]);
				cnt[up[ti].fr]--;
				inc(cnt[up[ti].fr]);
				dec(cnt[up[ti].to]);
				cnt[up[ti].to]++;
				inc(cnt[up[ti].to]);
			}
			now[up[ti].x]=up[ti].to;
			ti++;
		}
		while (ti>qu[i].ti)
		{
			ti--;
			if (up[ti].x>=l&&up[ti].x<=r)
			{
				dec(cnt[up[ti].fr]);
				cnt[up[ti].fr]++;
				inc(cnt[up[ti].fr]);
				dec(cnt[up[ti].to]);
				cnt[up[ti].to]--;
				inc(cnt[up[ti].to]);
			}
			now[up[ti].x]=up[ti].fr;
		}
		qu[i].ans=cntofcnt.query();
	}
	sort(qu.begin(),qu.end(),cmp2);
	for (i=0;i<qu.size();i++) printf("%d\n",qu[i].ans+1);
	return 0;
}