#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int val[100],ans[100];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int d,m;
		cin>>d>>m;
		int cnt=0ll,k=1ll;
		while(k<=d){
			cnt++;
			val[cnt]=k;
			if(k*2ll>d) val[cnt]=d-k+1ll;
			k*=2ll;
		}
		for(int i=1;i<=cnt;i++){
			ans[i]=(ans[i-1]*(val[i]+1ll)+val[i])%m;
		}
		cout<<ans[cnt]<<endl;
	}
	return 0;
}