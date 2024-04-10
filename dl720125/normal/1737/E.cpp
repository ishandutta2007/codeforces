#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 1000000007
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

const int rev=500000004;

int f[1000010],r[1000010],g[1000010][2];

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD; 
}

inline void add2(int &x,int y)
{
	x+=y;
	if(x<0) x+=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	r[0]=1;
	for(int i=1;i<=1000000;i++) r[i]=1ll*r[i-1]*rev%MOD;
	while(t--){
		int n;cin>>n;
		if(n==1){
			cout<<1<<'\n';continue;
		}
		int sum=0;
		for(int i=n;i>=3;i--){
			int len=(i-1)/2+1;
			if(i==n){
				f[i]=1ll*r[len]*2%MOD;g[i][0]=1;g[i][1]=0;
			}
			else{
				f[i]=r[len];
				g[i][0]=g[i+1][0];add1(g[i][0],g[i+1][1]);
				g[i][1]=g[i+1][0];add1(g[i][1],g[i+1][1]);
				if(2*i<=n) add2(g[i][1],-g[2*i-1][0]);
				if(2*i<=n) add2(g[i][1],-g[2*i][0]);
				if(2*i==n-1) add2(g[i][1],-1);
				int now=g[i][0];add1(now,g[i][1]);
				f[i]=1ll*f[i]*now%MOD*r[n-i]%MOD;
			}
			add1(sum,f[i]);
		}
		f[2]=1;add2(f[2],-sum);
		f[1]=0;
		for(int i=1;i<=n;i++) cout<<f[i]<<'\n';
	}
	return 0;
}