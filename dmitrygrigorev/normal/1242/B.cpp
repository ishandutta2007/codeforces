#include <bits/stdc++.h>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 100007;

set<int> data[N];

set<int> unused;

void dfs(int vertex){
	int last = -1;
	while (true){
		auto it = unused.upper_bound(last);
		if (it==unused.end()) return;
		int W = (*it);
		if (data[vertex].count(W)){
			last = W;
			continue;
		}
		unused.erase(unused.find(W));
		dfs(W);
	}
}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i=0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].insert(v), data[v].insert(u);
	}

	for (int i=0;i<n;++i) unused.insert(i);

	int cmp = 0;

	for (int i=0;i<n;++i){
		if (unused.count(i)){
			dfs(i);
			cmp++;
		}
	}

	cout << cmp-1;

	


}