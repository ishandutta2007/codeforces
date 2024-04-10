#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve(int x, vector<int> v) {

	set<pair<int, int> > values;
	values.insert(mp(x, 0));

	bool add = false;

	for (int i = 0; i < 59; ++i) {
		set<pair<int, int> > nv;

		int need = (1LL<<(i+1));

		for (auto p : values) {

			int x = p.x;

			//cout << i << " " << x << " " << p.y << " " << v[i] << endl;
			int T = ((x%need) + need) % need;
			//cout << T << endl;

			if (T == 0 && v[i] % 2 == 0) {
				nv.insert(mp(x, (p.y + v[i]) / 2));
			}

			if (T == 0 && v[i] % 2 != 0) {
				if (p.y) {
					nv.insert(mp(x, (p.y + v[i]) / 2));
				}
			}

			if (T != 0 && v[i] % 2 == 0) {
				if (p.y) {
					nv.insert(mp(x + need/2, (p.y + v[i] - 1) / 2));
					nv.insert(mp(x - need/2, (p.y + v[i] - 1) / 2));
				}
			}

			if (T != 0 && v[i] % 2 != 0) {
				nv.insert(mp(x + need/2, (p.y + v[i] - 1) / 2));
				nv.insert(mp(x - need/2, (p.y + v[i] - 1) / 2));
			}

		}

		values = nv;

	}

	for (auto p : values) {
		if (p.x == 0) {
			cout << "Yes\n";
			return;
		}
	}

	cout << "No\n";


}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(60, 0);

	int n;
	int t;

	cin >> n >> t;

	for (int i = 0; i < n-2; ++i) {
		char x;
		cin >> x;
		v[x - 'a']++;
	}

	char y;
	cin >> y;

	t += (1LL<<(y - 'a'));

	char x;
	cin >> x;

	t -= (1LL<<(x - 'a'));

	solve(t, v);

}