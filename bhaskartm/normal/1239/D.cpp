#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int n;
vector<vector<int>>g, gr;
vector<bool>used;
vector<int>order, component, scc;
vector<vector<int>>comp;

void dfs1(int v){
	used[v]=1;
	for(auto u:g[v]){
		if(!used[u]){
			dfs1(u);
		}
	}
	order.pb(v);
}

void dfs2(int v){
	used[v]=1;
	component.pb(v);
	for(auto u:gr[v]){
		if(!used[u]){
			dfs2(u);
		}
	}
}


void scc_calc(){
	used.assign(n, false);
	for(int i=0; i<n; i++){
		if(!used[i]){
			dfs1(i);
		}
	}
	used.assign(n, false);
	scc.resize(n);
	for(int i=0, cnt=0; i<n; i++){
		int v=order[n-1-i];
		if(!used[v]){
			dfs2(v);
			for(auto u:component){
				scc[u]=cnt;
			}
			comp.pb(component);
			cnt++;
			component.clear();
		}
	}
}



 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int N, m;
		cin>>N>>m;
		n=2*N;
		g.clear();
		gr.clear();
		g.resize(n);
		gr.resize(n);
		used.clear();
		order.clear();
		component.clear();
		scc.clear();
		comp.clear();

		vector<pair<int, int>>ed;
		for(int i=0; i<m; i++){
			int a, b;
			cin>>a>>b;
			a--;
			b--;
			b+=N;
			if(b-a==N){
				g[b].pb(a);
				gr[a].pb(b);
				ed.pb({b, a});
			}
			else{
				g[a].pb(b);
				gr[b].pb(a);
				ed.pb({a, b});
			}
		}
		
		scc_calc();
		
		if(n==2 || comp.size()==1){
			cout<<"No"<<endl;
			continue;
		}
		else{
			cout<<"Yes"<<endl;
		}	

		int n2=comp.size();
		
		int in[n2];
		for(int i=0; i<n2; i++){
			in[i]=0;
		}
		for(auto u:ed){
			if(scc[u.f]==scc[u.s]){
				continue;
			}
			in[scc[u.s]]++;
		}
		
		vector<int>v1;
		vector<int>v2;
		bool pre[n+1];
		for(int i=0; i<=N; i++){
			pre[i]=0;
		}
		for(int i=0; i<n2; i++){
			if(in[i]==0){
				
				for(auto u:comp[i]){
					if(u>=N){
						v2.pb(u+1-N);
						pre[u+1-N]=1;
					}
				}
				break;
			}
		}
		for(int i=1; i<=N; i++){
			if(!pre[i]){
				v1.pb(i);
			}
		}
		cout<<v1.size()<<" "<<v2.size()<<endl;
		for(auto u:v1){
			cout<<u<<" ";
		}
		cout<<endl;
		for(auto u:v2){
			cout<<u<<" ";
		}
		cout<<endl;
		
	}
	
	return 0;
}