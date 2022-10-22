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

int a[100010],b[100010],vis[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;a[i]=ch-'0';
		}
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;b[i]=ch-'0';
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(a[i]!=b[i]) ans+=2;
		for(int i=1;i<=n;i++) vis[i]=0;
		int tot=0;
		for(int i=1;i<=n;i++) if(a[i]==0&&b[i]==0) tot++;
		for(int i=1;i<=n;i++) if(a[i]==1&&b[i]==1){
			bool flag=false;
			for(int j=i-1;j>=1;j--){
				if(a[j]!=b[j]) break;
				if(a[j]==1&&b[j]==1) break;
				if(vis[j]) break;
				if(a[j]==0&&b[j]==0){
					flag=true;break;
				}
			}
			if(flag){
				ans+=2;vis[i-1]=1;tot--;continue;
			}
			for(int j=i+1;j<=n;j++){
				if(a[j]!=b[j]) break;
				if(a[j]==1&&b[j]==1) break;
				if(vis[j]) break;
				if(a[j]==0&&b[j]==0){
					flag=true;break;
				}
			}
			if(flag){
				ans+=2;vis[i+1]=1;tot--;continue; 
			}
		}
		ans+=tot;
		cout<<ans<<'\n';
	}
	return 0;
}