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

int n,k;
long long a[100010],s[100010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=n-k+1;i<=n;i++) cin>>s[i];
		if(k==1){
			cout<<"Yes\n";continue;
		}
		for(int i=n;i>=n-k+2;i--){
			a[i]=s[i]-s[i-1];
		}
		bool flag=true;
		if(1ll*(n-k+1)*a[n-k+2]<s[n-k+1]) flag=false;
		for(int i=n-k+2;i<=n-1;i++){
			if(a[i]>a[i+1]) flag=false;
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}