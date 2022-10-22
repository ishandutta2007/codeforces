#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[4010],maxv[4010],ok[4010],dp[4010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n*2;i++) cin>>a[i];
		maxv[1]=a[1];
		for(int i=2;i<=n*2;i++) maxv[i]=max(maxv[i-1],a[i]);
		for(int i=1;i<=n*2;i++) ok[i]=0;
		for(int i=1;i<=n*2;i++) if(maxv[i]==a[i]) ok[i]=1;
		vector<int> v;
		int cnt=1;
		for(int i=2;i<=n*2;i++){
			if(ok[i]){
				v.push_back(cnt);
				cnt=1;
			}
			else cnt++;
		}
		v.push_back(cnt);
		for(int i=1;i<=n*2;i++) dp[i]=0;
		dp[0]=1;
		for(int i=0;i<v.size();i++){
			for(int j=n*2;j>=v[i];j--){
				if(dp[j-v[i]]) dp[j]=1;
			}
		}
		if(dp[n]) cout<<"YES\n";
		else cout<<"NO\n";
	}	
	return 0;
}