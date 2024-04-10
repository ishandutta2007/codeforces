#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

unordered_map<int, vi> G[100005];

int p[100005];
unordered_set<int> s[100005];

void init(int n) {
	for(int i=2;i<=n;i++)
		p[i] = i;
}

int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(s[rx].size() > s[ry].size()) swap(rx, ry);
	for(auto it:s[rx])
		s[ry].insert(it);
	p[rx] = ry;
}
bool same(int u, int v) {
	return find(u) == find(v);
}
void _add_edge(int u,int v,int c,bool i=false)
{
	auto & a = G[u][c];
	a.push_back(v);
	if (a.size() >= 2)
		unite(a[0],v);
	if (!i)
		s[find(u)].insert(v);
}
void add_edge(int u,int v,int c,bool i=false)
{
	_add_edge(u,v,c,i);
	_add_edge(v,u,c,i);
}
int main()
{
	IO_OP;
	
	int n, m, c, q;
	cin >> n >> m >> c >> q;
	init(n);
	for(int i=0;i<m;i++) {
		int u, v, cc;
		cin >> u >> v >> cc;
		add_edge(u,v,cc,1);
	}
	for (int i=1;i<=n;i++)
		for (auto it = G[i].begin(); it != G[i].end(); ++it)
			for (int j : it->second)
				s[find(i)].insert(j);
	while(q--) {
		char op;
		cin >> op;
		if(op == '+') {
			int u, v, cc;
			cin >> u >> v >> cc;
			add_edge(u,v,cc);
		} else {
			int u, v;
			cin >> u >> v;
			if(same(u, v) || s[find(u)].count(v)) {
				cout << "Yes" << '\n';
			} else{
				cout << "No" << '\n';
			}
		}
	}
	
}