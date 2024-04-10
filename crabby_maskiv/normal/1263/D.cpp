#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200035;
int n,m;
string s[N];
vector<int> g[N];
bool vis[N];
void bfs(int s){
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:g[u]){
			if(vis[v]) continue;
			vis[v]=1;
			q.push(v);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s[i];
		int len=s[i].length();
		for(j=0;j<len;j++){
			g[i+26].push_back(s[i][j]-'a');
			g[s[i][j]-'a'].push_back(i+26);
		}
	}
	n+=26;
	int ans=0;
	for(i=27;i<=n;i++){
		if(!vis[i]){
			ans++;
			bfs(i);
		}
	}
	cout<<ans;
	return 0;
}