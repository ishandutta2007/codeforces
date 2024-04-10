#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxM=1e6;
int n, m, p[mxN], r[mxN], d[mxN], anc[mxN][17], da[mxN][17], db[mxN][17], av[mxM];
array<int, 4> e[mxM];
vector<array<int, 4>> ta, tb;
vector<array<int, 2>> adj[mxN];

int find(int x) {
	return x^p[x]?(p[x]=find(p[x])):x;
}

bool join(int x, int y) {
	if((x=find(x))==(y=find(y)))
		return 0;
	if(r[x]<r[y])
		swap(x, y);
	p[y]=x;
	r[x]+=r[x]==r[y];
	return 1;
}

void dfs(int u=0, int p=-1, int pw=0) {
	anc[u][0]=p;
	da[u][0]=pw;
	d[u]=~p?d[p]+1:0;
	for(int i=1; i<17; ++i) {
		if(~anc[u][i-1]) {
			anc[u][i]=anc[anc[u][i-1]][i-1];
			da[u][i]=max(da[u][i-1], da[anc[u][i-1]][i-1]);
		} else {
			anc[u][i]=-1;
			da[u][i]=da[u][i-1];
		}
	}
	for(array<int, 2> v : adj[u]) {
		if(v[0]==p)
			continue;
		dfs(v[0], u, v[1]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> e[i][1] >> e[i][2] >> e[i][0], --e[i][1], --e[i][2];
		e[i][3]=i;
	}
	sort(e, e+m);
	iota(p, p+n, 0);
	for(int i=0; i<m; ++i) {
		if(join(e[i][1], e[i][2])) {
			adj[e[i][1]].push_back({e[i][2], e[i][0]});
			adj[e[i][2]].push_back({e[i][1], e[i][0]});
			tb.push_back(e[i]);
		} else {
			ta.push_back(e[i]);
		}
	}
	dfs();
	memset(db, 0x3f, sizeof(db));
	for(array<int, 4> e : ta) {
		int u=e[1], v=e[2];
		if(d[u]<d[v])
			swap(u, v);
		int ans=0;
		for(int i=16; ~i; --i)
			if(d[u]-(1<<i)>=d[v]) {
				ans=max(ans, da[u][i]);
				db[u][i]=min(db[u][i], e[0]);
				u=anc[u][i];
			}
		//cout << u << " " << v << " " << ans << endl;
		if(u^v) {
			for(int i=16; ~i; --i) {
				if(anc[u][i]^anc[v][i]) {
					ans=max({ans, da[u][i], da[v][i]});
					db[u][i]=min(db[u][i], e[0]);
					db[v][i]=min(db[v][i], e[0]);
					u=anc[u][i];
					v=anc[v][i];
				}
			}
			ans=max({ans, da[u][0], da[v][0]});
			db[u][0]=min(db[u][0], e[0]);
			db[v][0]=min(db[v][0], e[0]);
		}
		//cout << ans << "\n";
		av[e[3]]=ans;
	}
	for(int i=16; i; --i) {
		for(int j=0; j<n; ++j) {
			db[j][i-1]=min(db[j][i-1], db[j][i]);
			if(~anc[j][i-1]) {
				db[anc[j][i-1]][i-1]=min(db[anc[j][i-1]][i-1], db[j][i]);
			}
		}
	}
	for(array<int, 4> e : tb) {
		if(d[e[1]]<d[e[2]])
			swap(e[1], e[2]);
		av[e[3]]=db[e[1]][0];
	}
	for(int i=0; i<m; ++i)
		cout << min(av[i], (int)1e9) << "\n";
}