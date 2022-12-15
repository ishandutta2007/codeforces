#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

const int maxn=100005;

int n;
ll a[maxn];

ll pre[maxn],suf[maxn];

ll gcd(ll x, ll y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

ll ga,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	pre[1]=a[1]; suf[n]=a[n];
	for(int i=2;i<=n;i++)
		pre[i]=gcd(pre[i-1],a[i]);
	for(int i=n-1;i>=1;i--)
		suf[i]=gcd(suf[i+1],a[i]);
	for(int i=0;i<=n-1;i++)
	{
		if(i==0)
			ans=suf[2];
		else if(i==n-1)
			ans=ans*pre[n-1]/gcd(pre[n-1],ans);
		else
			ans=ans*gcd(pre[i],suf[i+2])/gcd(gcd(pre[i],suf[i+2]),ans);
	}
	printf("%lld\n",ans);
	return 0;
}