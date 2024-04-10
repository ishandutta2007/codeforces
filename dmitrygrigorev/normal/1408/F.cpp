#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<pair<int, int> > ans;

void combine(int l, int r) {
	if (r - l < 1) return;
	if (r-l == 1) {
		ans.pb(mp(l, l+1));
		return;
	}
	int mid = (l+r)/2;
	combine(l, mid);
	combine(mid+1, r);

	int u = mid + 1;
	for (int i = l; i <= mid; ++i) {
		ans.pb(mp(i, u++));
	}

}

bool deg(int x) {
	while (x%2==0) x /= 2;
	return (x==1);
}

bool bad(int x, int y) {
	if (x > y) swap(x, y);
	if (!deg(x)) return true;
	return false;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n <= 2) {
		cout << 0;
		return 0;
	}


	vector<vector<int> > arr;
	int start = 0;

	for (int i = 0; i < 19; ++i) {
		if (n & (1<<i)) {
			combine(start, start + (1<<i) - 1);
			vector<int> tut;
			for (int j = 0; j < (1<<i); ++j) {
				tut.pb(start++);
			}
			arr.pb(tut);
		}
	}

	while (arr.size() > 2) {

		auto a = arr[arr.size() - 3];
		auto b = arr[arr.size() - 2];
		auto c = arr[arr.size() - 1];

		for (int i = 0; i < 3; ++i) arr.pop_back();

		while (bad(b.size(), c.size())) {

			if (b.size() > c.size()) swap(b, c);
			int T = b.size();
			for (int i = 0; i < T; ++i) {
				ans.pb(mp(b[i], c.back()));
				b.pb(c.back());
				c.pop_back();	
			}
		}
		if (b.size() > c.size()) swap(b, c);

		int need = a.size();


		while (a.size() != b.size()) {
			int T = a.size();
			for (int i = 0; i < T; ++i) {
				ans.pb(mp(a[i], c.back()));
				a.pb(c.back());
				c.pop_back();
			}
		}

		int T = b.size();
		for (int i = 0; i < T; ++i) {
			ans.pb(mp(b[i], a.back()));
			b.pb(a.back());
			a.pop_back();	
		}

		if (b.size() > c.size()) swap(b, c);
		arr.pb(b);
		arr.pb(c);
	}

	assert(ans.size() <= 500000);

	//if (ans.size() > 500000) exit(0);
	//cerr << n << " " << ans.size() << endl;

	cout << ans.size() << '\n';

	//exit(0);

	for (auto x : ans) {
		cout << x.x+1 << " " << x.y+1 << '\n';
	}

}