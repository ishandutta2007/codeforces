/*

Code for problem F by cookiedoth
Generated 26 Mar 2019 at 07.21 P


  !











\_()_/
^_^
~_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct dsu {
	vector<int> p, sz1, sz2;
	vector<pair<int, int> > st;
	int v;
	ll ans;

	void init(int n, int m) {
		v = n + m;
		sz1.resize(v);
		sz2.resize(v);
		p.resize(v);
		iota(all(p), 0);
		for (int i = 0; i < n; ++i) {
			sz1[i] = 1;
		}
		for (int i = n; i < v; ++i) {
			sz2[i] = 1;
		}
	}

	int get_root(int v) {
		if (p[v] == v) {
			return v;
		}
		else {
			return get_root(p[v]);
		}
	}

	ll func(int v) {
		return (ll)sz1[v] * (ll)sz2[v];
	}

	void hang(int u, int v) {
		st.push_back({u, v});
		p[u] = v;
		sz1[v] += sz1[u];
		sz2[v] += sz2[u];
		ans += func(v);
	}

	void join(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v) {
			st.push_back({u, u});
			return;
		}
		ans -= func(u);
		ans -= func(v);
		if (sz1[u] + sz2[u] < sz1[v] + sz2[v]) {
			hang(u, v);
		}
		else {
			hang(v, u);
		}
	}

	void roll_back(int cnt) {
		for (int i = 0; i < cnt; ++i) {
			int u = st.back().first, v = st.back().second;
			st.pop_back();
			if (u == v) {
				continue;
			}
			p[u] = u;
			ans -= func(v);
			sz1[v] -= sz1[u];
			sz2[v] -= sz2[u];
			ans += func(u);
			ans += func(v);
		}
	}

	ll S_size() {
		return ans;
	}
};

int n;
vector<pair<int, int> > a;
vector<int> cx, cy, p;
vector<ll> ans;
dsu T;

void apply(int q_id) {
	T.join(a[q_id].first, cx.size() + a[q_id].second);
}

void go(int l, int r) {
	if (l == r) {
		if (p[l] > l) {
			apply(l);
		}
		ans.push_back(T.S_size());
		if (p[l] > l) {
			T.roll_back(1);
		}
	}
	else {
		int mid = (l + r) >> 1, cnt = 0;
		for (int i = mid + 1; i <= r; ++i) {
			if (p[i] < l) {
				apply(p[i]);
				cnt++;
			}
		}
		go(l, mid);
		T.roll_back(cnt);
		cnt = 0;
		for (int i = l; i <= mid; ++i) {
			if (p[i] > r) {
				apply(i);
				cnt++;
			}
		}
		go(mid + 1, r);
		T.roll_back(cnt);
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		a.push_back({x, y});
		cx.push_back(x);
		cy.push_back(y);
	}

	sort(all(cx));
	sort(all(cy));
	cx.erase(unique(all(cx)), cx.end());
	cy.erase(unique(all(cy)), cy.end());
	for (int i = 0; i < n; ++i) {
		a[i].first = lower_bound(all(cx), a[i].first) - cx.begin();
		a[i].second = lower_bound(all(cy), a[i].second) - cy.begin();
	}

	p.resize(n, n);
	map<pair<int, int>, int> mp;
	for (int i = 0; i < n; ++i) {
		if (mp.find(a[i]) == mp.end()) {
			mp[a[i]] = i;
		}
		else {
			p[mp[a[i]]] = i;
			p[i] = mp[a[i]];
			mp.erase(a[i]);
		}
	}

	T.init(cx.size(), cy.size());
	go(0, n - 1);
	output(all(ans), cout);
}