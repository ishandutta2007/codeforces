#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<tuple<int, int, int> > > gr;

main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> d(n, 1e18);
	d[0] = 0;

	gr.assign(n, {});
	for (int i = 0; i < m; ++i) {
		int u, v, x;
		cin >> u >> v >> x;
		u--, v--;
		gr[u].push_back(make_tuple(v, x, 0));
		gr[v].push_back(make_tuple(u, x, 0));
	}

	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		gr[0].push_back(make_tuple(--a, b, 1));
		gr[a].push_back(make_tuple(0, b, 1));
	}

	set<pair<int, int> > kek;

	for (int i = 0; i < n; ++i) kek.insert(make_pair(d[i], i));
	while (kek.size()) {
		auto p = *kek.begin();
		kek.erase(kek.begin());
		auto w = p.second;

		for (int i = 0; i < gr[w].size(); ++i) {
			int to = get<0>(gr[w][i]);
			int e = get<1>(gr[w][i]);
			if (e + d[w] < d[to]) {
				kek.erase(kek.find(make_pair(d[to], to)));
				kek.insert(make_pair(e+d[w], to));
				d[to] = e + d[w];
			}
		}
	}

	int res = 0;

	vector<int> eq(n, 0);
	vector<int> spec(n, 0);

	for (int i = 0; i < n; ++i) {
		for (auto p : gr[i]) {
			int tp = get<2>(p);
			int to = get<0>(p);
			int w = get<1>(p);
			if (d[to] <= d[i]) continue;
			//cout << i << " " << to << " " <<w << " " << tp << " " << d[i] << " " << d[to] << "\n";
			if (d[to] == w+d[i]) {
				if (tp==1) eq[to]++;
				else spec[to]++;
			}
			else if (tp==1 && i==0) {
				res++;
				//cout << to << " " << d[to] << " " << w << endl;
			}
		}
	}

	//cout << res << endl;

	for (int i = 0; i < n; ++i) {
		//cout << spec[i] << " " << eq[i] << endl;
		if (!spec[i]) {
			if (eq[i]) res += eq[i]-1;
		}
		else res += eq[i];
	}

	cout << res;





}