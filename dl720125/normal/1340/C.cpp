#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

int n,m,d[10010],G,R,dist[10010][1010];
pair<int,int> l[10010][1010],r[10010][1010];
bool vis[10010][1010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>d[i];
	cin>>G>>R;
	sort(d+1,d+m+1);
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int i=1;i<=m;i++){
		for(int j=0;j<=G;j++){
			if(i>1){
				int len=d[i]-d[i-1];
				if(j+len<G) l[i][j]=make_pair(j+len,0);
				else if(j+len==G) l[i][j]=make_pair(0,1);
			}
			if(i<m){
				int len=d[i+1]-d[i];
				if(j+len<G) r[i][j]=make_pair(j+len,0);
				else if(j+len==G){
					if(i+1<m) r[i][j]=make_pair(0,1);
					else r[i][j]=make_pair(G,0);
				}
			}
		}
	}
	int ans=INF;
	deque<pair<int,int> > q;
	for(int i=1;i<=m;i++) for(int j=0;j<=G;j++) dist[i][j]=INF;
	memset(vis,0,sizeof(vis));
	dist[1][0]=0;vis[1][0]=1;
	q.push_back(make_pair(1,0));
	while(!q.empty())
	{
		pair<int,int> t=q.front();q.pop_front();
		if(t.first==m){
			ans=min(ans,dist[t.first][t.second]*(G+R)+t.second);
			continue;
		}
		if(l[t.first][t.second].first!=-1){
			int pos=l[t.first][t.second].first;
			int dis=l[t.first][t.second].second;
			if(!vis[t.first-1][pos]){
				vis[t.first-1][pos]=1;
				dist[t.first-1][pos]=dist[t.first][t.second]+dis;
				if(dis==0) q.push_front(make_pair(t.first-1,pos)); 
				else q.push_back(make_pair(t.first-1,pos));
			}
		}
		if(r[t.first][t.second].first!=-1){
			int pos=r[t.first][t.second].first;
			int dis=r[t.first][t.second].second;
			if(!vis[t.first+1][pos]){
				vis[t.first+1][pos]=1;
				dist[t.first+1][pos]=dist[t.first][t.second]+dis;
				if(dis==0) q.push_front(make_pair(t.first+1,pos));
				else q.push_back(make_pair(t.first+1,pos));
			}
		}
	}
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}