#include <cstdio>
typedef long long ll;
const int mo=(int)1e9+7;
const int N=(int)1e5+5;
int n,m,c[N],q[N];
ll ans;
inline ll power(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%mo) if(b&1) ans=ans*a%mo;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a; scanf("%d",&a);
		c[a]++;
	}
	for(int i=N-1;i;i--) 
		c[i-1]+=c[i];
	
	for(int i=1;c[i];i++)
	{
		m=0;
		int k;
		for(k=1;k*k<=i;k++) if(i%k==0) q[m++]=k;
		k--;
		if(k*k==i) k--;
		for(;k;k--) if(i%k==0) q[m++]=i/k;
		ll res=(power(m,c[i])-power(m-1,c[i]))%mo;
		for(int j=1;j<m;j++) res=res*power(j,c[q[j-1]]-c[q[j]])%mo;
		(ans+=res)%=mo;
	}
	printf("%I64d\n",(ans+mo)%mo);
}