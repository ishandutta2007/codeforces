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

int n,d,cnt,p[1010],sz[1010];

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>d;
	for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;
	multiset<int> s;
	for(int i=1;i<=n;i++) s.insert(-sz[i]);
	for(int i=1;i<=d;i++){
		int x,y;cin>>x>>y;
		int rootx=find_set(x),rooty=find_set(y);
		if(rootx!=rooty){
			p[rooty]=rootx;
			s.erase(s.find(-sz[rootx]));
			s.erase(s.find(-sz[rooty]));
			sz[rootx]+=sz[rooty];
			s.insert(-sz[rootx]);
		}
		else cnt++;
		int len=(int)s.size();
		vector<int> v;
		for(int j=1;j<=min(cnt+1,len);j++){
			v.push_back(-(*s.begin()));
			s.erase(s.begin());
		}
		int sum=0;
		for(int j=0;j<v.size();j++){
			sum+=v[j];
			s.insert(-v[j]);
		}
		cout<<sum-1<<'\n';
	}
	return 0;
}