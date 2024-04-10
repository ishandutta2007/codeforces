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

int a[100010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m,k;cin>>n>>m>>k;
		for(int i=1;i<=k;i++) cin>>a[i];
		long long cnt=0ll;
		bool flag=false;
		for(int i=1;i<=k;i++){
			if(a[i]>=2*m){
				int now=(a[i]-m)/m+1;
				cnt+=1ll*now;
				if(now>2) flag=true;
			}
		}
		if(cnt>=1ll*n){
			if((cnt-1ll*n)%2ll==0ll||flag){
				cout<<"Yes\n";continue;
			}
		}
		cnt=0ll;
		flag=false;
		for(int i=1;i<=k;i++){
			if(a[i]>=2*n){
				int now=(a[i]-n)/n+1;
				cnt+=1ll*now;
				if(now>2) flag=true;
			}
		}
		if(cnt>=1ll*m){
			if((cnt-1ll*m)%2ll==0ll||flag){
				cout<<"Yes\n";continue;
			}
		}
		cout<<"No\n";
	}
	return 0;
}