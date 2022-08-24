#include <bits/stdc++.h>
#define data dkfjdskjf
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<int> d, tow;
vector<bool> relax;
const int INF = 1e9;

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	data.assign(n, {});
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		data[v-1].push_back(u-1);
	}

	int k;
	cin >> k;

	vector<int> path(k);
	for (int i = 0; i < k; ++i) {
		cin >> path[i];
		path[i]--;
	}

	d.assign(n, INF);
	tow.assign(n, -1);
	d[path.back()] = 0;
	relax.assign(n, false);

	queue<int> q;
	q.push(path.back());
	while (q.size()) {
		int W = q.front();
		q.pop();

		for (int i = 0; i < data[W].size(); ++i) {
			int to = data[W][i];
			if (d[to] > d[W] + 1) {
				d[to] = d[W]+1;
				tow[to] = W;
				q.push(to);
			}
			else if (d[to] == d[W] + 1) {
				relax[to] = true;
			}
		}
	}

	int min_ans = 0, max_ans = 0;
	for (int i = 0; i+2 < k; ++i) {
		int rem = k-i-1;
		if (relax[path[i]] || tow[path[i]] != path[i+1]) {
			max_ans++;
		}
		if (d[path[i+1]] + 1 != d[path[i]]) min_ans++;
	}
	cout << min_ans << " " << max_ans;


}