#include <bits/stdc++.h>
#define index dgfd
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int matrix[1500][1500];

bitset<1500> used[1500];

int index[1500][1500];

vector<vector<int> > great;

const int mod = 998244353;
vector<bool> troll;

vector<int> solve(vector<int> &v) {

	if (v.size() == 1) {
		return {0, 1};
	}

	vector<vector<int> > results;
	vector<vector<int> > children;

	int R = v.size();
	for (auto x : v) {
		if (troll[x]) continue;
		for (int j = R-1; j >= 1; j--) {
			if (index[x][j-1] != -1) {
				int A = index[x][j-1];
				children.pb(great[A]);
				for (auto t : great[A]) troll[t] = true;
				break;
			}
		}
	}


	for (auto x : v) troll[x] = false;

	for (auto ch : children) {
		results.pb(solve(ch));
	}

	vector<int> current;
	current.pb(1);

	for (auto t : results) {
		vector<int> gl(current.size() + t.size() - 1);
		for (int i = 0; i < current.size(); ++i) {
			for (int j = 0; j < t.size(); ++j) {
				int A = ((ll) current[i] * t[j]) % mod;
				gl[i+j] += A;
				if (gl[i+j] >= mod) gl[i+j] -= mod;
			}
		}
		current = gl;
	}

	current[1] += 1;
	if (current[1] >= mod) current[1] -= mod;

	return current;


}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	troll.assign(n, false);

	vector<vector<pair<int, int> > > arr(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			index[i][j] = -1;
			cin >> matrix[i][j];
			arr[i].pb(mp(matrix[i][j], j));
		}
	}

	bitset<1500> q;

	for (auto &x : arr) sort(all(x));

	vector<bitset<1500> > kek(n);
	vector<vector<int> > tet(n);

	for (int step = 0; step < n; ++step) {

		for (int i = 0; i < n; ++i) {
			
			int index = arr[i][step].y;
			kek[i][index] = 1;
			tet[i].pb(index);

		}

		for (int i = 0; i < n; ++i) {

			if (used[step][i]) continue;

			q = kek[i] & used[step];


			if (q.count() != 0) {
				used[step][i] = true;
				continue;
			}

			bool can = true;
			for (auto val : tet[i]) {
				if (kek[i] != kek[val]) can = false;
			}

			if (!can) {
				used[step][i] = true;
				continue;
			}


			int Q = -1;
			for (auto val : tet[i]) Q = max(Q, arr[val][step].x);

			int E = 1e9;
			for (auto val : tet[i]) if (step + 1 < n) E = min(E, arr[val][step + 1].x);

									//if (i == 4 && step==2) cout << Q << " " << E << endl;


			if (Q >= E) {
				for (auto val : tet[i]) {
					used[step][val] = true;
				}
			}
			else {
				for (auto val : tet[i]) {
					used[step][val] = true;
				}
				int R = great.size();
				great.pb(tet[i]);

				for (auto val : tet[i]) {
					index[val][step] = R;
				}
			}

		}

	}

	vector<int> tarr;
	for (int i = 0; i < n; ++i) tarr.pb(i);

	auto ans = solve(tarr);
	while (ans.size() <= n) ans.pb(0);

	for (int i = 1; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}

}