#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define mod 998244353
long long a[210000],b[210000];
int n;
int main()
{
	cin>>n;
	rep(i,n){ scanf("%lld",&a[i]); a[i]=a[i]*i*(n-i+1); }
	rep(i,n)scanf("%lld",&b[i]);
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	sort(b+1,b+n+1);
	long long ans=0;
	rep(i,n)ans=(ans+(a[i]%mod)*(b[i]%mod)%mod)%mod;
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
}