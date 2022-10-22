#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 1000000007
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

int pw[3000010],rev[3000010],val[3000010];
const int rev3=333333336;

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

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
	if(x<0) x+=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	pw[0]=1;
	for(int i=1;i<=3000005;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[3000005]=my_pow(pw[3000005],MOD-2);
	for(int i=3000004;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD; 
	int n,q;cin>>n>>q;
	for(int i=0;i<=3*n;i++){
		int now=calc(3*n+3,i+1);
		if(i>=1) add(now,-1ll*val[i-1]*3%MOD);
		if(i>=2) add(now,-1ll*val[i-2]%MOD);
		val[i]=1ll*now*rev3%MOD;
	}
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		cout<<val[x]<<'\n';
	}
	return 0;
}