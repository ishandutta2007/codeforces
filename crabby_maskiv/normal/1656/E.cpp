#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
vector<int> g[N];
int dep[N],deg[N];
void dfs(int u,int fa){
	for(auto v:g[u]){
		if(v==fa) continue;
		dep[v]=dep[u]^1;
		dfs(v,u);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			deg[u]++;deg[v]++;
		}
		int rt=0;
		for(i=1;i<=n;i++)
			if(deg[i]>deg[rt]) rt=i;
		dep[rt]=0;
		dfs(rt,0);
		for(i=1;i<=n;i++){
			if(!dep[i]) cout<<-deg[i]-1<<" ";
			else cout<<2*deg[i]-1<<" ";
		}
		cout<<endl;
		for(i=1;i<=n;i++){
			deg[i]=dep[i]=0;
			g[i].clear();
		}
	}
	return 0;
}