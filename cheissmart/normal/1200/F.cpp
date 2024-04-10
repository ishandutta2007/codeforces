#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, M = 2520;

int a[1024], e[11], ans[1024][M], vis[1024][M], n, u, v, cans;
pi G[1024][M];
vector<pi> p;
set<int> st;

void dfs(int i, int j) {
	vis[i][j] = 1;
	p.EB(i, j);
	u = G[i][j].F, v = G[i][j].S;
	if(!vis[u][v]){
		dfs(u, v);
	} else if(vis[u][v] == 2) {
		for(pi pp:p)
			ans[pp.F][pp.S] = ans[u][v];
	} else {
		st.clear();
		for(int pos=(int)p.size()-1;pos>=0;pos--) {
			st.insert(p[pos].F);
			if(p[pos] == MP(u, v)) 
				break;
		}
		cans = st.size();
		for(pi pp:p)
			ans[pp.F][pp.S] = cans;
	}
	vis[i][j] = 2;
}

int main()
{
	IO_OP;
	
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		a[i] = (a[i] % M + M) % M;
	}
	for(int i=1;i<=n;i++) {
		int m;
		cin >> m;
		for(int j=0;j<m;j++)
			cin >> e[j];
		for(int k=0;k<M;k++) {
			G[i][k] = {e[(a[i]+k)%m], (a[i]+k) % M};
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		y = (y % M + M) % M;
		if(!vis[x][y]) {
			p.clear();
			dfs(x, y);
		}
		cout << ans[x][y] << endl;
	}

	
}