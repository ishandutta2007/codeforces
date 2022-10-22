#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define MOD 998244353ll
using namespace __gnu_pbds;
using namespace std;

int a[300010];

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return (res*res)%MOD;
	else return (((res*res)%MOD)*x)%MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	int val1=1,val2=1;
	for(int i=1;i<=n;i++) val1=(val1*i)%MOD;
	for(int i=1;i<=2*n;i++) val2=(val2*i)%MOD;
	for(int i=1;i<=2*n;i++) cin>>a[i];
	sort(a+1,a+2*n+1);
	int sum1=0;
	for(int i=1;i<=n;i++) sum1=(sum1+a[i])%MOD;
	int sum2=0;
	for(int i=n+1;i<=n*2;i++) sum2=(sum2+a[i])%MOD;
	int ans=(((val2*my_pow(val1,MOD-2))%MOD)*my_pow(val1,MOD-2))%MOD;
	ans=(ans*((sum2-sum1+MOD)%MOD))%MOD;
	cout<<ans<<endl;
	return 0;
}