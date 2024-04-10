#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int k[100010];
vector<int> v[100010];
bool vis[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			v[i].clear();vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int x;cin>>x;
				v[i].push_back(x);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(int j=0;j<v[i].size();j++){
				if(!vis[v[i][j]]){
					vis[v[i][j]]=1;
					flag=true;break;
				}
			}
			if(!flag) ans=i;
		}
		if(ans==0) cout<<"OPTIMAL\n";
		else{
			cout<<"IMPROVE\n";
			for(int j=1;j<=n;j++) if(!vis[j]){
				cout<<ans<<" "<<j<<'\n';
				break;
			}
		}
	}	
	return 0;
}