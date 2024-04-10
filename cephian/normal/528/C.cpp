#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vi odd;

// ----- UNDIRECTED GRAPH -----
struct euler_path {
	vi e1,e2;
	vvi G;
	vector<bool> used = {};

	euler_path(){}
	euler_path(int N):G(N){}
	euler_path(int N, int M):G(N){used.reserve(M);}

	void get_path(vi& path, int v = 0) {
		while(G[v].size()) {
			int i = G[v].back();
			G[v].pop_back();
			if(used[i]) continue;
			used[i] = 1;
			int u = (v==e1[i])?e2[i]:e1[i];
			get_path(path,u);
		}
		path.push_back(v);
	}

	inline void add_edge(int u, int v) {
		G[u].push_back(e1.size()), G[v].push_back(e2.size());
		e1.push_back(u), e2.push_back(v);
		used.push_back(0);
	}
};

euler_path e;

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	euler_path e(n);
	for(int i = 0; i < m; ++i) {
		int u,v;
		scanf("%d%d",&u,&v),--u,--v;
		e.add_edge(u,v);
	}

	for(int i = 0; i < n; ++i)
		if(e.G[i].size()&1)
			odd.pb(i);
	while(odd.size()) {
		int a = odd.back(); odd.pop_back();
		int b = odd.back(); odd.pop_back();
		e.add_edge(a,b);
	}
	if(e.e1.size()&1)
		e.add_edge(0,0);
	vi path;
	e.get_path(path);
	
	printf("%d\n",(int)e.e1.size());
	for(int i = 1; i < path.size(); ++i) {
		if(i&1)
			printf("%d %d\n",path[i-1]+1,path[i]+1);
		else
			printf("%d %d\n",path[i]+1,path[i-1]+1);
	}
}