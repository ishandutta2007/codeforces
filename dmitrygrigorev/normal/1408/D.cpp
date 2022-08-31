#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1000007;

int max_req[N];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > a(n), b(m);

	for (auto &x : a) {
		cin >> x.x >> x.y;
	}

	for (auto &x : b) {
		cin >> x.x >> x.y;
	}

	int ans = 1e9;
	for (auto x : a) {
		for (auto y : b) {
			if (x.x > y.x || x.y > y.y) continue;
			int dx = y.x - x.x;
			int dy = y.y - x.y;
			max_req[dx] = max(max_req[dx], dy + 1);
		}
	}

	int tet = 0;
	for (int i = N-1; i >= 0; i--) {
		tet = max(tet, max_req[i]);
		ans = min(ans, i + tet);
	}

	cout << ans;


}