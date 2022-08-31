#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 30007;
const int M = 5;

struct Transition {
	int primary;
	int to;
	int coins;
};

bool cmp(Transition &x, Transition &y) {
	return (x.primary < y.primary);
}

vector<Transition> trans[N][M];
ll cnt[N][M];

const int LG = 17;

pair<ll, ll> what_state[N][M][LG];
pair<ll, ll> edges[N][M][LG];


void solve() {

	int n, c, q;
	cin >> n >> c >> q;

	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
		x--;
	}

	for (int i = n; i >= 0; --i) {
		for (int j = c; j >= 0; --j) {
			trans[i][j].clear();
			for (int take = 1; take + i <= n && take - 1 <= j; ++take) {
				int P = v[i + take - 1];
				trans[i][j].pb({P, i + take, j - (take - 1)});
			}
			sort(all(trans[i][j]), cmp);
			if (!trans[i][j].size()) {
				cnt[i][j] = 1;
				for (int e = 0; e < LG; ++e) {
					what_state[i][j][e] = mp(-1, -1);
					edges[i][j][e] = mp(-1, -1);
				}
			}
			else {

				for (int e = 0; e < LG; ++e) {
					what_state[i][j][e] = mp(-1, -1);
					edges[i][j][e] = mp(-1, -1);
				}

				cnt[i][j] = 0;

				for (auto p : trans[i][j]) {
					cnt[i][j] += cnt[p.to][p.coins];
				}

				ll mx = -1;
				int index = -1;

				int u = 0;

				for (auto p : trans[i][j]) {
					if (cnt[p.to][p.coins] > mx) {
						mx = cnt[p.to][p.coins];
						index = u;
					}
					u++;
				}

				ll lsum = 0, rsum = 0;
				for (int e = 0; e < index; ++e) {
					int A = trans[i][j][e].to, B = trans[i][j][e].coins;
					lsum += cnt[A][B];
				}

				for (int e = index + 1; e < trans[i][j].size(); ++e) {
					int A = trans[i][j][e].to, B = trans[i][j][e].coins;
					rsum += cnt[A][B];
				}

				what_state[i][j][0] = mp(trans[i][j][index].to, trans[i][j][index].coins);
				edges[i][j][0] = mp(lsum, rsum);

				for (int e = 1; e < LG; ++e) {
					int A = what_state[i][j][e-1].x, B = what_state[i][j][e-1].y;
					if (what_state[A][B][e-1] == mp((ll) -1, (ll) -1)) break;

					what_state[i][j][e] = what_state[A][B][e-1];
					edges[i][j][e] = mp(edges[i][j][e-1].x + edges[A][B][e-1].x, edges[i][j][e-1].y + edges[A][B][e-1].y);
				}


			}

		}
	}

	for (int i = 0; i < q; ++i) {
		int number;
		ll need;

		cin >> number >> need;
		need--;
		number--;

		if (need >= cnt[0][c]) {
			cout << "-1\n";
			continue;
		}

		int pos = 0, rem = c;

		bool decided = false;

		while (!decided) {

			//cout << pos << " " << rem << endl;

			ll L = need, R = cnt[pos][rem] - need - 1;
			ll ltaken = 0, rtaken = 0;

			for (int i = LG-1; i >= 0; --i) {
				if (what_state[pos][rem][i] == mp((ll) -1, (ll) -1)) continue;
				int A = what_state[pos][rem][i].x, B = what_state[pos][rem][i].y;

				//cout << i << " " << pos << " " << rem << " " << A << " " << B << endl;

				if (A > number) continue;
				ll C = edges[pos][rem][i].x, D = edges[pos][rem][i].y;

				if (ltaken + C > L || rtaken + D > R) continue;
				pos = A, rem = B, ltaken += C, rtaken += D;
			}

			need -= ltaken;

			//cout << pos << " " << rem << " " << need << endl;

			for (int u = 0; u < trans[pos][rem].size(); u++) {
				int A = trans[pos][rem][u].to, B = trans[pos][rem][u].coins;
				//cout << " === " << cnt[A][B] << " " << A << " " << B << " " << number << endl;
				if (cnt[A][B] <= need) {
					need -= cnt[A][B];
					continue;
				}
				else {
					if (A > number) {
						vector<int> Q;
						for (int f = pos; f < A; ++f) Q.pb(v[f]);
						reverse(all(Q));

						int steps = number - pos;
						cout << Q[steps] + 1 << '\n';
						decided = true;
					}
					else {
						pos = A, rem = B;
					}
					break;
				}
			}


		}

	}




}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}