#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
vector<int> adj[maxn];
long long a[maxn],b[maxn];
int k[maxn];
int fa[maxn];
bool ok=1;

void dfs(int u){
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		fa[v]=u;
		dfs(v);
	}
	if(fa[u]==0){
		if(a[u]<0)ok=0;
	}else{
		if(a[u]<0){
			if((a[fa[u]]+1e17)/k[u]<0-a[u])ok=0;
			a[fa[u]]-=-a[u]*k[u];
		}else a[fa[u]]+=a[u];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)a[i]-=b[i];
	for(int i=2;i<=n;i++){
		int fa;
		cin>>fa>>k[i];
		adj[fa].push_back(i);
	}
	dfs(1);
	cout<<(ok?"YES":"NO");
	return 0;
}