#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define V vector
#define mp make_pair
const int N(111111);
V<int> adj[N];
int siz[N], fa[N], cnt[N], hsh[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	V<pair<int, int> > q;
	fa[1] = 0;
	q.pb(mp(1, 0));
	siz[1] = 1;
	int rt(-1);
	while(!q.empty()) {
		int v(q.back().fi), p(q.back().se++);
		if(p != adj[v].size()) {
			int y(adj[v][p]);
			if(y != fa[v]) {
				siz[y] = 1;
				fa[y] = v;
				q.pb(mp(y, 0));
			}
		}else {
			q.pop_back();
			if(!q.empty())
				siz[q.back().fi] += siz[v];
			if(siz[v] * 2 >= n && rt == -1)
				rt = v;
		}
	}
	q.pb(mp(rt, 0));
	memset(fa, 0, sizeof(fa));
	int tot(0);
	map<V<int>, int> bkt;
	while(!q.empty()) {
		int v(q.back().fi), p(q.back().se++);
		if(p != adj[v].size()) {
			int y(adj[v][p]);
			if(y != fa[v]) {
				fa[y] = v;
				q.pb(mp(y, 0));
			}
		}else {
			V<int> vec;
			for(int i(0); i < (int)adj[v].size(); i++) {
				int y(adj[v][i]);
				if(y != fa[v]) {
					vec.pb(hsh[y]);
				}
			}
			sort(vec.begin(), vec.end());
			if(bkt.count(vec) == 0)
				hsh[v] = bkt[vec] = ++tot;
			else 
				hsh[v] = bkt[vec];
			q.pop_back();
		}
	}
	for(int i(1); i <= n; i++)
		cnt[hsh[i]]++;
	q.pb(mp(rt, 0));
	int cur(0);
	int ans(0), ansi(rt);
	while(!q.empty()) {
		int v(q.back().fi), p(q.back().se++);
		if(p != adj[v].size()) {
			int y(adj[v][p]);
			if(y != fa[v]) {
				cur += cnt[hsh[y]] >= 2;
				if(cur > ans) {
					ans = cur;
					ansi = y;
				}
				q.pb(mp(y, 0));
			}
		}else {
			cur -= cnt[hsh[v]] >= 2;
			q.pop_back();
		}
	}
	cout << ansi << endl;
}