#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;
vector<int> tin, tout, f;
int timer;

bool father(int u, int v) {
	if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
	return false;
}

bool cmp(int u, int v) {
	return (tin[u] < tin[v]);
}

void dfs(int vertex, int last) {
	tin[vertex] = timer++;
	f[vertex] = last;
	for (int i = 0; i < gr[vertex].size(); ++i) {
		int to = gr[vertex][i];
		if (to==last) continue;
		dfs(to, vertex);
	}
	tout[vertex] = timer++;
}

int main(){
#ifdef LOCAL
	freopen("K_input.txt", "r", stdin);
	//freopen("K_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	gr.assign(n, {}), tin.assign(n, -1), tout.assign(n, -1), f.assign(n, -1);

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].push_back(v), gr[v].push_back(u);
	}

	dfs(0, -1);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> arr(k);
		for (int j = 0; j < k; ++j) {
			cin >> arr[j];
			arr[j]--;
			arr[j] = max(0, f[arr[j]]);
		}
		sort(arr.begin(), arr.end(), cmp);
		bool ans = true;
		for (int j = 1; j <arr.size(); ++j) {
			if (!father(arr[j-1], arr[j])) ans = false;
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}

}