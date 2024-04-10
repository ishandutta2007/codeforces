#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
long long k;
int n,m,mod,s[50050];
map<long long,pair<int,int> >mp;
struct matrix
{
	int a[2][2];
	friend matrix operator *(matrix a,matrix b)
	{
		static matrix c;
		c.a[0][0]=(1ll*a.a[0][0]*b.a[0][0]+1ll*a.a[0][1]*b.a[1][0])%mod;
		c.a[0][1]=(1ll*a.a[0][0]*b.a[0][1]+1ll*a.a[0][1]*b.a[1][1])%mod;
		c.a[1][0]=(1ll*a.a[1][0]*b.a[0][0]+1ll*a.a[1][1]*b.a[1][0])%mod;
		c.a[1][1]=(1ll*a.a[1][0]*b.a[0][1]+1ll*a.a[1][1]*b.a[1][1])%mod;
		return c;
	}
}I,t[50050],pre[50050],suf[50050],ans,cur,res[200020];
void build(int k,int l,int r)
{
	if(l==r)return res[k]=t[l],void();
	build(k<<1,l,l+r>>1),build(k<<1|1,(l+r>>1)+1,r);
	res[k]=res[k<<1]*res[k<<1|1];
}
matrix query(int k,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)return res[k];
	if(rr<=l+r>>1)return query(k<<1,l,l+r>>1,ll,rr);
	if(ll>l+r>>1)return query(k<<1|1,(l+r>>1)+1,r,ll,rr);
	return query(k<<1,l,l+r>>1,ll,rr)*query(k<<1|1,(l+r>>1)+1,r,ll,rr);
}
matrix kpow(matrix a,long long b)
{
	matrix ret=I;
	for(;b;b>>=1,a=a*a)
		if(b&1)ret=ret*a;
	return ret;
}
int main()
{
	I.a[0][0]=I.a[1][1]=1;
	scanf("%lld %d %d",&k,&mod,&n);
	if(k<=1){printf("%d",k%mod);return 0;}
	for(int i=0;i<n;++i)scanf("%d",&s[i]);
	for(int i=2;i<=n;++i)t[i].a[0][0]=s[i-1],t[i].a[1][0]=s[i-2],t[i].a[0][1]=1;
	t[1].a[0][0]=s[0],t[1].a[1][0]=s[n-1],t[1].a[0][1]=1;
	build(1,1,n);
	pre[0]=suf[n+1]=I;
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]*t[i];
	for(int i=n;i;--i)suf[i]=t[i]*suf[i+1];
	scanf("%d",&m);
	long long p;int w;
	for(int i=1;i<=m;++i)
	{
		scanf("%lld %d",&p,&w);
		mp[p+1].first=w;
		mp[p+2].second=w;
	}
	long long l=2,r;
	ans=I;
	for(auto x:mp)
	{
		if(x.first>k)break;
		if(!x.second.first)x.second.first=s[(x.first-1)%n];
		if(!x.second.second)x.second.second=s[(x.first-2)%n];
		if(x.first!=l)
		{
			r=x.first-1;
			if((l-1)/n==(r-1)/n)ans=ans*query(1,1,n,(l-1)%n+1,(r-1)%n+1);
			else
			{
				ans=ans*suf[(l-1)%n+1];
				ans=ans*kpow(pre[n],(r-1)/n-(l-1)/n-1);
				ans=ans*pre[(r-1)%n+1];
			}
		}
		cur.a[0][0]=x.second.first;
		cur.a[1][0]=x.second.second;
		cur.a[0][1]=1,cur.a[1][1]=0;
		ans=ans*cur;
		l=x.first+1;
	}
	if(l<=k)
	{
		if((l-1)/n==(k-1)/n)ans=ans*query(1,1,n,(l-1)%n+1,(k-1)%n+1);
		else
		{
			ans=ans*suf[(l-1)%n+1];
			ans=ans*kpow(pre[n],(k-1)/n-(l-1)/n-1);
			ans=ans*pre[(k-1)%n+1];
		}		
	}
	printf("%d",ans.a[0][0]);
	return 0;
}