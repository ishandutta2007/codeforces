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

int n,a[20],p[20],val1[20][20010],val2[20][20010],res[20010],f[20010],dp[20][20010];

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
	if(x<0) x+=MOD; 
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<n);j++) if(!(j&(1<<(i-1)))){
			val1[i][j]=val2[i][j]=1;
			for(int k=1;k<=n;k++) if(j&(1<<(k-1))){
				val1[i][j]=1ll*a[k]*my_pow(a[i]+a[k],MOD-2)%MOD*val1[i][j]%MOD;
				val2[i][j]=1ll*a[i]*my_pow(a[i]+a[k],MOD-2)%MOD*val2[i][j]%MOD;
			}
		}
	}
	for(int i=1;i<(1<<n);i++) res[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<(1<<n);j++){
			int cnt=__builtin_popcount(j);
			if(cnt<=i) f[j]=res[j];
			else f[j]=0;
		}
		for(int j=1;j<(1<<n);j++){
			int mask=(((1<<n)-1)^j);
			for(int k=mask;k>0;k=(k-1)&mask){
				if(__builtin_popcount(k)>i) continue;
				int nw=(j|k),val=1;
				for(int l=1;l<=n;l++) if(k&(1<<(l-1))) val=1ll*val*val1[l][j]%MOD;
				add(f[nw],1ll*f[j]*res[k]%MOD*val%MOD);
			}
		}
		for(int j=1;j<(1<<n);j++){
			int cnt=__builtin_popcount(j);
			if(cnt==i+1) add(res[j],-f[j]);
		}
	}
	for(int i=1;i<(1<<n);i++){
		int cnt=__builtin_popcount(i);
		dp[cnt][i]=res[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<(1<<n);j++){
		    int cnt=__builtin_popcount(j);
		    if(cnt<i) continue;
			int mask=(((1<<n)-1)^j);
			for(int k=mask;k>0;k=(k-1)&mask){
				int nw=(j|k),val=1;
				for(int l=1;l<=n;l++) if(k&(1<<(l-1))) val=1ll*val*val1[l][j]%MOD;
				add(dp[i][nw],1ll*dp[i][j]*res[k]%MOD*val%MOD);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) add(ans,1ll*i*dp[i][(1<<n)-1]%MOD);
	cout<<ans<<'\n';
	return 0;
}