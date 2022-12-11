#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,p[300030],q[300030],pos[300030];
int ad[1200020];
pair<int,int>mi[1200020];
set<int>s;
void build(int k,int l,int r)
{
	if(l==r)
	{
		mi[k]=make_pair(0,l);
		return;
	}
	build(k<<1,l,l+r>>1);
	build(k<<1|1,(l+r>>1)+1,r);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
}
int pushdown(int k)
{
	ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
	mi[k<<1].first+=ad[k],mi[k<<1|1].first+=ad[k];
	ad[k]=0;
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return;
	if(l>=ll&&r<=rr)
	{
		mi[k].first+=w,ad[k]+=w;
		return;
	}
	if(ad[k])pushdown(k);
	add(k<<1,l,l+r>>1,ll,rr,w);
	add(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
}
pair<int,int>query(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return make_pair(n+1,0);
	if(l>=ll&&r<=rr)return mi[k];
	if(ad[k])pushdown(k);
	return min(query(k<<1,l,l+r>>1,ll,rr),query(k<<1|1,(l+r>>1)+1,r,ll,rr));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=1;i<=n;++i)scanf("%d",&q[i]);
	build(1,1,n);
	printf("%d ",n);
	for(int i=1,last=n;i<n;++i)
	{
		add(1,1,n,q[i],n,-1);
		if(mi[1].first<0)
		{
			s.insert(mi[1].second);
			add(1,1,n,mi[1].second,n,1);
		}
		while(s.lower_bound(pos[last])!=s.end())
		{
			int p=*s.lower_bound(pos[last]);
			s.erase(p);
			add(1,1,n,pos[last],p-1,1);
			--last;
		}
		printf("%d ",last);
	}
	return 0;
}