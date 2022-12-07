#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

#include <bits/stdc++.h>
using namespace std;

// Source: Me
// Tested on: ???
// Easy to use segtree. Change comb and E based on problem
template <class T>
struct SegTree {
  int n;
  vector<T> t;
  T E = INF;

  T comb(T a, T b) {  // Segtree function
    return min(a, b);
  }
  SegTree() {}
  SegTree(int _n) : n(_n) { t.assign(4 * n + 5, E); }
  SegTree(vector<T>& bld) : n(bld.size()) {
    t.assign(4 * n + 5, E);
    build(bld, 1, 0, n - 1);
  }
  void build(vector<T>& bld, int node, int tl, int tr) {
    if (tl == tr) {
      t[node] = bld[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(bld, 2 * node, tl, tm);
      build(bld, 2 * node + 1, tm + 1, tr);
      pull(node);
    }
  }
  void pull(int node) { t[node] = comb(t[2 * node], t[2 * node + 1]); }
  T query(int l, int r) { return query(l, r, 1, 0, n - 1); }
  T query(int l, int r, int node, int tl, int tr) {
    if (r < tl || tr < l) return E;
    if (l <= tl && tr <= r) return t[node];
    int tm = (tl + tr) / 2;
    return comb(query(l, r, 2 * node, tl, tm),
                query(l, r, 2 * node + 1, tm + 1, tr));
  }
  void update(int p, T val) { return update(p, val, 1, 0, n - 1); }
  void update(int p, T val, int node, int tl, int tr) {
    if (tl == tr) {
      t[node] += val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm)
      update(p, val, 2 * node, tl, tm);
    else
      update(p, val, 2 * node + 1, tm + 1, tr);
    pull(node);
  }

  // first index such that f(index) is true (UNTESTED)
  int search_first(int l, int r, const function<bool(T)>& f) {
    return search_first(l, r, f, 1, 0, n - 1);
  }
  int search_first_knowingly(const function<bool(T)>& f, int node, int tl,
                             int tr) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int res;
    if (f(t[2 * node]))
      res = search_first_knowingly(f, 2 * node, tl, tm);
    else
      res = search_first_knowingly(f, 2 * node + 1, tm + 1, tr);
    return res;
  }
  int search_first(int l, int r, const function<bool(T)>& f, int node, int tl,
                   int tr) {
    if (l <= tl && tr <= r) {
      if (!f(t[node])) return -1;
      return search_first_knowingly(f, node, tl, tr);
    }
    int tm = (tl + tr) / 2;
    int res = -1;
    if (l <= tm) res = search_first(l, r, f, 2 * node, tl, tm);
    if (r > tm && res == -1)
      res = search_first(l, r, f, 2 * node + 1, tm + 1, tr);
    return res;
  }

  // last index such that f(index) is true (UNTESTED)
  int search_last(int l, int r, const function<bool(T)>& f) {
    return search_last(l, r, f, 1, 0, n - 1);
  }
  int search_last_knowingly(const function<bool(T)>& f, int node, int tl,
                            int tr) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int res;
    if (f(t[2 * node + 1]))
      res = search_last_knowingly(f, 2 * node + 1, tm + 1, tr);
    else
      res = search_last_knowingly(f, 2 * node, tl, tm);
    return res;
  }
  int search_last(int l, int r, const function<bool(T)>& f, int node, int tl,
                  int tr) {
    if (l <= tl && tr <= r) {
      if (!f(t[node])) return -1;
      return search_last_knowingly(f, node, tl, tr);
    }
    int tm = (tl + tr) / 2;
    int res = -1;
    if (r > tm) res = search_last(l, r, f, 2 * node + 1, tm + 1, tr);
    if (l <= tm && res == -1) res = search_last(l, r, f, 2 * node, tl, tm);
    return res;
  }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
	cin >> n;
	vector <int> v(n + 1, 0);
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 0; i <= n; i++) v[i] -= i;
	vector <int> pref(n + 1, 0);
	vector <int> temp(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		temp[i] = min(temp[i - 1], v[i]);
	}
	for(int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + temp[i];
	}
	vector <int> suff(n + 1, 0);
	SegTree <int> st(v);
	for(int i = n; i >= 0; i--) {
		int ind = st.search_first(i + 1, n, [&](int val) {return val <= v[i];});
		if(ind == -1) {
			suff[i] = (n - i + 1) * (v[i]);
		} else {
			suff[i] = suff[ind] + (ind - i) * (v[i]);
		}
	}
	// for(int i = 0; i <= n; i++) cout << suff[i] << ' ';
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int p, x;
		cin >> p >> x;
		int ans = pref[p - 1];
		x = min(x - p, temp[p - 1]);
		// cout << x << '\n';
		int ind = st.search_first(p + 1, n, [&](int val) {return val <= x;});
		// cout << ans << ' ';
		if(ind == -1) {
			ans += (n - p + 1) * (x);
		} else {
			ans += suff[ind] + (ind - p) * (x);
		}
		// cout << x << ' ' << p << ' ' << ind << ' ' << suff[ind] << ' ' << ans << ' ';
		cout << ans + n*(n + 1)/2 << '\n';
	}
}