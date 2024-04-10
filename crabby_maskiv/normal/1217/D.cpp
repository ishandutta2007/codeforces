#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll mod=1000000007ll;
int n,m;
vector<int> g[N];
bool flag;
bool vis1[N],vis2[N];
int dfn[N],cnt;
int U[N],V[N];
void dfs1(int cur){
	dfn[cur]=++cnt;
	vis1[cur]=1;
	for(auto v:g[cur]){
		if(vis2[v]) continue;
		if(vis1[v]) flag=1;
		else dfs1(v);
	}
	vis2[cur]=1;
}
int main() {
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		U[i]=x;V[i]=y;
		g[x].push_back(y);
	}
	for(i=1;i<=n;i++) if(!vis1[i]) dfs1(i);
	if(!flag){
		cout<<1<<endl;
		for(i=1;i<=m;i++) cout<<"1 ";
		return 0;
	}
	cout<<2<<endl;
	for(i=1;i<=m;i++){
		if(dfn[U[i]]>dfn[V[i]]) cout<<"1 ";
		else cout<<"2 ";
	}
    return 0;
}