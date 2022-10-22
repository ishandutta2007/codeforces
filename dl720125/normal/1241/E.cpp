#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
int dp[500100][2];
vector<pair<int,int> > v[500100];

inline void dfs(int u,int pr)
{
	vector<int> res;
	int ans=0;
	for(int i=0;i<v[u].size();i++) if(v[u][i].first!=pr){
		int t=v[u][i].first,dis=v[u][i].second;
		dfs(t,u);
		ans+=dp[t][0];
		int val=dp[t][1]+dis-dp[t][0];
		if(val>0) res.push_back(dp[t][1]+dis-dp[t][0]);
	}
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	dp[u][0]=ans;dp[u][1]=ans;
	int cnt1=0,cnt2=0;
	for(int i=0;i<res.size();i++){
		cnt1++;
		cnt2++;
		if(cnt1<=k){
			dp[u][0]+=res[i];
		}
		if(cnt2<k){
			dp[u][1]+=res[i];
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
			dp[i][0]=0;dp[i][1]=0;
		}
		for(int i=1;i<n;i++){
			int x,y,c;
			cin>>x>>y>>c;
			v[x].push_back(make_pair(y,c));
			v[y].push_back(make_pair(x,c));
		}
		dfs(1,-1);
		cout<<dp[1][0]<<endl;
	}
	return 0;
}