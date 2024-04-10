/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
vector <int> g[N];
int cnt[N];
bool vis[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	set <pair <int, int>> nv;
	for (int i = 0; i < n; i++) {
		nv.insert(make_pair(0, i));
	}
	vector <int> ans;
	int cn = 0;
	while (!nv.empty()) {
		set <int> st;
		int so = (*nv.begin()).S;
		queue <int> q;
		q.push(so);
		vis[so] = true;
		nv.erase(make_pair(cnt[so], so));
		while (!q.empty()) {
			int x = q.front();
			cn++;
			q.pop();
			st.insert(x);
			for (auto y : g[x]) {
				if (!nv.count(make_pair(cnt[y], y)))
					continue;
				nv.erase(make_pair(cnt[y], y)); 
				cnt[y]++;
				nv.insert(make_pair(cnt[y], y)); 
			}
			while (!nv.empty()) {
				pair <int, int> p = (*nv.begin());
				if (p.F >= cn)
					break;
				nv.erase(p);
				q.push(p.S);
			}
		}
		ans.push_back(st.size());
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto st : ans) {
		cout << st << ' ';
	//	for (auto x : st) {
	//		cout << x + 1 << ' ';
	//	}
	}
}