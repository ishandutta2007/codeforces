#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007 
using namespace __gnu_pbds;
using namespace std;

int n,m,cnt,ans,s,t;
char c[210][210];
map<pair<pair<int,int>,pair<int,int> >,int> mp;

vector<pair<pair<int,int>,int> > g[100010];
int lvl[100010],r[100010]; 

inline void add_edge(int x,int y,int c)
{
	g[x].push_back(make_pair(make_pair(y,c),g[y].size()));
	g[y].push_back(make_pair(make_pair(x,0),g[x].size()-1));
}

inline void bfs(int x)
{
	memset(lvl,-1,sizeof(lvl));
	queue<int> q;
	lvl[x]=0;
	q.push(x);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			pair<pair<int,int>,int> e=g[u][i];
			if(e.first.second>0&&lvl[e.first.first]==-1){
				lvl[e.first.first]=lvl[u]+1;
				q.push(e.first.first);
			}
		}
	}
}
		
inline int dfs(int now,int cap)
{ 
	if(now==t){
		return cap;
	}
	for(int i=r[now];i<g[now].size();i++,r[now]++){
		pair<pair<int,int>,int> e=g[now][i];
		if(e.first.second>0&&(lvl[now]<lvl[e.first.first])){
			int dis=dfs(e.first.first,min(cap,e.first.second));
			if(dis>0){
				g[now][i].first.second-=dis;
				g[e.first.first][e.second].first.second+=dis;
				return dis;
			}
		}
	}
	return 0;
}

inline int max_flow()
{
	int flow=0;
	while(true){
		bfs(s);
		if(lvl[t]==-1) return flow;
		memset(r,0,sizeof(r));
		int f=dfs(s,INF);
		while(f>0){
			flow+=f;
			f=dfs(s,INF);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			if(c[i][j]=='#') ans++;
		}
	}
	s=1;t=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(c[i][j]=='#'){
			if(i<n){
				if(c[i+1][j]=='#'){
					cnt++;
					mp[make_pair(make_pair(i,j),make_pair(i+1,j))]=cnt;
					mp[make_pair(make_pair(i+1,j),make_pair(i,j))]=cnt;
					add_edge(s,cnt+2,1);
				}
			}
			if(j<m){
				if(c[i][j+1]=='#'){
					cnt++;
					mp[make_pair(make_pair(i,j),make_pair(i,j+1))]=cnt;
					mp[make_pair(make_pair(i,j+1),make_pair(i,j))]=cnt;
					add_edge(cnt+2,t,1);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[make_pair(make_pair(i,j),make_pair(i-1,j))]){
				int x=mp[make_pair(make_pair(i,j),make_pair(i-1,j))];
				if(mp[make_pair(make_pair(i,j),make_pair(i,j-1))]){
					int y=mp[make_pair(make_pair(i,j),make_pair(i,j-1))];
					add_edge(x+2,y+2,1); 
				}
				if(mp[make_pair(make_pair(i,j),make_pair(i,j+1))]){
					int y=mp[make_pair(make_pair(i,j),make_pair(i,j+1))];
					add_edge(x+2,y+2,1); 
				}
			}
			if(mp[make_pair(make_pair(i,j),make_pair(i+1,j))]){
				int x=mp[make_pair(make_pair(i,j),make_pair(i+1,j))];
				if(mp[make_pair(make_pair(i,j),make_pair(i,j-1))]){
					int y=mp[make_pair(make_pair(i,j),make_pair(i,j-1))];
					add_edge(x+2,y+2,1); 
				}
				if(mp[make_pair(make_pair(i,j),make_pair(i,j+1))]){
					int y=mp[make_pair(make_pair(i,j),make_pair(i,j+1))];
					add_edge(x+2,y+2,1); 
				}
			}
		}
	}
	ans-=cnt-max_flow();
	cout<<ans<<endl;
	return 0;
}