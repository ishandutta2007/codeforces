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

int a[100010],sum[100010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,q;cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		sum[0]=0;
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]<=q);
		int ans=sum[n],pos=n+1,val=0;
		for(int i=n;i>=1;i--){
			if(a[i]>val) val++;
			if(val>q) break;
			if(sum[i-1]+n-i+1>ans){
				ans=sum[i-1]+n-i+1;
				pos=i;
			}
		}
		for(int i=1;i<pos;i++){
			if(a[i]<=q) cout<<'1';
			else cout<<'0';
		}
		for(int i=pos;i<=n;i++) cout<<'1';
		cout<<'\n';
	}
	return 0;
}