#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	int a[n],ans[n];
	loop(n) cin >> a[i];
	loop(n) ans[i]=1e9;
	vector<int> adj[n];
	loop(n){
		if(i-a[i]>=0) adj[i-a[i]].push_back(i);
		if(i+a[i]<n) adj[i+a[i]].push_back(i);
	}
	queue<int> bfs;
	bool visited[n];
	loop(n) visited[i]=false;
	loop(n){
		if(i-a[i]>=0) if((a[i-a[i]]-a[i])%2!=0) ans[i]=1;
		if(i+a[i]<n) if((a[i+a[i]]-a[i])%2!=0) ans[i]=1;
		if(ans[i]==1){
			bfs.push(i);
			visited[i]=true;
		}
	}
	int x,y;
	while(!bfs.empty()){
		x=bfs.front();
		loop(adj[x].size()){
			if(visited[adj[x][i]]) continue;
			ans[adj[x][i]]=ans[x]+1;
			visited[adj[x][i]]=true;
			bfs.push(adj[x][i]);
		}
		bfs.pop();
	}
	loop(n) if(!visited[i]) ans[i]=-1;
	loop(n) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}