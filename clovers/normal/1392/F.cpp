#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=1000010;

ll n,a[N],sum=0;
ll ans[N],add=0;

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	if(n==1)
	{
		printf("%lld\n",a[1]);
		return 0;
	}
	ll base=(n-1)*n/2;
	for(int i=1;i<=n;i++) a[i]=i-1;
	sum-=base;
	add=sum/n;
	for(int i=1;i<=n;i++) a[i]+=add;
	sum-=add*n;
	for(int i=1;i<=sum;i++) a[i]++;
	for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}