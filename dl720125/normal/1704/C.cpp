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
		int n,m;cin>>n>>m;
		for(int i=1;i<=m;i++) cin>>a[i];
		sort(a+1,a+m+1);
		priority_queue<int> q;
		for(int i=1;i<m;i++) q.push(a[i+1]-a[i]-1);
		q.push(n-a[m]+a[1]-1);
		int ans=0,offset=0;
		while(!q.empty()){
			int t=q.top();q.pop();
			t-=offset*2;
			if(t<=0) continue;
			if(t==1) ans+=t,offset++;
			else if(t==2) ans+=t-1,offset++;
			else ans+=t-1,offset+=2;
		}
		cout<<n-ans<<'\n';
	}
	return 0;
}