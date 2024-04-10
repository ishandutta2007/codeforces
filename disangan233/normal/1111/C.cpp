#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
ll ans,a[100005],n,m,A,B,bj;
inline ll qpow(re x,re y)
{
	re z=1;
	while(y)
	{
		if(y&1) z*=x;
		x*=x;y>>=1;
	}
	return z;
}
inline int check(re x)
{
	re l=1,r=m,ans=0;
	while(l<=r)
	{
		re mid=(l+r)>>1;
		if(a[mid]>x) r=mid-1;
		else ans=l,l=mid+1;
	}
	return ans;
}
inline ll dfs(re l,re beg,re end,re st)
{
	if(beg>end) return A;
	if(!l) return (end-beg+1)*1ll*B;
	re mm=st+(1<<(l-1)),kk=lower_bound(a+beg,a+end+1,mm)-a;
	return min((end-beg+1)*1ll*(1<<l)*B,dfs(l-1,kk,end,mm)+dfs(l-1,beg,kk-1,st));
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(re i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	cout<<dfs(n,1,m,1);
	return 0;
}