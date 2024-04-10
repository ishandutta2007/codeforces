#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define INF 1000000000000000007ll
using namespace __gnu_pbds;
using namespace std;

int a[200010],b[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;cin>>n>>k;k--;
		int maxv=-INF;
		for(int i=1;i<=n;i++) cin>>a[i],maxv=max(maxv,a[i]);
		for(int i=1;i<=n;i++) a[i]=maxv-a[i];
		int mx=-INF;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		for(int i=1;i<=n;i++) b[i]=mx-a[i];
		if(k%2==0){
			for(int i=1;i<=n;i++) cout<<a[i]<<" ";
			cout<<'\n';
		}
		else{
			for(int i=1;i<=n;i++) cout<<b[i]<<" ";
			cout<<'\n';
		}
	}	
	return 0;
}