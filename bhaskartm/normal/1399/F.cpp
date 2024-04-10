#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define pb push_back
#define f first
#define s second
int dp[6005][6005];
bool pre[6005][6005];
vector<vector<int>>ri;

int f(int l, int r){
	if(l>r){
		return 0;
	}
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	dp[l][r]=0;
	int ans=0;
	
	ans=max(ans, f(l+1, r));
	
	for(auto u:ri[l]){
		if(u>=r){
			break;
		}
		ans=max(ans, f(l, u) + f(u+1, r));
	}
	if(pre[l][r]){
		ans++;
	}
	dp[l][r]=ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int, int>>v;
		set<int>se;
		map<int, int>m;
		for(int i=0; i<n; i++){
			int l, r;
			cin>>l>>r;
			v.pb({l, r});
			se.insert(l);
			se.insert(r);
		}
		int pt=0;
		for(auto u:se){
			m[u]=pt;
			pt++;
		}
		for(int i=0; i<v.size(); i++){
			v[i]={m[v[i].f], m[v[i].s]};
		}
		
		ri.clear();
		ri.resize(pt+5);
		for(int i=0; i<v.size(); i++){
			ri[v[i].f].pb(v[i].s);
			pre[v[i].f][v[i].s]=1;
		}
		for(int i=0; i<pt+5; i++){
			sort(ri[i].begin(), ri[i].end());
		}
		for(int i=0; i<pt+2; i++){
			for(int j=0; j<pt+2; j++){
				dp[i][j]=-1;
	
			}
		}
		
		cout<<f(0, pt+1)<<endl;
		for(int i=0; i<pt+2; i++){
			for(int j=0; j<pt+2; j++){
				dp[i][j]=0;
				pre[i][j]=0;
			}
		}
	}
	return 0;
}