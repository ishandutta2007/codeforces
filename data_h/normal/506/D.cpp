#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int LIMIT = 200;
const int N = 111111;

int n, m;
int father[N];
vector<pair<int, pair<int, int> > > edges;

int qa[N], qb[N], answer[N];
vector<int> e[N];
int visit[N];
map<pair<int, int>, int> mv;

int find(int x) {
	if (x == father[x]) {
		return x;
	} else {
		return father[x] = find(father[x]);
	}
}

void dfs(int x) {
	if (visit[x]) {
		return ;
	}
	visit[x] = 1;
	for(int i = 0; i < (int)e[x].size(); i++) {
		dfs(e[x][i]);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(make_pair(c, make_pair(a, b)));
	}
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		scanf("%d %d", &qa[i], &qb[i]);
	}
	sort(edges.begin(), edges.end());
	for(int i = 0, j; i < (int)edges.size(); i = j) {
		for(j = i; j < (int)edges.size() && edges[i].first == edges[j].first; j++) {
		}
		int number = j - i;
		if (number >= LIMIT) {
			for(int k = 1; k <= n; k++) {
				father[k] = k;
			}
			for(int k = i; k < j; k++) {
				int a = find(edges[k].second.first), b = find(edges[k].second.second);
				if (a != b) {
					father[a] = b;
				}
			}
			for(int k = 1; k <= q; k++) {
				int a = find(qa[k]), b = find(qb[k]);
				if (a == b) {
					answer[k]++;
				}
			}
		} else {
			static vector<int> vecs;
			vecs.clear();
			for(int k = i; k < j; k++) {
				vecs.push_back(edges[k].second.first);
				vecs.push_back(edges[k].second.second);
			}
			sort(vecs.begin(), vecs.end());
			vecs.erase(unique(vecs.begin(), vecs.end()), vecs.end());
			for(int k = 0; k < (int)vecs.size(); k++) {
				e[k].clear();
			}
			for(int k = i; k < j; k++) {
				int a = lower_bound(vecs.begin(), vecs.end(), edges[k].second.first) - vecs.begin();
				int b = lower_bound(vecs.begin(), vecs.end(), edges[k].second.second) - vecs.begin();
				e[a].push_back(b);
				e[b].push_back(a);
			}
			//printf("!! %d\n", mv[make_pair(2, 5)]);
			for(int k = 0; k < (int)vecs.size(); k++) {
				for(int l = 0; l < (int)vecs.size(); l++) {
					visit[l] = 0;
				}
				dfs(k);
				for(int l = 0; l < (int)vecs.size(); l++) {
					if (visit[l]) {
						mv[make_pair(vecs[k], vecs[l])]++;
					}
				}
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		printf("%d\n", answer[i] + mv[make_pair(qa[i], qb[i])]);
	}
	return 0;
}