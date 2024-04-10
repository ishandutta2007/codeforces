#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<pair<int, int> > > gr;
vector<int> can;
vector<int> desired;

int n;

int dfs(int vertex, int last) {
	int sz = 1;
	for (auto ed : gr[vertex]) {
		if (ed.y == last) continue;
		sz += dfs(ed.x, ed.y);
	}

	if (last != -1) {
		can[last] = min(sz, n-sz);
	}

	return sz;

}

const int N = 100007;
vector<int> glob[N];
int ptr = 0;

struct lex_compare {
    bool operator() (const int& lhs, const int& rhs) const {
        if (glob[lhs].size() != glob[rhs].size()) return (glob[lhs].size() > glob[rhs].size());
        return (lhs < rhs);
    }
};

int dfs2(int vertex, int must, int last) {

	vector<int> children;

	vector<int> tut;
	tut.pb(vertex);
	glob[ptr] = tut;
	children.pb(ptr++);

	for (auto ed : gr[vertex]) {
		if (ed.x == last) continue;
		children.pb(dfs2(ed.x, desired[ed.y], vertex));
		if (children.back() == -1) children.pop_back();
	}

	int tot = 0;
	for (auto c : children) tot += glob[c].size();

	assert(must <= tot);
	tot -= must;

	set<int, lex_compare> ms;
	for (auto c : children) ms.insert(c);

	while (tot) {
		tot -= 2;
		assert(ms.size() > 1);

		auto it = ms.begin();
		int a = (*it);
		ms.erase(ms.begin());

		it = ms.begin();
		int b = (*it);
		ms.erase(ms.begin());

		int E = glob[a].back(), F = glob[b].back();
		glob[a].pop_back(), glob[b].pop_back();
		cout << E+1 << " " << F+1 << "\n";

		if (glob[a].size()) ms.insert(a);
		if (glob[b].size()) ms.insert(b);
	}

	if (!ms.size()) {
		return -1;
	}

	auto it = ms.begin();
	int Q = (*it);
	ms.erase(ms.begin());

	while (ms.size()) {
		auto it = ms.begin();
		int R = (*it);
		ms.erase(ms.begin());
		for (auto W : glob[R]) glob[Q].pb(W);
	}

	return Q;
	



}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.x != b.x) return (a.x < b.x);
	return ((can[a.y]%2) < (can[b.y]%2));
}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> n >> k;

	gr.assign(n, {});
	can.assign(n-1, -1);

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		gr[u-1].pb(mp(v-1, i));
		gr[v-1].pb(mp(u-1, i));
	}	

	dfs(0, -1);

	int mn = 0, mx = 0;
	for (auto x : can) {
		mx += x;
		mn += (x%2);
	}

	if ((k%2) != (mn%2)) {
		cout << "NO";
		exit(0);
	}

	if (k < mn || k > mx) {
		cout << "NO\n";
		exit(0);
	}

	desired.assign(n-1, -1);
	k -= mn;
	k /= 2;

	vector<pair<int, int> > arr;
	for (int i = 0; i < n-1; ++i) {
		arr.pb(mp(can[i] / 2, i));
	}

	sort(all(arr), cmp);

	int u = 0;
	for (int i = 1; i <= n; ++i) {
		while (u < arr.size() && arr[u].x < i) {
			desired[arr[u].y] = can[arr[u].y];
			u++;
		}

		if (k <= (n - 1 - u)) {
			for (int j = u; j < n-1; ++j) arr[j].x = 0;
			sort(arr.begin() + u, arr.end(), cmp);

			for (int j = u; j < n-1; ++j) {
				if (k) {
					desired[arr[j].y] = (can[arr[j].y] % 2) + 2*i;
					k--;
				}
				else {
					desired[arr[j].y] = (can[arr[j].y] % 2) + 2*i - 2;
				}
			}
			break;
		}

		k -= (n - 1 - u);

	}

	cout << "YES\n";

	dfs2(0, 0, -1);

}