#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[110],b[110],c[110],ans[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++) cin>>c[i];
		for(int i=1;i<n;i++){
			if(a[i]!=ans[i-1]) ans[i]=a[i];
			if(b[i]!=ans[i-1]) ans[i]=b[i];
			if(c[i]!=ans[i-1]) ans[i]=c[i];
		}
		if(a[n]!=ans[n-1]&&a[n]!=ans[1]) ans[n]=a[n];
		if(b[n]!=ans[n-1]&&b[n]!=ans[1]) ans[n]=b[n];
		if(c[n]!=ans[n-1]&&c[n]!=ans[1]) ans[n]=c[n];
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<'\n';
	}
	return 0;
}