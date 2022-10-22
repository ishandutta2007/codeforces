#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define MOD 998244353ll
using namespace __gnu_pbds;
using namespace std;

int n,m,pw[200010],rev[200010];

inline int my_pow(int x,int y)
{
	if(y==0ll) return 1ll;
	if(y==1ll) return x;
	int res=my_pow(x,y/2ll);
	if(y%2ll==0ll) return (res*res)%MOD;
	else return (((res*res)%MOD)*x)%MOD;
}

inline int calc(int x,int y)
{
	int num=(rev[y]*rev[x-y])%MOD;
	return (pw[x]*num)%MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int ans=0ll;
	pw[0]=1ll;rev[0]=1ll;
	for(int i=1;i<=m;i++){
		pw[i]=(pw[i-1]*i)%MOD;
		rev[i]=my_pow(pw[i],MOD-2ll);
	}
	for(int i=1;i<=n-1;i++){
		int pre=i-1ll,nxt=n-i-1ll;
		int val=(calc(m,n-1ll)*calc(n-2ll,pre))%MOD;
		ans+=(val*(n-2ll))%MOD;
		if(ans>=MOD) ans-=MOD;
	}
	cout<<(ans*my_pow(2ll,MOD-2ll))%MOD<<endl;
	return 0;
}