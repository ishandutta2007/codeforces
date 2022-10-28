#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

int n;
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}
vector<vector<int>>adj;
vector<vector<int>>comps;
vector<int>fu;
int vis[100005];

void dfs(int v){
	vis[v]=1;
	fu.push_back(v);
	for(auto u:adj[v]){
		if(vis[u]==0){
			dfs(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, m;
	cin>>N>>m;
	adj.resize(N);
	vector<pair<pair<int, int>, int>>edge;
	for(int i=0; i<m; i++){
		int u,v;
		char c;
		cin>>u>>v>>c;
		u--;
		v--;
		if(c=='R'){
			edge.push_back({{u, v}, 1});
		}
		else{
			edge.push_back({{u, v}, 0});
		}
	}
	for(auto u:edge){
		adj[u.first.first].push_back(u.first.second);
		adj[u.first.second].push_back(u.first.first);
	}
	for(int i=0; i<N; i++){
		if(vis[i]==0){
			dfs(i);
			comps.push_back(fu);
			fu.clear();
		}
	}
	n=2*N;
	g.resize(n);
	gt.resize(n);
	for(auto u:edge){
		int u1=u.f.f;
		int u2=u.f.s;
		if(u.s==0){
			g[2*u1].pb(2*u2);
			g[2*u1+1].pb(2*u2+1);
			g[2*u2].pb(2*u1);
			g[2*u2+1].pb(2*u1+1);
			gt[2*u2].pb(2*u1);
			gt[2*u2+1].pb(2*u1+1);
			gt[2*u1].pb(2*u2);
			gt[2*u1+1].pb(2*u2+1);
		}
		else{
			g[2*u1+1].pb(2*u2);
			g[2*u2+1].pb(2*u1);
			g[2*u1].pb(2*u2+1);
			g[2*u2].pb(2*u1+1);
			gt[2*u2].pb(2*u1+1);
			gt[2*u1].pb(2*u2+1);
			gt[2*u2+1].pb(2*u1);
			gt[2*u1+1].pb(2*u2);
		}
	}
	
	bool booly1=solve_2SAT();
	
	int val1[N];
	for(int i=0; i<N; i++){
		val1[i]=assignment[i];
	}
	vector<int>ans1;
	for(int i=0; i<comps.size(); i++){
		vector<int>one;
		vector<int>zero;
		for(int j=0; j<comps[i].size(); j++){
			if(val1[comps[i][j]]==0){
				zero.pb(comps[i][j]);
			}
			else{
				one.pb(comps[i][j]);
			}
		}
		if(zero.size()>one.size()){
			for(auto u:one){
				ans1.pb(u);
			}
		}
		else{
			for(auto u:zero){
				ans1.pb(u);
			}
		}
	}
	g.clear();
	gt.clear();
	used.clear();
	order.clear();
	comp.clear();
	assignment.clear();
	g.resize(n);
	gt.resize(n);
	
	for(auto u:edge){
		int u1=u.f.f;
		int u2=u.f.s;
		if(u.s==1){
			
			g[2*u1].pb(2*u2);
			g[2*u1+1].pb(2*u2+1);
			g[2*u2].pb(2*u1);
			g[2*u2+1].pb(2*u1+1);
			gt[2*u2].pb(2*u1);
			gt[2*u2+1].pb(2*u1+1);
			gt[2*u1].pb(2*u2);
			gt[2*u1+1].pb(2*u2+1);
		}
		else{
			g[2*u1+1].pb(2*u2);
			g[2*u2+1].pb(2*u1);
			g[2*u1].pb(2*u2+1);
			g[2*u2].pb(2*u1+1);
			gt[2*u2].pb(2*u1+1);
			gt[2*u1].pb(2*u2+1);
			gt[2*u2+1].pb(2*u1);
			gt[2*u1+1].pb(2*u2);
		}
	}
	bool booly2=solve_2SAT();
	
	int val2[N];
	for(int i=0; i<N; i++){
		val2[i]=assignment[i];
	}
	vector<int>ans2;
	for(int i=0; i<comps.size(); i++){
		vector<int>one;
		vector<int>zero;
		for(int j=0; j<comps[i].size(); j++){
			if(val2[comps[i][j]]==0){
				zero.pb(comps[i][j]);
			}
			else{
				one.pb(comps[i][j]);
			}
		}
		if(zero.size()>one.size()){
			for(auto u:one){
				ans2.pb(u);
			}
		}
		else{
			for(auto u:zero){
				ans2.pb(u);
			}
		}
	}
	if(!booly1 && !booly2){
		cout<<-1;
		return 0;
	}
	if(booly1 && !booly2){
		cout<<ans1.size()<<endl;
		for(auto u:ans1){
			cout<<u+1<<" ";
		}
		return 0;
	}
	if(!booly1 && booly2){
		cout<<ans2.size()<<endl;
		for(auto u:ans2){
			cout<<u+1<<" ";
		}
		return 0;
	}
	if(ans1.size()<ans2.size()){
		cout<<ans1.size()<<endl;
		for(auto u: ans1){
			cout<<u+1<<" ";
		}
		return 0;
	}
	else{
		cout<<ans2.size()<<endl;
		for(auto u:ans2){
			cout<<u+1<<" ";
		}
		return 0;
	}
	return 0;
}