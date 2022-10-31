
#include<bits/stdc++.h>
using namespace std;
long double ans;
typedef long long ll;
int n,p[100010];
inline int lowbit(int x)
{
	return x&(-x);
}
class tree
{
	public:
		ll dat[100010];
		void add(int p,ll v)
		{
			for(;p<=n;p+=lowbit(p))dat[p]+=v;
		}
		ll query(int p)
		{
			ll ret=0;
			for(;p;p-=lowbit(p))ret+=dat[p];
			return ret;
		}
}t1,t2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		ans+=(long double)i*(n-i)*(n-i+1)/(2ll*n*(n+1));
	for(int i=n;i>=1;i--)
	{
		ll x=t1.query(p[i]-1);
		ans-=(long double)(x*((2*i+2ll*n*i)-(1ll*n*n+n)))/(1ll*n*(n+1));
		ans+=(long double)(2*i)/(1ll*n*(n+1))*t2.query(p[i]-1);
		t1.add(p[i],1);
		t2.add(p[i],i);
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}