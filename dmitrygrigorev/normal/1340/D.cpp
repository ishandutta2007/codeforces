#include <bits/stdc++.h>
#define data sdofhsf
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<pair<int, int> > ans;

int k;

void dfs(int vertex, int last, int target) {

	int cnt = data[vertex].size();
	if (vertex != 0) cnt--;

	int cur = target;

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		if (cur + 1 <= k) {
			ans.push_back(make_pair(to, cur + 1));
			dfs(to, vertex, cur + 1);
			cnt--;
			cur++;
		}

		else {
			ans.push_back(make_pair(vertex, target - cnt - 1));
			ans.push_back(make_pair(to, target - cnt));
			cur = target - cnt;
			dfs(to, vertex, cur);
		}
	}

	if (vertex != 0 && cur + 1 != target) {
		ans.push_back(make_pair(vertex, target - 1));
	}
	if (last != -1) ans.push_back(make_pair(last, target));

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	data.assign(n, {});
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
	}

	if (n==1) {
		cout << "1\n 1 0";
		exit(0);
	}

	ans.push_back(make_pair(0, 0));

	k = 1;
	for (int i = 0; i < n; ++i) k = max(k, (int) data[i].size());

	dfs(0, -1, 0);

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) cout << ans[i].first+1 << " " << ans[i].second << "\n";

}