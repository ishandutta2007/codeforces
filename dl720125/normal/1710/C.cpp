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

int n,u[200010],dp[200010][2][2][2][2][2][2];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD; 
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	string s;cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++) u[i]=s[i-1]-'0';
	dp[0][0][0][0][1][1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					for(int a=0;a<2;a++){
						for(int b=0;b<2;b++){
							for(int c=0;c<2;c++) if(dp[i-1][j][k][l][a][b][c]){
								int val=dp[i-1][j][k][l][a][b][c];
								for(int x=0;x<2;x++){
									for(int y=0;y<2;y++){
										int nj=(j|(!x&&y)),nk=(k|(x&&!y)),nl=(l|(x&&y));
										for(int o=0;o<2;o++){
											int na=(o^x),nb=o,nc=(o^y);
											if((a&&na>u[i])||(b&&nb>u[i])||(c&&nc>u[i])) continue;
											int pa=(a&(na==u[i])),pb=(b&(nb==u[i])),pc=(c&(nc==u[i]));
											add(dp[i][nj][nk][nl][pa][pb][pc],val);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			for(int c=0;c<2;c++){
				add(ans,dp[n][1][1][1][a][b][c]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}