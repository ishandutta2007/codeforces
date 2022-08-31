#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 500007;

int a[N];
int b[N];

vector<vector<pair<int, int> > > data;
int n;

vector<int> check(int x) {
	
	int deg = (1<<x);

	data.assign(deg, {});

	vector<bool> used(n, false);
	vector<int> cnt(deg, 0);

	vector<int> pos(2*n);

	for (int i = 0; i < n; ++i) {
		int c = a[i] % deg;
		int d = b[i] % deg;

		pos[2*i] = c, pos[2*i+1] = d;

		cnt[c]++;
		cnt[d]++;

		data[c].push_back(make_pair(d, 2*i));
		data[d].push_back(mp(d, 2*i+1));

	}

	for (int i = 0; i < deg; ++i) {
		if (cnt[i] % 2 != 0) {
			return {};
		}
	}

	vector<int> ans;
	vector<int> eating;

	eating.push_back(0);
	used[0] = true;

	while (eating.size()) {

		int need = pos[eating.back() ^ 1];

		bool ch = false;

		while (data[need].size()) {
			int ed = data[need].back().second;
			if (used[ed / 2]) {
				data[need].pop_back();
				continue;
			}

			used[ed / 2] = true;
			ch = true;
			eating.push_back(ed);
			break;
		}

		if (ch) continue;
		ans.push_back((eating.back() ^ 1));
		ans.push_back((eating.back() ^ 0));

		eating.pop_back();
	}

	if (ans.size() != 2*n) return {};
	return ans;



}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		v.push_back(a[i]);
		v.push_back(b[i]);
	}

	int L = 0, R = 21;
	vector<int> ans;
	for (int i = 0; i < 2*n; ++i) ans.push_back(i);

	while (R-L>1) {
		int M = (L+R)/2;
		vector<int> res = check(M);

		if (res.empty()) R = M;
		else {
			L = M;
			ans = res;
		}
	}

	cout << L << "\n";
	for (int i = 0; i < ans.size(); ++i) cout << ans[i]+1 << " ";
		cout << "\n";
/*
	#ifdef LOCAL
		for (int i = 0; i < ans.size(); ++i) {
			cout << v[ans[i]] % (1<<L) << " ";
		}
	#endif
*/

}