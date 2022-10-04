/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

struct fenwick {

	vector<int> t;
	int n;

	void init(int _n) {
		n = _n;
		t.resize(n);
	}

	void add(int pos, int val) {
		//cout << "adding " << pos << " " << val << endl;
		while (pos < n) {
			t[pos] += val;
			pos = (pos | (pos + 1));
		}
	}

	int get(int r) {
		if (r >= n) {
			r = n - 1;
		}
		int res = 0;
		//cout << "getting " << r << endl;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
		//cout << "res = " << res << endl;
	}

	int get(int l, int r) {
		if (l > r)
			return 0;
		//cout << l << " " << r << endl;
		//cout << "plus " << get(r) - get(l - 1) << endl;
		return get(r) - get(l - 1);
	}

};

const int mx = 3e5;
fenwick f;
int n, a[mx];
vector<pair<int, int> > ev;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; ++i) {
		ev.push_back({a[i] + 1, i});
	}
	sort(ev.begin(), ev.end());
	f.init(n);
	for (int i = 0; i < n; ++i) {
		f.add(i, 1);
	}
	int ptr = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		while (ptr < ev.size() && ev[ptr].first == i) {
			f.add(ev[ptr].second, -1);
			ptr++;
		}
		ans += (ll)(f.get(i + 1, a[i]));
	}
	cout << ans << endl;
}