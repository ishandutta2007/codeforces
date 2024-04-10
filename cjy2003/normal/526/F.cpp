#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
pair<int,int> operator + (pair<int,int>&a,pair<int,int>&b)
{
	static pair<int,int>c;
	c.first=a.first<b.first?a.first:b.first;
	c.second=(a.first==c.first?a.second:0)+(b.first==c.first?b.second:0);
	return c;
}
int n,p[300030];
int st1[300030],tp1,st2[300030],tp2;
int mi[300030],cnt[300030],ad[1200020];
long long ans;
pair<int,int>s[1200020];
void build(int k,int l,int r)
{
	s[k]=make_pair(l,1);
	if(l==r)return ;
	build(k<<1,l,l+r>>1),build(k<<1|1,(l+r>>1)+1,r);
}
inline void pushdown(int k)
{
	ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
	s[k<<1].first+=ad[k],s[k<<1|1].first+=ad[k];
	ad[k]=0;
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		s[k].first+=w;
		ad[k]+=w;
		return ;
	}
	if(ad[k])pushdown(k);
	add(k<<1,l,l+r>>1,ll,rr,w);
	add(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	s[k]=s[k<<1]+s[k<<1|1];
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&x,&y);
		p[x]=y;
	}
	build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		++ad[1],++s[1].first;
		while(tp1&&p[i]>p[st1[tp1]])add(1,1,n,st1[tp1-1]+1,st1[tp1],p[i]-p[st1[tp1]]),--tp1;
		while(tp2&&p[i]<p[st2[tp2]])add(1,1,n,st2[tp2-1]+1,st2[tp2],p[st2[tp2]]-p[i]),--tp2;
		st1[++tp1]=i;st2[++tp2]=i;
		ans+=s[1].second;
	}
	printf("%lld",ans);
	return 0;
}