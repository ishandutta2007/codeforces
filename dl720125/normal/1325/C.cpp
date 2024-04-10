#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,ans[100010],deg[100010];
vector<pair<int,int> > v[100010],e;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(make_pair(y,i));
		v[y].push_back(make_pair(x,i));
		e.push_back(make_pair(x,y));
		deg[x]++;deg[y]++;
	}
	if(n==2){
		cout<<0<<endl;
		return 0;
	}
	else if(n==3){
		cout<<0<<endl<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) if(deg[i]>=3){
		int val=0;
		for(int j=0;j<v[i].size();j++){
			int u=v[i][j].first,idx=v[i][j].second;
			ans[idx]=val++;
			if(val==3) break;
		}
		break;
	}
	int cnt=n-2;
	for(int i=1;i<n;i++) if(ans[i]==-1) ans[i]=cnt--;
	for(int i=1;i<n;i++) cout<<ans[i]<<endl;
	return 0;
}