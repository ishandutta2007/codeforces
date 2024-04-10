#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
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

int dp[3010][3010];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	string s,t;
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		if(i>=t.size()) dp[1][i]=2;
		else if(s[0]==t[i]) dp[1][i]=2;
	}
	for(int i=1;i<s.size();i++){
		for(int j=0;j<s.size()-i+1;j++){
			if(j>0){
				if(j-1>=t.size()) add(dp[i+1][j-1],dp[i][j]);
				else if(s[i]==t[j-1]) add(dp[i+1][j-1],dp[i][j]);
			}
			if(j+i-1<s.size()-1){
				if(j+i>=t.size()) add(dp[i+1][j],dp[i][j]);
				else if(s[i]==t[j+i]) add(dp[i+1][j],dp[i][j]);
			}
		}
	}
	int ans=0;
	for(int i=t.size()-1;i<s.size();i++){
		add(ans,dp[i+1][0]);
	}
	cout<<ans<<endl;
	return 0;
}