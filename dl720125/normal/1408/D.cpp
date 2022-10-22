#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

int n,m,cnt,a[2010],b[2010],c[2010],d[2010];
vector<int> v[1000010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++) cin>>c[i]>>d[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			v[max(c[j]-a[i]+1,0)].push_back(max(d[j]-b[i]+1,0));
		}
	}
	int ans=INF,mx=0;
	for(int i=1000001;i>=0;i--){
		ans=min(ans,i+mx);
		for(int j=0;j<v[i].size();j++) mx=max(mx,v[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}