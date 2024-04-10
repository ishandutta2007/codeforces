#include <bits/stdc++.h>
#define free dfkjgfdg
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Event {
	int x;
	int y;
	int type;
};

bool cmp(Event &a, Event &b) {
	return (a.x < b.x);
}

set<pair<int, int> > free;

void kill(int x) {
	while (free.size() && x) {
		auto element = (*free.begin());
		free.erase(free.begin());

		int len = element.y - element.x + 1;

		if (len <= x) {
			x -= len;
		}

		else {
			element.x += x;
			free.insert(element);
			return;
		}

	}
}

void kill_p(int x) {

	auto W = free.upper_bound(mp(x, 2.001e9));
	if (W!=free.begin()) {
		W--;
		auto element = (*W);
		if (x >= element.x && x <= element.y) {
			free.erase(W);
			if (element.x < x) free.insert(mp(element.x, x-1));
			if (element.y > x) free.insert(mp(x+1, element.y));
		}
	}

}

bool get(int x) {

	auto W = free.upper_bound(mp(x, 2.001e9));
	if (W!=free.begin()) {
		W--;
		auto element = (*W);
		if (x >= element.x && x <= element.y) {
			return true;
		}
		return false;
	}

	return false;

}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<Event> v;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.pb({x, y, 1});
	}

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		v.pb({x, y, i + 2});
	}

	sort(all(v), cmp);

	free.insert(mp(0, 2e9));

	vector<bool> ans(m);

	int start = 0;
	int last = -1;

	while (start < n+m) {

		kill(v[start].x - last - 1);

		int finish = start;
		while (finish < n+m && v[finish].x == v[start].x) {
			finish++;
		}

							//	cout << start << endl;


		int W = (*free.begin()).x;
		bool have_least = false;

		set<int> killed_here;

		for (int i = start; i < finish; ++i) {
			if (v[i].type == 1) {
				if (v[i].y < W) {
					have_least = true;
				}
				killed_here.insert(v[i].y);
				kill_p(v[i].y);
			}
		}


		if (!have_least) {
			killed_here.insert(W);
			kill_p(W);
		}


		for (int i = start; i < finish; ++i) {
			if (v[i].type != 1) {
				int R = v[i].type - 2;
				if (killed_here.count(v[i].y)) {
					ans[R] = false;
				}
				else ans[R] = true;
			}
		}

		last = v[start].x;

		start = finish;

	}

	for (auto x : ans) {
		if (x) {
			cout << "WIN\n";
		}
		else cout << "LOSE\n";
	}




}