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

int n,m,dp[4000010],val[4000010];

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=m) x-=m;
}

inline void add2(int &x,int y)
{
	x+=y;
	if(x<0) x+=m; 
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	dp[1]=1;
	for(int j=2;j<=n;j++) add1(val[j],dp[1]);
	for(int j=4;j<=n;j+=2) add2(val[j],-dp[1]);
	int sum=1;
	for(int i=2;i<=n;i++){
		dp[i]=sum;add1(val[i],val[i-1]);add1(dp[i],val[i]);
		for(int j=i*2;j<=n;j+=i) add1(val[j],dp[i]);
		for(int j=(i+1)*2;j<=n;j+=(i+1)) add2(val[j],-dp[i]);
		add1(sum,dp[i]);
	}
	cout<<dp[n]<<'\n';
	return 0;
}