#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

struct node{
	int h,i;
};
int n;
int p[maxn];
node nd[maxn];
vector<int> adj[maxn];
int s[maxn];
long long ans=0;
void dfs(int u){
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		nd[v].h=nd[u].h+1;
		dfs(v);
	}
}

bool vld=0;
void dfs2(int u){
	if(u==1) ans+=s[1];
	
	if(nd[u].h%2==0){
		long long ms=0x7FFF7FFF7FFF7FFF;
		if(adj[u].size()==0) return ;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			ms=min(ms,(long long)s[v]);
		}
		ans+=ms-s[p[u]];
		if(ms-s[p[u]]<0){
			vld=1;
		}
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			ans+=s[v]-ms;
			dfs2(v);
		}
	}else{
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			dfs2(v);
		}
	}
}
bool cmp(node a,node b){
	return a.h<b.h;
}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>p[i];
		adj[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) nd[i].i=i;
	nd[1].h=1;
	dfs(1);
	for(int i=1;i<=n;i++){
		if(nd[i].h%2==0&&s[i]!=-1){
			cout<<-1;
			return 0;
		}
		if(nd[i].h%2==1&&s[i]==-1){
			cout<<-1;
			return 0;
		}
	}
	dfs2(1);
	if(vld){
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return 0;
}////