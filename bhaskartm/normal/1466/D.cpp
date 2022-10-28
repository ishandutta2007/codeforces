#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;
int val[N];
int deg[N];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum=0;
		for(int i=1; i<=n; i++){
			cin>>val[i];
			sum+=val[i];
		}
		for(int i=1; i<=n; i++){
			deg[i]=-1;
		}
		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			deg[u]++;
			deg[v]++;
			
		}
		set<pair<int, int>>se;
		for(int i=1; i<=n; i++){
			if(deg[i]!=0){
				se.insert({val[i], i});
			}
		}
		vector<int>ans;
		ans.pb(sum);
		for(int i=0; i<n-2; i++){
			if(se.size()==0){
				ans.pb(ans.back());
				continue;
			}
			auto it=se.end();
			it--;
			int node=(*it).s;
			se.erase(it);
			sum+=val[node];
			deg[node]--;
			if(deg[node]!=0){
				se.insert({val[node], node});
			}
			ans.pb(sum);
		}
		for(auto u:ans){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	return 0;
}