#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class Hopcroft {
	static const int N = 22000;

	int cnt,pos[N],neg[N];
public:
	int gao(int n, const vector<vector<int>> &e) {
		std::fill(pos,pos+n,-1);
		std::fill(neg,neg+n,-1);

		for(int x=cnt=0,y; x<n; x++) {
			for(size_t i=0; i<e[x].size(); i++) {
				if(~neg[y=e[x][i]]) continue;
				pos[neg[y]=x]=y;
				cnt++;
				break;
			}
		}

		while(true) {
			int push=0,pop=0,ok=0;
			std::fill(lx,lx+n,-1);
			std::fill(ly,ly+n,-1);
			for(int x=0; x<n; x++) if(pos[x]<0) lx[q[push++]=x]=0;

			while(push!=pop) {
				int x=q[pop++],y;

				for(size_t i=0; i<e[x].size(); i++) {
					if(~ly[y=e[x][i]]) continue;
					ly[y]=1+lx[x];
					if(~neg[y] && ~lx[neg[y]]) continue;
					if(~neg[y]) lx[q[push++]=neg[y]]=1+ly[y];
					else ok=1;
				}
			}

			if(!ok) return cnt;
			for(int x=0; x<n; x++) if(pos[x]<0 && aug(x,e)) cnt++;

		}
	}
	
private:
	int lx[N],ly[N],q[N];

	bool aug(int x, const vector<vector<int>> &e) {
		int c=lx[x]+1,y=lx[x]=-1;

		for(size_t i=0; i<e[x].size(); i++) if(ly[y=e[x][i]]==c) {
				ly[y]=-1;
				if(~neg[y] && !aug(neg[y],e)) continue;
				pos[neg[y]=x]=y;
				return true;
			}

		return false;
	}
} flow;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> E;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		E.emplace_back(w, u, v);
	}
	sort(E.begin(), E.end());
	int lo = n - 1, hi = m + 1;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		vector<vector<int>> adj(n);
		for (int j = 0; j < mid; j++) {
			adj[get<1>(E[j])].push_back(get<2>(E[j]));
		}
		if (flow.gao(n, adj) != n) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	if (hi <= m) {
		return cout << get<0>(E[hi - 1]) << '\n', 0;
	}
	return cout << -1 << '\n', 0;
}