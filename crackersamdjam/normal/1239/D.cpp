#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e6+5;

int tc, n, m;
vector<int> adj[MM];
int dfn[MM], low[MM], t, id[MM], sccid;
bool ins[MM];
stack<int> stk;

void dfs(int cur){
	
	dfn[cur] = low[cur] = ++t;
	ins[cur] = 1;
	stk.push(cur);

	for(int u: adj[cur]){
		if(!dfn[u]){
			dfs(u);
			low[cur] = min(low[cur], low[u]);
		}
		else if(ins[u])
			low[cur] = min(low[cur], dfn[u]);
	}
	
	if(low[cur] == dfn[cur]){
		int u = -1;
		sccid++;
		while(u != cur){
			u = stk.top(); stk.pop();
			id[u] = sccid;
			ins[u] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>tc;
	while(tc--){
		cin>>n>>m;

		t = sccid = 0;
		for(int i = 1; i <= n; i++){
			dfn[i] = low[i] = id[i] = ins[i] = 0;
			adj[i].clear();
		}

		for(int i = 0,a,b; i < m; i++){
			cin>>a>>b;
			adj[a].emplace_back(b);
		}

		for(int i = 1; i <= n; i++){
			if(!dfn[i])
				dfs(i);
		}
		if(sccid > 1){
			vector<int> va, vb;
			cout<<"Yes\n";
			for(int i = 1; i <= n; i++){
				if(id[i] == 1)
					va.emplace_back(i);
				else
					vb.emplace_back(i);
			}
			cout<<size(va)<<' '<<size(vb)<<'\n';
			for(int i: va)
				cout<<i<<' ';
			cout<<'\n';
			for(int i: vb)
				cout<<i<<' ';
			cout<<'\n';
		}
		else{
			cout<<"No\n";
		}
	}
}