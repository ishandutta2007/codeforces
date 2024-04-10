#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int n,m,p,q;
	cin>>n>>m;	
	cin>>p>>q;
	vector<string> vs(n);
	function<int(int,int)>getid=[&](int r,int c){
		assert(0<=r&&r<n);
		assert(0<=c&&c<m);
		int s=r*m+c;
		assert(0<=s&&s<n*m);
		return s;
	};
	for (int i=0;i<n;i++){
		cin>>vs[i];
		assert((int)vs[i].size()==m);		
	}
	vector<vector<pair<int,int>>>g(n*m);
	function<void(int,int,int,int,int)>addedge=[&](int r1,int c1,int r2,int c2,int cost){
		assert(0<=r1&&r1<n&&0<=c1&&c1<m);
		if(!(0<=r2&&r2<n&&0<=c2&&c2<m)){
			return;
		}
		assert(abs(r1-r2)+abs(c1-c2)==2);
		assert(!(vs[r1][c1]=='#'));
		if(vs[r2][c2]=='#'){
			return;	
		}
		int a=getid(r1,c1),b=getid(r2,c2);
		swap(a,b);
		g[a].push_back({b, cost});
	};
	for(int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if(vs[i][j]=='L'){
				// ca sa se elibereze i,j trebuie sa se elibereze i,j
				addedge(i,j,i,j+2,q);
				addedge(i,j,i+1,j+1,p);
				addedge(i,j,i-1,j+1,p);
			}
			if(vs[i][j]=='R'){
				// ca sa se elibereze i,j trebuie sa se elibereze i,j
				addedge(i,j,i,j-2,q);
				addedge(i,j,i+1,j-1,p);
				addedge(i,j,i-1,j-1,p);
			}
			if(vs[i][j]=='U'){
				addedge(i,j,i+2,j,q);
				addedge(i,j,i+1,j-1,p);
				addedge(i,j,i+1,j+1,p);
			}
			if(vs[i][j]=='D'){
				addedge(i,j,i-2,j,q);
				addedge(i,j,i-1,j-1,p);
				addedge(i,j,i-1,j+1,p);
			}
		}
	}
	
	vector<vector<int>>st(2);
	
	for (int ri=0;ri<n;ri++){
		for (int ci=0;ci<m;ci++){
			if(vs[ri][ci]=='.'){
				st[(ri+ci)%2].push_back(getid(ri,ci));
			}
		}
	}

	const ll INF=(ll)1e18+7;

	vector<vector<ll>> dist(2,vector<ll>(n*m,INF));
	for (int IT=0;IT<2;IT++){
		queue<pair<ll,int>>qq;
		for (auto &i:st[IT]){
			dist[IT][i]=0;
			qq.push({0,i});
		}
		while(!qq.empty()){
			auto iter=qq.front();
			qq.pop();
			int v=iter.second;
			if(dist[IT][v]!=-iter.first){
				continue;	
			}
			//cout<<" = "<<v/m+1<<", "<<v%m+1<<"\n";
			for (auto &it:g[v]){
				if(dist[IT][v]+it.second<dist[IT][it.first]){
					dist[IT][it.first]=dist[IT][v]+it.second;
					qq.push({-dist[IT][it.first], it.first});
				}
			}
		}
	}
	ll sol=INF;
	int dr[]={-1,0,1,0};
	int dc[]={0,1,0,-1};
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			for (int k=0;k<4;k++){
				int r=i+dr[k],c=j+dc[k];
				if(0<=r&&0<=c&&r<n&&c<m){
					int a=getid(i,j),b=getid(r,c);
					sol=min(sol,dist[0][a]+dist[1][b]);			
				}
			}
		}
	}
	if(sol==INF){
		cout<<"-1\n";
		return 0;
	}
	cout<<sol<<"\n";
	
	return 0;
}

 
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */