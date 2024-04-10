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

int n,m,a[90010],pos[90010];
pair<int,int> b[90010];
bool vis[90010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n*m;i++) cin>>a[i],b[i].first=a[i],b[i].second=i;
		sort(b+1,b+n*m+1);
		for(int i=1;i<=n*m;i++){
			int now=i;
			while(now<n*m&&b[now+1].first==b[i].first) now++;
			vector<int> v;
			for(int j=i;j<=now;j++) v.push_back(b[j].second);
			int posl=(i-1)/m+1,posr=(now-1)/m+1;
			if(posl==posr){
				int cnt=0;
				for(int j=now;j>=i;j--) pos[v[cnt++]]=j;
			}
			else{
				int cnt=0;
				for(int j=posl*m;j>=i;j--) pos[v[cnt++]]=j;
				for(int j=posl+1;j<posr;j++){
					for(int k=j*m;k>=(j-1)*m+1;k--) pos[v[cnt++]]=k;
				}
				for(int j=now;j>=(posr-1)*m+1;j--) pos[v[cnt++]]=j;
			}
			i=now;
		}
		for(int i=1;i<=n*m;i++) vis[i]=0;
		int ans=0;
		for(int i=1;i<=n*m;i++){
			for(int j=m*((pos[i]-1)/m)+1;j<pos[i];j++) ans+=vis[j];
			vis[pos[i]]=1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}