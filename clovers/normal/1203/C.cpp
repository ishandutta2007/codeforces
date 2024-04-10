#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=400010;

int n;
ll a[N];

ll gcd(ll x,ll y)
{
	if(x<y) swap(x,y);
	if(y==0) return x;
	return gcd(y,x%y);
}

ll f(ll x)
{
	ll ret=0;
	for(ll i=1;i*i<=x;i++)
	{
		if(x%i==0) ret++;
		if(i*i!=x&&x%i==0) ret++;
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll x=0;
	for(int i=1;i<=n;i++) x=gcd(a[i],x);
	cout<<f(x)<<endl;
	return 0;
}