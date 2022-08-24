#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > op;
	for (int i = 0; i < 2*n; ++i) {
		char ch;
		cin >> ch;

		if (ch == '+') op.pb(mp(0, -1));
		else {
			int x;
			cin >> x;
			x--;
			op.pb(mp(1, x));
		}

	}

	vector<int> adds;
	reverse(all(op));

	set<int> must_add;

	for (auto x : op) {
		if (x.x == 1) must_add.insert(x.y);
		else {
			if (!must_add.size()) {
				cout << "NO";
				exit(0);
			}
			int W = (*must_add.begin());
			must_add.erase(must_add.begin());

			adds.pb(W);
		}
	}

	reverse(all(adds));
	reverse(all(op));

	int u = 0;

	for (auto x : op) {
		if (x.x == 0) must_add.insert(adds[u++]);
		if (x.x == 1) {
			if (!must_add.size()) {
				cout << "NO";
				exit(0);
			}
			int W = (*must_add.begin());
			must_add.erase(must_add.begin());
			if (x.y != W) {
				cout << "NO";
				exit(0);
			}
		}
	}

	cout << "YES\n";
	for (auto x : adds) cout << x+1 << " ";


}