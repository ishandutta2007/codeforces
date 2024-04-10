#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int inf=0x3f3f3f3f;
int n,m,k;
vector<int> g[N],_g[N];
int a[N];
int d[N];
int s,t;
void bfs(){
	queue<int> q;q.push(t);
	d[t]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:_g[u]){
			if(!d[v]){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		_g[y].push_back(x);
	}
	cin>>k;
	for(i=1;i<=k;i++) cin>>a[i];
	s=a[1];t=a[k];
	bfs();
	int mn=0,mx=0;
	for(i=1;i<k;i++){
		if(d[a[i+1]]==d[a[i]]-1){
			for(auto v:g[a[i]])
				if(v!=a[i+1]&&d[v]==d[a[i]]-1){
					mx++;
					break;
				}
		}
		else{
			mn++;
			mx++;
		}
	}
	cout<<mn<<" "<<mx;
	return 0;
}