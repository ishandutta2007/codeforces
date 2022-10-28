#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


vector<vector<int>>nums;
int r, c;
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

int fu(int i, int j){
	if(nums[i][j]==-1){
		cout<<i<<" "<<j<<endl;
	}
	return nums[i][j];
}
 

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>r>>c;
	nums.resize(r);
	for(int i=0; i<r; i++){
		nums[i].resize(c);
	}
	
	char arr[r][c];
	
	int pt=0;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>arr[i][j];
			if(arr[i][j]=='.'){
				nums[i][j]=-1;
			}
			else{
				nums[i][j]=pt;
				pt++;
			}
		}
	}
	
	
	n=pt;
	g.resize(n);
	gr.resize(n);
	
	bool che=0;
	for(int i=0; i<c; i++){
		int x;
		cin>>x;
		if(x!=0){
			che=1;
		}
	}
	if(che==0){
		cout<<0;
		return 0;
	}
	
	int lo[r][c];
	
	for(int i=0; i<c; i++){
		int la=-1;
		for(int j=r-1; j>=0; j--){
			lo[j][i]=la;
			if(arr[j][i]=='#'){
				la=j;
			}
		}
	}
	
	
	
	
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(arr[i][j]=='.'){
				continue;
			}
			if(j!=0){
				if(arr[i][j-1]=='#'){
					g[fu(i, j)].pb(fu(i, j-1));
				
					
				}
				else{
					int num=lo[i][j-1];
					if(num!=-1){
						g[fu(i, j)].pb(fu(num, j-1));
						
					}
				}
			}
			if(j!=(c-1)){
				if(arr[i][j+1]=='#'){
					g[fu(i, j)].pb(fu(i, j+1));
					
				}
				else{
					int num=lo[i][j+1];
					if(num!=-1){
						g[fu(i, j)].pb(fu(num, j+1));
						
					}
				}
			}
			if(i!=0 && arr[i-1][j]=='#'){
				g[fu(i, j)].pb(fu(i-1, j));
			}
			int num=lo[i][j];
			if(num!=-1){
				g[fu(i, j)].pb(fu(num, j));
			}
		}
	}
	
	vector<pair<int, int>>ed;
	
	for(int i=0; i<pt; i++){
		for(auto u:g[i]){
			gr[u].pb(i);
			//cout<<u<<" "<<i<<endl;
			ed.pb({i, u});
		}
	}

	scc_calc();
	
	int deg[pt];
	for(int i=0; i<pt; i++){
		deg[i]=0;
	}
	
	
	for(auto u:ed){
		
		if(scc[u.f]!=scc[u.s]){
			deg[scc[u.s]]++;
		}
	}
	int ans=0;
	for(int i=0; i<comp.size(); i++){
		if(deg[i]==0){
			ans++;
		}
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}