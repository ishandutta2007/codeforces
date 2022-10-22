#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
vector<int> g[N];
int deg[N],fa[N],lv[N];
void dfs(int u){
	for(auto v:g[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs(v);
	}
}
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++){
			deg[i]=fa[i]=lv[i]=0;
			g[i].clear();
		}
		for(i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		for(i=2;i<=n;i++) deg[fa[i]]++;
		for(i=2;i<=n;i++){
			if(deg[i]==0)
				lv[fa[i]]++;
		}
		queue<int> q;
		for(i=1;i<=n;i++) if(lv[i]==deg[i]&&lv[i]) q.push(i);
		int answ=0;
		while(!q.empty()){
			int u=q.front();q.pop();
		//	cerr<<u<<endl;
			answ+=lv[u];answ--;
			deg[fa[u]]--;
			if(!deg[fa[u]]){
				if(fa[u]==1) break;
				lv[fa[fa[u]]]++;
				if(lv[fa[fa[u]]]==deg[fa[fa[u]]])
					q.push(fa[fa[u]]);
			}
			else{
				if(lv[fa[u]]==deg[fa[u]])
					q.push(fa[u]);
			}
		}
		answ++;
		cerr<<"answ = ";
		cout<<answ<<endl;
	}
	return 0;
}