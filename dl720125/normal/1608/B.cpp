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

int ans[100010],deg[100010];
vector<int> v[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,a,b;cin>>n>>a>>b;
		int mx=(n-1)/2;
		if(a+b>n-2) cout<<-1<<'\n';
		else if(a>mx||b>mx) cout<<-1<<'\n';
		else if(abs(a-b)>=2) cout<<-1<<'\n';
		else{
			string s="";
			if(a==b){
				for(int i=1;i<=a;i++) s+="01";
				for(int i=1;i<=n-1-a*2;i++) s+="0";
			}
			else if(a==b+1){
				for(int i=1;i<=a;i++) s+="01";
				for(int i=1;i<=n-1-a*2;i++) s+="1";
			}
			else{
				for(int i=1;i<=b;i++) s+="10";
				for(int i=1;i<=n-1-b*2;i++) s+="0";
			}
			for(int i=1;i<=n;i++) v[i].clear(),deg[i]=0,ans[i]=0;
			for(int i=1;i<=n-1;i++){
				if(s[i-1]=='0') v[i].push_back(i+1),deg[i+1]++;
				else v[i+1].push_back(i),deg[i]++;
			}
			queue<int> q;
			for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
			int cnt=0;
			while(!q.empty()){
				int t=q.front();q.pop();ans[t]=++cnt;
				for(int i=0;i<v[t].size();i++){
					int u=v[t][i];deg[u]--;
					if(deg[u]==0) q.push(u);
				}
			}
			for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
			cout<<'\n'; 
		}
	}
	return 0;
}