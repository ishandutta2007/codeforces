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

int n,a[100010],b[100010],flag[100010];
vector<int> v[100010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>b[i],v[i].clear();
		for(int i=1;i<=n;i++){
			if(b[i]==0) flag[i]=2;
			else if(b[i]==n+1) flag[i]=1;
			else if(b[i]<i) flag[i]=2,v[b[i]].push_back(i);
			else flag[i]=1,v[b[i]].push_back(i);
		}
		int k=n;
		for(int i=1;i<=n;i++) if(flag[i]==2){
			k=i-1;break;
		}
		vector<int> g;int cnt=0;
		for(int i=1;i<=n;i++) if(b[i]==0||b[i]==n+1) g.push_back(i);
		while(cnt+(int)g.size()<n){
			int pos=-1;
			for(int i=0;i<g.size();i++) if(!v[g[i]].empty()){
				pos=i;break;
			}
			for(int i=0;i<g.size();i++) if(i!=pos){
				cnt++;a[cnt]=g[i];
			}
			cnt++;a[cnt]=g[pos];
			int now=g[pos];g.clear();
			for(int i=0;i<v[now].size();i++) g.push_back(v[now][i]);
		}
		for(int i=0;i<g.size();i++){
			cnt++;a[cnt]=g[i];
		}
		cout<<k<<'\n';
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}