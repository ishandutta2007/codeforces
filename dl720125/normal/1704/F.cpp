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

int sg[500010],b[500010],vis[110];
char c[500010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	sg[0]=0;sg[1]=1;sg[2]=1;
	for(int i=3;i<=87;i++){
		for(int j=0;j<=87;j++) vis[j]=0;
		vis[sg[i-2]]=1;vis[sg[i-3]]=1;
		for(int j=1;j<=i-4;j++) vis[sg[j]^sg[i-3-j]]=1;
		for(int j=0;j<=87;j++) if(!vis[j]){
			sg[i]=j;break;
		}
	}
	for(int i=88;i<=500000;i++) sg[i]=sg[i-34];
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>c[i];
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='R') cnt0++;
			else cnt1++;
		}
		if(cnt0!=cnt1){
			if(cnt0>cnt1) cout<<"Alice\n";
			else cout<<"Bob\n";
			continue;
		}
		vector<int> v;
		for(int i=1;i<n;i++) b[i]=(c[i]!=c[i+1]);
		int cnt=0;
		for(int i=1;i<n;i++){
			if(b[i]==1) cnt++;
			else{
				v.push_back(cnt);
				cnt=0;
			}
		}
		v.push_back(cnt);
		int ans=0;
		for(int i=0;i<v.size();i++) ans^=sg[v[i]];
		if(ans>0) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}