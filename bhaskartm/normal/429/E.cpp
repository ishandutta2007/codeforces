#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>adj;
int ans[100005];


void dfs(int v, int p, int co){
	ans[v]=co;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v, 3-co);
	}
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	adj.resize(n+1);
	
	multiset<pair<pair<int, int>, int>>se;
	for(int i=0; i<n; i++){
		int l, r;
		cin>>l>>r;
		se.insert({{l, r}, i});
	}
	while(1){
		if(se.size()==0){
			break;
		}
		if(se.size()==1){
			auto it=se.begin();
			
			break;
		}
		auto it=se.begin();
		int l1=(*it).f.f;
		int r1=(*it).f.s;
		int ind1=(*it).s;
		se.erase(it);
		it=se.begin();
		int l2=(*it).f.f;
		int r2=(*it).f.s;
		int ind2=(*it).s;
		se.erase(it);
		if(r1<l2){
			
			se.insert({{l2, r2}, ind2});
			continue;
		}
		adj[ind1].pb(ind2);
		adj[ind2].pb(ind1);
		if(r1==r2){
			continue;
		}
		if(r1>r2){
			se.insert({{r2+1, r1}, ind1});
		}
		else{
			se.insert({{r1+1, r2}, ind2});
		}
	}
	for(int i=0; i<n; i++){
		if(ans[i]==0){
			dfs(i, 0, 2);
		}
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]-1<<" ";
	}
	return 0;
}