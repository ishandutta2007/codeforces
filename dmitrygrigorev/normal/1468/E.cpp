#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int it = 0; it < t; ++it) {

		vector<int> a(4), b(4);
		for (int i = 0; i < 4; ++i) {
			cin >> a[i];
			b[i] = i;
		}

		int ans = 0;

		do {
			int A = a[b[0]], B = a[b[1]], C = a[b[2]], D = a[b[3]];
			ans = max(ans, min(A, B) * min(C, D));
		}
		while (next_permutation(all(b)));

		cout << ans << '\n';

	}

}