#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > remaining;

struct lex_compare {
    bool operator() (const int& lhs, const int& rhs) const {
        if (remaining[lhs].size() != remaining[rhs].size()) return (remaining[lhs].size() > remaining[rhs].size());
        return (lhs > rhs);
    }
};

void solve() {

	int n, x, y;
	cin >> n >> x >> y;

	remaining.assign(n+1, {});
	set<int, lex_compare> ms;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i]--;
	}

	vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		remaining[v[i]].pb(i);
	}

	for (int i = 0; i <= n; ++i) ms.insert(i);

	int free = -1;
	for (int i = 0; i <= n; ++i) if (!remaining[i].size()) free = i;


	for (int i = 0; i < x; ++i) {
		auto it = ms.begin();

		auto num = (*it);
		ms.erase(it);

		int index = remaining[num].back();
		remaining[num].pop_back();
		ans[index] = num;

		ms.insert(num);
	}

	vector<int> rw;

	int tp = -1;

	for (auto el : ms) {
		if (tp == -1) tp = remaining[el].size();
		for (auto x : remaining[el]) {
			rw.pb(x);
		}
	}

	vector<pair<int, int> > stay;
	for (int i = 0; i < rw.size(); ++i) {
		int a = rw[i];
		int b = rw[(i+tp)%rw.size()];

		if (v[a] != v[b]) {
			stay.pb(mp(b, a));
		}
	}

	if (stay.size() < y-x) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for (int i = 0; i < y-x; ++i) {
		int a = stay[i].second, b = stay[i].first;
		ans[b] = v[a];
	}

	for (int i = 0; i < n; ++i) if (ans[i] == -1) ans[i] = free;

	for (auto x : ans) cout << x+1 << " ";
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