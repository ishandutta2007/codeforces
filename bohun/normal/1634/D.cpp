#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int t, n;
map<set<int>, int> cache;

bool asked(set<int> s) {
	return cache.find(s) != cache.end();
}

int ask(set<int> s) {
	if (asked(s))
		return cache[s];

	cout << "? ";
	for (auto x : s)
		cout << x << " ";
	cout << endl;

	int res;
	cin >> res;
	return cache[s] = res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cache.clear();
		cin >> n;

		int a = 1, b = 2, c = 3;
		rep(i, 4, n) {
			set<int> s[3];
			s[0] = {a, b, c};
			s[1] = {a, b, i};
			s[2] = {a, c, i};

			int mx = -1;
			set<int> t[2];

			rep(x, 0, 2)
				if (ask(s[x]) > mx) {
					mx = ask(s[x]);
					t[0] = s[x];
				}

			rep(x, 0, 2)
				rep(y, x + 1, 2)
					if (ask(s[x]) == mx && ask(s[y]) == mx) {
						t[0] = s[x];
						t[1] = s[y];
					}	

			if (t[1].empty())
				t[1] = {b, c, i};

			vector<int> v;
			for (auto e : {a, b, c, i})
				if (t[0].count(e) && t[1].count(e))
					v.push_back(e);

			while (v.size() > 2)
				v.pop_back();
			
			for (auto e : {a, b, c, i}) {
				if (e != v[0] && e != v[1] && asked({v[0], v[1], e})) {
					c = e;
					break;
				}
			}

			a = v[0];
			b = v[1];
		}

		cout << "! " << a << " " << b << endl;
	}

	return 0;
}