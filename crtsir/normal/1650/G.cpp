#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
vector<int>v[200003];
int dis[200003],cnt[2][200003];
int n,m;
bool vis[2][200003];
int bfs(int s,int t){
	for(int i=0;i<n;i++)dis[i]=-1,cnt[0][i]=0,cnt[1][i]=0,vis[0][i]=0,vis[1][i]=0;
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(q.size()){
		int nw=q.front();q.pop();
		for(int i=0;i<v[nw].size();i++)
			if(dis[v[nw][i]]==-1){
				dis[v[nw][i]]=dis[nw]+1;
				q.push(v[nw][i]);
			}
	}
	queue<pair<int,int> >Q;
	Q.push({s,0});
	cnt[0][s]=1;vis[0][s]=1;
	while(Q.size()){
		int nw=Q.front().first,len=Q.front().second;Q.pop();
		for(int i=0;i<v[nw].size();i++){
			if(len>dis[v[nw][i]])
				continue;
			if(vis[len+1-dis[v[nw][i]]][v[nw][i]]==0)
				Q.push(make_pair(v[nw][i],len+1));
			vis[len+1-dis[v[nw][i]]][v[nw][i]]=1;
			cnt[len+1-dis[v[nw][i]]][v[nw][i]]=(cnt[len-dis[nw]][nw]+cnt[len+1-dis[v[nw][i]]][v[nw][i]])%mod;
		}
	}
	return (cnt[0][t]+cnt[1][t])%mod;
}
void solve(){
	int s,t;
	cin>>n>>m>>s>>t;s--;t--;
	for(int i=0;i<n;i++)
		v[i].clear();
	while(m--){
		int x,y;
		cin>>x>>y;x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout<<bfs(s,t)<<endl;
}
int main(){
	int CS;
	cin>>CS;
	while(CS--)
		solve();
}