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

int dp[110][110][2];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			int rem=(x%2+2)%2;
			if(rem%2==0) cnt0++;
			else cnt1++;
		}
		for(int i=0;i<=cnt0;i++){
			for(int j=0;j<=cnt1;j++){
				if(i==0&&j==0){
					dp[i][j][0]=1;dp[i][j][1]=0;continue;
				}
				dp[i][j][0]=0;dp[i][j][1]=0;
				if(i>0) dp[i][j][0]|=(dp[i-1][j][!(j&1)]==0);
				if(i>0) dp[i][j][1]|=(dp[i-1][j][j&1]==0);
				if(j>0) dp[i][j][0]|=(dp[i][j-1][(j-1)&1]==0);
				if(j>0) dp[i][j][1]|=(dp[i][j-1][!((j-1)&1)]==0);
			}
		}
		if(dp[cnt0][cnt1][0]) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}