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

char a[110],b[110];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		bool flag=true;
		for(int i=2;i<=m;i++) if(b[i]!=a[i+n-m]){
			flag=false;break;
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n-m+1;i++){
			if(a[i]=='0') cnt0++;
			else cnt1++;
		}
		if((b[1]=='0'&&cnt0>0)||(b[1]=='1'&&cnt1>0)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}