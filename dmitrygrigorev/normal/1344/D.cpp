#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;
vector<int> v;

int get(int x) {

	int tot = 0;
	for (int i = 0; i < n; ++i) {
		int sec = v[i] - x;
		if (sec < 0) continue;

		int L = 0, R = v[i];
		while (R-L>1) {
			int M = (L+R)/2;
			if (3*M*M + 3*M + 1 <= sec) L = M;
			else R = M;
		}

		tot += R;

	}

	return tot;

}

main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int L = -4e18;
	int R = 4e18;

	while (R-L>1) {
		int M = (L+R)/2;
		int t = get(M);
		if (t <= k) R = M;
		else L = M;
	}

	k -= get(R);

	vector<int> ans(n, 0);

	for (int i = 0; i < n; ++i) {
		int sec = v[i] - R;
		if (sec < 0) continue;

		int L = 0, R = v[i];
		while (R-L>1) {
			int M = (L+R)/2;
			if (3*M*M + 3*M + 1 <= sec) L = M;
			else R = M;
		}

		ans[i] = R;
	}

	for (int i = 0; i < n; ++i) {
		int sec = v[i] - L;
		if (sec < 0 || k == 0) continue;

		if (3*ans[i]*ans[i] + 3*ans[i] + 1 == sec) {
			if (ans[i] < v[i]) {
				ans[i]++;
				k--;
			}
		}
	}

	for (int i = 0; i < n; ++i) cout << ans[i] << " ";





}