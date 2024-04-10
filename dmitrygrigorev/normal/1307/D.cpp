#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;

const int INF = 1e9;

vector<int> dijkstra(int start) {
	int n = data.size();
	vector<int> d(n, INF);

	d[start] = 0;
	set<pair<int, int> > W;

	for (int i = 0; i < n; ++i) W.insert({d[i], i});

	for (int i = 0; i < n; ++i) {
		auto it = W.begin();
		auto p = (*it);
		W.erase(it);

		int dist = p.first, vertex = p.second;
		for (int j = 0; j < data[vertex].size(); ++j) {
			int to = data[vertex][j];
			if (dist + 1 < d[to]) {
				W.erase(W.find({d[to], to}));
				d[to] = dist+1;
				W.insert({d[to], to});
			}
		}

	}

	return d;

}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	data.assign(n, {});
	vector<int> spec(k);
	for (int i = 0; i < k; ++i) cin >> spec[i];

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v), data[v].push_back(u);
	}

	vector<int> a = dijkstra(0);
	vector<int> b = dijkstra(n-1);


	vector<pair<int, int> > arr;
	for (int i = 0; i < k; ++i) {
		arr.push_back({a[spec[i]-1], spec[i]-1});
	}

	sort(arr.begin(), arr.end());


	int longest = -INF, res = -INF;
	for (int i = k-1; i >= 0; i--) {
		//cout << longest << " " << arr[i].first << endl;
		res = max(res, longest + 1 + arr[i].first);
		longest = max(longest, b[arr[i].second]);
	}

	cout << min(res, a[n-1]);




}