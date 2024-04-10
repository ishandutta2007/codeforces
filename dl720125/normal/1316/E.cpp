#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define INF 1000000000000000007ll
using namespace __gnu_pbds;
using namespace std;

int n,p,k,dp[100010][210],s[100010][10];
pair<int,int> a[100010];

inline int getint(){
    int r=0ll;
	char c;
	c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){r=r*10ll+c-'0';c=getchar();}
    return r;
}

signed main()
{
	cin>>n>>p>>k;
	for(int i=1;i<=n;i++){
		a[i].first=getint();
		a[i].second=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p;j++){
			s[i][j]=getint();
		}
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=0;i<=n;i++) for(int j=0;j<(1ll<<p);j++) dp[i][j]=-INF;
	dp[0][0]=0ll;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1ll<<p);j++){
			int cnt=i-1ll-__builtin_popcountll(j);
			if(cnt<0ll) continue;
			if(cnt<k) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].first);
			else dp[i][j]=max(dp[i][j],dp[i-1][j]);
			for(int l=1;l<=p;l++) if(!(j&(1ll<<(l-1)))){
				dp[i][j|(1ll<<(l-1))]=max(dp[i][j|(1ll<<(l-1))],dp[i-1][j]+s[a[i].second][l]);
			}
		}
	}
	cout<<dp[n][(1ll<<p)-1ll]<<endl;
	return 0;
}