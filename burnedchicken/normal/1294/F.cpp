#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
int n,x,y,nd1,nd2,nd3,dist[200005],Max,father[200005],ans=0;
vector<int> adj[200005],vec;
queue<int> q;
bool visited[200005];
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n-1){
		cin >> x >> y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rep(200005) visited[i]=false;
	q.push(0);
	visited[0]=true;
	dist[0]=0;
	Max=0;
	while(!q.empty()){
		x=q.front();
		rep(adj[x].size()){
			y=adj[x][i];
			if(visited[y]) continue;
			q.push(y);
			visited[y]=true;
			dist[y]=dist[x]+1;
			if(dist[y]>Max){
				Max=dist[y];
				nd1=y;
			}
		}
		q.pop();
	}
	rep(200005) visited[i]=false;
	q.push(nd1);
	visited[nd1]=true;
	dist[nd1]=0;
	father[nd1]=-1;
	Max=0;
	while(!q.empty()){
		x=q.front();
		rep(adj[x].size()){
			y=adj[x][i];
			if(visited[y]) continue;
			q.push(y);
			visited[y]=true;
			dist[y]=dist[x]+1;
			father[y]=x;
			if(dist[y]>Max){
				Max=dist[y];
				nd2=y;
			}
		}
		q.pop();
	}
	ans=dist[nd2];
	vec.pb(nd2);
	x=nd2;
	while(1){
		x=father[x];
		vec.pb(x);
		if(x==nd1) break;
	}
	rep(200005) visited[i]=false;
	rep(vec.size()){
		q.push(vec[i]);
		visited[vec[i]]=true;
		dist[vec[i]]=0;
	}
	Max=0;
	while(!q.empty()){
		x=q.front();
		rep(adj[x].size()){
			y=adj[x][i];
			if(visited[y]) continue;
			q.push(y);
			visited[y]=true;
			dist[y]=dist[x]+1;
			if(dist[y]>Max){
				Max=dist[y];
				nd3=y;
			}
		}
		q.pop();
	}
	if(Max==0){
		rep(200005){
			if(nd1==i||nd2==i) continue;
			else{
				nd3=i;
				break;
			}
		}
	}
	else ans+=dist[nd3];
	cout << ans << '\n' << nd1+1 << ' ' << nd2+1 << ' ' << nd3+1 << '\n';
	return 0;
}