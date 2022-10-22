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

inline long long calc(long long x)
{
	long long res=0ll;
	int L=1,R=1000000000,ans=0;
	while(L<=R){
		int mid=(L+R)/2;
		if(1ll*mid*mid<=x){
			ans=mid;L=mid+1;
		}
		else R=mid-1;
	}
	res+=1ll*ans;
	L=1,R=1000000000,ans=0;
	while(L<=R){
		int mid=(L+R)/2;
		if(1ll*mid*(mid+1)<=x){
			ans=mid;L=mid+1;
		}
		else R=mid-1;
	}
	res+=1ll*ans;
	L=1,R=1000000000,ans=0;
	while(L<=R){
		int mid=(L+R)/2;
		if(1ll*mid*(mid+2)<=x){
			ans=mid;L=mid+1;
		}
		else R=mid-1;
	}
	res+=1ll*ans;
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		long long l,r;cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<'\n';
	}
	return 0;
}