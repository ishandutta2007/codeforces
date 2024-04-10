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
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i],a[i]%=2;
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt0++;
			else cnt1++;
		}
		if(abs(cnt0-cnt1)>1){
			cout<<-1<<'\n';
			continue;
		}
		vector<int> v;
		for(int i=1;i<=n;i++) if(a[i]==0) v.push_back(i);
		if(n%2==0){
			int val1=0,val2=0;
			for(int i=1;i<=n/2;i++){
				val1+=abs(v[i-1]-(i*2-1));
				val2+=abs(v[i-1]-(i*2));
			}
			cout<<min(val1,val2)<<'\n';
		}
		else{
			if(v.size()==n/2){
				int val=0;
				for(int i=1;i<=n/2;i++){
					val+=abs(v[i-1]-(i*2));
				}
				cout<<val<<'\n';
			}
			else{
				int val=0;
				for(int i=1;i<=n/2+1;i++){
					val+=abs(v[i-1]-(i*2-1));
				}
				cout<<val<<'\n';
			}
		} 
	}
	return 0;
}