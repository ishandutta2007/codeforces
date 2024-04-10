#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int mod=998244353;
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
struct data
{
	int a,b,pf;
	friend data operator + (data a,data b)
	{
		data c;
		c.pf=1ll*a.pf*b.pf%mod;
		c.a=(a.a+1ll*b.a*a.pf)%mod;
		c.b=(a.b+1ll*b.b*a.pf)%mod;
		return c;
	}
}s[800080];
struct data1
{
	int a,b;
	friend data1 operator + (data1 a,data1 b)
	{
		data1 c;
		c.a=1ll*a.a*b.a%mod;
		c.b=(1ll*a.a*b.b+a.b)%mod;
		return c;
	}
}s1[800080];
int n,q,p[200020];
void build(int k,int l,int r)
{
	s1[k]=data1{1,0};
	if(l==r)
	{
		s[k]=data{mod+1-p[l],1,p[l]};
		return ;
	}
	build(k<<1,l,l+r>>1);
	build(k<<1|1,(l+r>>1)+1,r);
	s[k]=s[k<<1]+s[k<<1|1];
}
data query(int k,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)return s[k];
	if(ll>l+r>>1)return query(k<<1|1,(l+r>>1)+1,r,ll,rr);
	if(rr<=l+r>>1)return query(k<<1,l,l+r>>1,ll,rr);
	return query(k<<1,l,l+r>>1,ll,rr)+query(k<<1|1,(l+r>>1)+1,r,ll,rr);
}
void upd(int k,int l,int r,int p,int a,int b)
{
	if(l==r)
	{
		s1[k]=data1{a,b};
		return ;
	}
	if(p<=l+r>>1)upd(k<<1,l,l+r>>1,p,a,b);
	else upd(k<<1|1,(l+r>>1)+1,r,p,a,b);
	s1[k]=s1[k<<1]+s1[k<<1|1];
}
set<int>st;
void insert(int l,int r)
{
	data now=query(1,1,n,l,r);
//	printf("%d %d %d %d %d\n",l,r,now.a,now.pf,now.b);
	int inv=kpow(mod+1-now.a,mod-2);
	upd(1,1,n,l,1ll*now.pf*inv%mod,1ll*now.b*inv%mod);
}
void erase(int l,int r)
{
	upd(1,1,n,l,1,0);
}
int main()
{
	scanf("%d %d",&n,&q);
	int inv100=kpow(100,mod-2);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]),p[i]=1ll*p[i]*inv100%mod;
	build(1,1,n);
	insert(1,n);
	int x;
	st.insert(1);st.insert(n+1);
	while(q--)
	{
		scanf("%d",&x);
		if(*st.lower_bound(x)==x)
		{
			auto it=st.lower_bound(x);
			erase(x,*next(it)-1);
			erase(*prev(it),x-1);
			insert(*prev(it),*next(it)-1);
			st.erase(it);
		}
		else
		{
			auto it=st.insert(x).first;
			erase(*prev(it),*next(it)-1);
			insert(x,*next(it)-1);
			insert(*prev(it),x-1);
		}
		printf("%d\n",s1[1].b);
	}
	return 0;
}