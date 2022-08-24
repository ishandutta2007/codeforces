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
	
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	set<int> q;
	for (auto x : v) q.insert(x);

	int t = q.size();

	if (t == 1) {
		cout << "1\n";
		return;
	}

	int need = 0;

	if (t > 1 && k == 1) {
		cout << "-1\n";
		return;
	}

	t--;
	k--;


	cout << (t + k - 1) / k << '\n';



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

	for (int i = 0; i <t ; ++i) solve();

}