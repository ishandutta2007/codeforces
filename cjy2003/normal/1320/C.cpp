#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
pair<int,int>a[200020];
pair<int,int>b[200020];
pair<pair<int,int>,int>c[200020];
int n,m,p,ans=-2000000000;
int mx[800080],ad[800080];
void build(int k,int l,int r)
{
	if(l==r)return mx[k]=-b[l].second,void();
	build(k<<1,l,l+r>>1);build(k<<1|1,(l+r>>1)+1,r);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
inline void pushdown(int k)
{
	ad[k<<1]+=ad[k];ad[k<<1|1]+=ad[k];
	mx[k<<1]+=ad[k];mx[k<<1|1]+=ad[k];
	ad[k]=0;
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		mx[k]+=w;
		ad[k]+=w;
		return;
	}
	if(ad[k])pushdown(k);
	add(k<<1,l,l+r>>1,ll,rr,w);
	add(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
int main()
{
	scanf("%d %d %d",&n,&m,&p);
	for(int i=1;i<=n;++i)scanf("%d %d",&a[i].first,&a[i].second);
	for(int i=1;i<=m;++i)scanf("%d %d",&b[i].first,&b[i].second);
	for(int i=1;i<=p;++i)scanf("%d %d %d",&c[i].first.first,&c[i].first.second,&c[i].second);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	sort(c+1,c+1+p);
	build(1,1,m);
//	printf("!!!");
	for(int i=1,last=1;i<=n;++i)
	{
		while(last<=p&&c[last].first.first<a[i].first)
		{
			int x=lower_bound(b+1,b+1+m,make_pair(c[last].first.second+1,0))-b;
			if(x<=m)add(1,1,m,x,m,c[last].second);
			++last;
		}
		ans=max(ans,-a[i].second+mx[1]);
	}
	printf("%d",ans);
	return 0;
}