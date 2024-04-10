#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
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

inline int ask(int x,int y)
{
	cout<<"and "<<x<<' '<<y<<'\n';fflush(stdout);
	int a;cin>>a;
	cout<<"or "<<x<<' '<<y<<'\n';fflush(stdout);
	int b;cin>>b;
	return a+b;
}

int val[10010];

signed main()
{
	int n,k;cin>>n>>k;
	int a=ask(1,2),b=ask(2,3),c=ask(1,3);
	long long tot=(1ll*a+1ll*b+1ll*c)/2ll;
	val[1]=(int)(tot-1ll*b);val[2]=(int)(tot-1ll*c);val[3]=(int)(tot-1ll*a);
	for(int i=4;i<=n;i++){
		int x=ask(1,i);
		val[i]=x-val[1];
	}
	sort(val+1,val+n+1);
	cout<<"finish "<<val[k]<<'\n';fflush(stdout);
	return 0;
}