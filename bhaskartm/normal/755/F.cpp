#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int p[1000005];
bool vis[1000005];
vector<vector<int>>cycles;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;

	for(int i=1; i<=n; i++){
		cin>>p[i];
	}
	
	for(int i=1; i<=n; i++){
		if(vis[i]){
			continue;
		}
		vector<int>cycle;
		int node=i;
		while(1){
			if(vis[node]){
				break;
			}
			vis[node]=1;
			cycle.pb(node);
			node=p[node];
			
		}
		cycles.pb(cycle);
	}
	vector<int>ans;
	for(int i=0; i<cycles.size(); i++){
		ans.pb(cycles[i].size());
	}
	sort(ans.begin(), ans.end());
	int kk1=k;
	int kk2=k;
	int ans1=0;
	int ans2=0;
	for(auto u:ans){
		if(u%2==0){
			ans1+=((u)/2);
		}
		else{
			ans1+=((u-1)/2);
			ans2+=1;
		}
	}

	int maxi;
	int mini;
	
	if(ans1>=k){
		maxi=2*k;
	}
	else if(ans1+ans2>=k){
		maxi=2*ans1+(k-ans1);
	}
	else{
		maxi=n;
	}
	bitset<1000005>dp;
	dp[0]=1;
	
	int cnt[k+1];
	
	for(int i=0; i<=k; i++){
		cnt[i]=0;
	}
	for(auto u:ans){
		if(u>k){
			continue;
		}
		cnt[u]++;
		if(cnt[u]*u>k){
			cnt[u]--;
		}
	}
	for(int i=1; i<=k; i++){
		if(cnt[i]==0){
			continue;
		}
		for(int x=0; (1<<x)<=cnt[i]; x++){
			dp |= (dp<<(i*(1<<x)));
			cnt[i]-=(1<<x);
		}
		dp |= (dp<<(i*cnt[i]));
	}
	if(dp[k]){
		mini=k;
	}
	else{
		mini=k+1;
	}
	cout<<mini<<" "<<maxi;
	return 0;
}