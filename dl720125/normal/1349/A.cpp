#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int n,a[200010],pre[200010],suf[200010];

inline int gcd(int x,int y)
{
	if(y==0ll) return x;
	return gcd(y,x%y);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		pre[i]=gcd(pre[i-1],a[i]);
	}
	suf[n]=a[n];
	for(int i=n-1;i>=1;i--){
		suf[i]=gcd(suf[i+1],a[i]);
	}
	vector<int> v;
	v.push_back(suf[2]);
	for(int i=2;i<n;i++){
		v.push_back(gcd(pre[i-1],suf[i+1]));
	}
	v.push_back(pre[n-1]);
	int ans=1ll;
	for(int i=0;i<v.size();i++){
		int g=gcd(ans,v[i]);
		ans=ans*(v[i]/g);
	}
	cout<<ans<<endl;
	return 0;
}