#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int L = -1;
const int R = 1e13;

void change(vector<int> &v) {

	int n = v.size();
	if (n == 2) return;

	v[2] += v[1]/2;
	v[0] += v[1]/2;

	v[1] %= 2;

	vector<int> z;
	if (v[1] == 0) z.pb(1);

	for (int i = 2; i < n-1; ++i) {


		while (v[i] > 1) {
			while (z.size() && v[i] > 1) {
				if (z.back() == i-1) {
					v[i] -= 2;
					v[i+1]++;
					z.pop_back();
				}
				else {
					int need = min(v[i] - 1, (i-1) - z.back());
					v[i] -= need;
					z.back() += need;
					v[i+1] += need;
				}
			}

			int mvs = i + 1;
			int can = (v[i] - 1) / mvs;

			v[0] += can;
			v[i+1] += can * (mvs - 1);
			v[i] -= can * mvs;

			if (v[i] > 1) {
				z.pb(1);
				v[0]++;
				v[i+1]++;
				v[i]--;
			}
		}

		if (v[i] == 0) z.pb(i);

	}

	for (int i = 1; i < n - 1; ++i) v[i] = 1;

	for (auto x : z) v[x] = 0;

}

main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) cin >> x;
	vector<int> deltas;

	deltas.pb(v[0] - L);
	for (int i = 1; i < n; ++i) deltas.pb(v[i] - v[i-1]);
	deltas.pb(R - v.back());

	change(deltas);

	int cur = L;
	for (int i = 0; i < n; ++i) {
		cur += deltas[i];
		cout << cur << " ";
	}

}