#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<pair<int, int> > > gr;
vector<vector<pair<int, int> > > inside;

bool together[81][81];
bool bad[81];

int ans = 0;

int k;

void recursion(vector<int>& now) {
	if (now.size() == k) {
		ans++;
		return;
	}

	int t = now.size();
	for (int i = 0; i <= t; ++i) {
		int el = 9*t + i;
		bool can = !bad[el];
		for (auto x : now) if (together[x][el]) can = false;
		if (can) {
			now.pb(el);
			recursion(now);
			now.pop_back();
		}
	}

}


bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return (a.second < b.second);
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m >> k;

	gr.assign(n, {});
	inside.assign(n, {});

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		gr[u].pb(mp(v, w));
		inside[v].pb(mp(u, w));
	}

	map<pair<int, int>, int> pos;

	for (auto &x : gr) {
		sort(all(x), cmp);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < gr[i].size(); ++j) {
			int to = gr[i][j].first;
			pos[mp(i, to)] = j;
		}
	}

	for (int i = 0; i < n; ++i) {
		vector<int> kek(81, 0);
		for (int j = 0; j < inside[i].size(); ++j) {
			int to = inside[i][j].first;
			int deg = gr[to].size() - 1, p = pos[mp(to, i)];
			kek[9*deg + p]++;
		}

		vector<int> tr;
		for (int j = 0; j < 81; ++j) if (kek[j]) tr.pb(j);
		for (int j = 0; j < 81; ++j) if (kek[j] > 1) bad[j] = true;
		for (auto x : tr) for (auto y : tr) {
			together[x][y] = true;
		}

	}

	vector<int> now;

	recursion(now);

	cout << ans;





}