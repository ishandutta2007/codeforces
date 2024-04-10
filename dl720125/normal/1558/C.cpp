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

int n,a[3010],pos[3010];

inline void func(int x)
{
	for(int i=1;i<=x/2;i++) swap(a[i],a[x-i+1]);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(a[i]%2!=i%2){
				flag=true;break;
			}
		}
		if(flag){
			cout<<-1<<'\n';
			continue;
		}
		vector<int> v;
		for(int i=n;i>=3;i-=2){
			for(int j=1;j<=n;j++) pos[a[j]]=j;
			v.push_back(pos[i]);
			func(pos[i]);
			for(int j=1;j<=n;j++) pos[a[j]]=j;
			v.push_back(pos[i-1]-1);
			func(pos[i-1]-1);
			for(int j=1;j<=n;j++) pos[a[j]]=j;
			v.push_back(pos[i-1]+1);
			func(pos[i-1]+1);
			for(int j=1;j<=n;j++) pos[a[j]]=j;
			v.push_back(3);
			func(3);
			for(int j=1;j<=n;j++) pos[a[j]]=j;
			v.push_back(i);
			func(i);
		}
		cout<<v.size()<<'\n';
		for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
		cout<<'\n';
	}
	return 0;
}