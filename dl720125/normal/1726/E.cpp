#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int pw[300010],rev[300010],pw2[300010],pw22[300010],f[300010];

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline int calc(int x,int y)
{
	return 1ll*pw[x]*rev[y]%MOD*rev[x-y]%MOD;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	pw[0]=1;
	for(int i=1;i<=300000;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[300000]=my_pow(pw[300000],MOD-2);
	for(int i=299999;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	pw2[0]=1;
	for(int i=1;i<=300000;i++) pw2[i]=1ll*pw2[i-1]*(2*i-1)%MOD;
	pw22[0]=1;
	for(int i=1;i<=300000;i++) pw22[i]=1ll*pw22[i-1]*2%MOD;
	f[0]=1;f[1]=1;
	for(int i=2;i<=300000;i++){
		f[i]=f[i-1];
		add1(f[i],1ll*(i-1)*f[i-2]%MOD);
	}
	while(t--){
		int n;cin>>n;
		int ans=0;
		for(int i=0;i<=n/4;i++){
			add1(ans,1ll*calc(n-i*2,i*2)*pw2[i]%MOD*pw22[i]%MOD*f[n-i*4]%MOD);
		}
		cout<<ans<<'\n';
	}
	return 0;
}