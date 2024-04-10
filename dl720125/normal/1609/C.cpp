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

int cnt,p[1000010],vis[1000010],a[200010],nxt1[200010],nxt2[200010],nxt3[200010];

inline void init()
{
	for(int i=2;i<=1000000;i++){
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;i*p[j]<=1000000&&j<=cnt;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	init();
	int t;cin>>t;
	while(t--){
		int n,e;cin>>n>>e;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=n;i>=1;i--){
			if(i+e>n){
				if(a[i]==1) nxt1[i]=i;
				else nxt1[i]=-1;
			}
			else{
				if(a[i]==1){
					if(nxt1[i+e]==-1) nxt1[i]=i;
					else nxt1[i]=nxt1[i+e];
				}
				else nxt1[i]=-1;
			}
		}
		for(int i=n;i>=1;i--){
			if(i+e>n){
				if(vis[a[i]]) nxt2[i]=-1,nxt3[i]=-1;
				else if(a[i]==1) nxt2[i]=i,nxt3[i]=1;
				else nxt2[i]=i,nxt3[i]=0;
			}
			else{
				if(vis[a[i]]) nxt2[i]=-1,nxt3[i]=-1;
				else if(a[i]==1){
					if(nxt2[i+e]==-1) nxt2[i]=i,nxt3[i]=1;
					else nxt2[i]=nxt2[i+e],nxt3[i]=nxt3[i+e];
				}
				else{
					if(nxt2[i+e]==-1) nxt2[i]=i,nxt3[i]=0;
					else if(nxt3[i+e]==1) nxt2[i]=nxt2[i+e],nxt3[i]=0;
					else{
						if(nxt1[i+e]==-1) nxt2[i]=i,nxt3[i]=0;
						else nxt2[i]=nxt1[i+e],nxt3[i]=0;
					}
				}
			}
		}
		long long ans=0ll;
		for(int i=1;i<=n;i++){
			if(nxt2[i]!=-1&&nxt3[i]==0){
				if(nxt1[i]==-1) ans+=1ll*((nxt2[i]-i)/e+1);
				else ans+=1ll*((nxt2[i]-nxt1[i])/e);
			}
		}
		for(int i=1;i<=n;i++) if(a[i]!=1&&!vis[a[i]]) ans--;
		cout<<ans<<'\n';
	}
	return 0;
}