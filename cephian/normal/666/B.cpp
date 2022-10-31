#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > graph;

const int INF  = 0x7fffffff;
int n,m;
graph G,R;

int dist[2][3005][3005];
vector<vector<pii> > farthest[2];

queue<pii> Q;
void bfs_fill(bool w, graph& g, int s) {
	Q.push(pii(0,s));
	for(int i = 0; i < n; ++i)
		dist[w][s][i]=INF;
	dist[w][s][s]=0;
	while(!Q.empty()) {
		pii p = Q.front();
		farthest[w][s].push_back(p);
		Q.pop();
		for(int i = 0; i < g[p.second].size(); ++i) {
			int u = g[p.second][i];
			if(dist[w][s][u] == INF) {
				dist[w][s][u] = p.first+1;
				Q.push(pii(dist[w][s][u],u));
			}
		}
	}
	sort(farthest[w][s].begin(),farthest[w][s].end());
}

vector<int> fb,fc;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	G = graph(n,vector<int>());
	R = graph(n,vector<int>());
	farthest[0] = vector<vector<pii> >(n,vector<pii>());
	farthest[1] = vector<vector<pii> >(n,vector<pii>());
	for(int i = 0; i < m; ++i) {
		int a,b;
		cin >> a >> b;
		G[a-1].push_back(b-1);
		R[b-1].push_back(a-1);
	}
	for(int i = 0; i < n; ++i) {
		bfs_fill(0,G,i);
		bfs_fill(1,R,i);
	}
	int _a,_b,_c,_d;
	int best = 0;
	for(int b = 0; b < n; ++b) {
		for(int c = 0; c < n; ++c) {
			if(b == c || dist[0][b][c] == INF) continue;
			int i = farthest[1][b].size()-1;
			fb.clear();
			fc.clear();
			for(;fb.size() < 2 && i > 0; --i) {
				if(farthest[1][b][i].second == c || farthest[1][b][i].second == b) continue;
				fb.push_back(farthest[1][b][i].second);
			}
			i = farthest[0][c].size()-1;
			for(;fc.size() < 2 && i > 0;--i) {
				if(farthest[0][c][i].second == c || farthest[0][c][i].second == b) continue;
				fc.push_back(farthest[0][c][i].second);
			}
			for(int k = 0; k < fb.size(); ++k) {
				for(int l = 0; l < fc.size(); ++l) {
					int a = fb[k];
					int d = fc[l];
					if(a == d) continue;
					int dst = dist[0][a][b] + dist[0][b][c] + dist[0][c][d];
					if(dst > best) {
						_a = a;
						_b = b;
						_c = c;
						_d = d;
						best = dst;
					}
					// printf("considering %d %d %d %d\n",a+1,b+1,c+1,d+1);
				}
			}
 		}
	}
	cout << _a+1 << " " << _b+1 << " " << _c+1 << " " << _d+1 << "\n";
	return 0;
}