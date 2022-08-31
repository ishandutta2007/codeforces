#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) v[i] += n-i-1;
	reverse(v.begin(), v.end());
	vector<bool> used(n, false);
	deque<int> path;
	int cur = 0;
	while (true) {
		path.push_back(cur);
		if (used[cur]) break;
		used[cur] = true;
		cur = v[cur];
	}
	while (path.front() != path.back()) path.pop_front();
	path.pop_front();
	cout << path.size() << "\n";
	for (int i = 0; i < path.size(); ++i) {
		cout << n - path[i] << " ";
	}
	cout << "\n";

	
	
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) solve();

	
}