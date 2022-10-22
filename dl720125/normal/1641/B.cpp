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

int a[510],b[510];
map<int,int> mp;

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;mp.clear();
		for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
		bool flag=true;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			if((it->second)%2==1){
				flag=false;break;
			}
		}
		if(!flag){
			cout<<-1<<'\n';
			continue;
		}
		vector<pair<int,int> > ans;
		vector<int> g;
		int now=1,sum=0;
		while(now<=n){
			int pos=-1;
			for(int i=now+1;i<=n;i++) if(a[i]==a[now]){
				pos=i;break;
			}
			int len=2*(pos-now);
			for(int i=now+1;i<pos;i++){
				ans.push_back(make_pair(sum+pos-now+i-now,a[i]));
			}
			g.push_back(len);
			sum+=len;
			now+=2;
			for(int i=pos;i>=now;i--) b[i]=a[now+pos-i-1];
			for(int i=pos;i>=now;i--) a[i]=b[i];
		}
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
		}
		cout<<g.size()<<'\n';
		for(int i=0;i<g.size();i++) cout<<g[i]<<' ';
		cout<<'\n';
	}
	return 0;
}