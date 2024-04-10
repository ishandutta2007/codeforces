#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
vector<int> g[N];
queue<int> q;
int deg[N];
int d[N];
vector<int> ans;
int main(){
//	freopen("c2.in","r",stdin);
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++) g[i].clear();
		ans.clear();
		for(i=1;i<=n;i++) deg[i]=d[i]=0;
		for(i=1;i<=m;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			deg[v]++;
		}
		for(i=1;i<=n;i++){
			if(!deg[i])
				q.push(i);
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			if(d[u]==2){
				ans.push_back(u);
				d[u]=-1;
			}
			for(auto v:g[u]){
				deg[v]--;
				d[v]=max(d[v],d[u]+1);
				if(!deg[v]) q.push(v);
			}
		}
		cout<<ans.size()<<endl;
		for(auto x:ans) cout<<x<<" ";		
	}

	return 0;
}