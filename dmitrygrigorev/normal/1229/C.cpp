#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > larger;
vector<int> deg;

main(){
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	larger.assign(n, {});
	deg.assign(n, 0);

	for (int i=0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u > v) swap(u, v);
		larger[u].push_back(v);
		deg[u]++, deg[v]++;
	}

	int ans = 0;
	for (int i=0; i < n; ++i){
		ans +=  larger[i].size() * (deg[i] - larger[i].size());
		//cout << deg[i] << " " << larger[i].size() << endl;
	}

	cout << ans << "\n";
	int q;
	cin >> q;
	for (int i=0;i<q;++i){
		int x;
		cin >> x;
		x--;
		ans -= larger[x].size() * (deg[x] - larger[x].size());
		for (int j=0; j < larger[x].size(); ++j){
			int to = larger[x][j];
			ans -= larger[to].size() * (deg[to] - larger[to].size());
			larger[to].push_back(x);
			ans += larger[to].size() * (deg[to] - larger[to].size());
		}
		larger[x].clear();
		cout << ans << "\n";
	}

}