#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

bool good(vector<int> v) {
	for (int i = 0; i < v.size(); ++i) if (v[i] != i) return false;
	return true;
}

void solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<int> ans;
	
	while (!good(v)) {
		vector<bool> g(n+1);
		for (int i = 0; i < n; ++i) g[v[i]] = true;
		int mex = 0;
		while (g[mex]) mex++;

		if (mex < n) {
			ans.push_back(mex);
			v[mex] = mex;
		}

		else {
			for (int i = 0; i < n; ++i) if (v[i] != i) {
				ans.push_back(i);
				v[i] = mex;
				break;
			}
		}

	}

	assert(ans.size() <= 2*n);
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i]+1 << " ";
	}
	cout << "\n";

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}