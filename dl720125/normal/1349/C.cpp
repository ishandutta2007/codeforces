#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

char c[1010][1010];
int dist[1010][1010];

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

signed main()
{
	ios::sync_with_stdio(false);
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dist[i][j]=-1;
		}
	}
	queue<pair<int,int> > q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int dir=0;dir<4;dir++){
				int nx=i+dx[dir],ny=j+dy[dir];
				if(nx<=0||ny<=0||nx>n||ny>m) continue;
				if(c[i][j]==c[nx][ny]){
					dist[i][j]=0;
					q.push(make_pair(i,j));
					break;
				}
			}
		}
	}
	while(!q.empty())
	{
		pair<int,int> t=q.front();
		q.pop();
		for(int dir=0;dir<4;dir++){
			int nx=t.first+dx[dir],ny=t.second+dy[dir];
			if(nx<=0||ny<=0||nx>n||ny>m) continue;
			if(dist[nx][ny]!=-1) continue;
			dist[nx][ny]=dist[t.first][t.second]+1;
			q.push(make_pair(nx,ny));
		}
	}
	for(int i=1;i<=t;i++){
		int x,y;long long p;
		cin>>x>>y>>p;
		if(dist[x][y]==-1){
			cout<<c[x][y]<<'\n';
			continue;
		}
		long long val=(long long)dist[x][y];
		if(p<=val) cout<<c[x][y]<<'\n';
		else{
			long long lef=p-val;
			if(c[x][y]=='0'){
				if(lef%2ll==0ll) cout<<0<<'\n';
				else cout<<1<<'\n';
			}
			else{
				if(lef%2ll==0ll) cout<<1<<'\n';
				else cout<<0<<'\n';
			}
		}
	}
	return 0;
}