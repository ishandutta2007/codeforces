#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct lsh
{
	long long va;
	int id;
}d[300060];
struct ret
{
	long long b;
	int a;
}a1,a2;
int n,m,c[300030],jl,tot[300030],x,y;
long long sum[2][300030],wx[300030],wy[300030],ans[300030];
inline bool cmp(lsh a,lsh b)
{
	return a.va<b.va;
}
inline long long mini(long long a,long long b)
{
	if(a<b)return a;
	return b;
}
inline void change(int p,long long vax,long long vay)
{
	while(p<=jl)
	{
		++tot[p];
		sum[0][p]+=vax;
		sum[1][p]+=vay;	
		p+=p&-p;
	}
}
inline ret query(int p,int f)
{
	ret s;
	s.a=s.b=0;
	while(p)
	{
		s.a+=tot[p];
		s.b+=sum[f][p];	
		p-=p&-p;
	}
	return s;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d %I64d",&wx[i],&wy[i]);
		d[i].va=wx[i]-wy[i];
		d[i].id=i;	
	}
	sort(d+1,d+1+n,cmp);
	d[0].va=-1e18;
	for(int i=1;i<=n;++i)
	{
		if(d[i].va!=d[i-1].va)++jl;	
		c[d[i].id]=jl;
	}
	while(m--)
	{
		scanf("%d %d",&x,&y);
		ans[x]-=mini(wx[x]+wy[y],wx[y]+wy[x]);
		ans[y]-=mini(wx[x]+wy[y],wx[y]+wy[x]);
	}
	for(int i=1;i<=n;++i)
		change(c[i],wx[i],wy[i]);
	for(int i=1;i<=n;++i)
	{
		a1=query(c[i],0);
		--a1.a;
		a1.b-=wx[i];	
		ans[i]+=1ll*a1.a*wy[i]+a1.b;
		a1=query(jl,1);
		a2=query(c[i],1);
		ans[i]+=1ll*(a1.a-a2.a)*wx[i]+a1.b-a2.b;
		printf("%I64d ",ans[i]);
	}
	return 0;
}