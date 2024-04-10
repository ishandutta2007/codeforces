#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

int a[10],n,b[100010],vis[100010];
vector<pair<int,int> > v;

signed main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<=6;i++) cin>>a[i];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=6;i++){
		for(int j=1;j<=n;j++){
			v.push_back(make_pair(b[j]-a[i],j));
		}
	}
	sort(v.begin(),v.end());
	int r=-1,ans=INF,cnt=0;
	for(int i=0;i<v.size();i++){
		while(r<((int)v.size()-1)&&cnt<n){
			vis[v[r+1].second]++;
			if(vis[v[r+1].second]==1) cnt++;
			r++;
		}
		if(cnt==n){
			ans=min(ans,v[r].first-v[i].first);
		}
		vis[v[i].second]--;
		if(vis[v[i].second]==0) cnt--;
	}
	cout<<ans<<endl;
	return 0;
}