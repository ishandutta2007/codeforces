#include <bits/stdc++.h>
#define ll long long
#define null null

using namespace std;

struct st { 
	vector<int> t;
	int n;
	st() {}
	void init(int _n) {
		n = _n;
		t.resize(4 * n);
	}
	void relax(int pos, int val, int v, int tl, int tr) {
		if (tl == tr)
			t[v] = max(t[v], val);
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				relax(pos, val, v * 2, tl, tm);
			else
				relax(pos, val, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]);
		}
	}
	int get(int l, int r, int v, int tl, int tr) {
		if (l > r)
			return 0;
		if (l == tl && r == tr)
			return t[v];
		int tm = (tl + tr) / 2;
		int res_l = get(l, min(r, tm), v * 2, tl, tm);
		int res_r = get(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
		return max(res_l, res_r);
	}
	void relax(int pos, int val) {
		//cout << "relaxing " << pos << " " << val << endl;
		relax(pos, val, 1, 0, n - 1);
	}
	int get(int l, int r) {
		//cout << "getting " << l << " " << r << endl;
		//cout << "returned " << get(l, r, 1, 0, n - 1) << endl;
		return get(l, r, 1, 0, n - 1);
	}
};

const int mx = 2e5;
int n, m, a[mx], nvp_l[mx], nvp_r[mx];
st t_l, t_r;
vector<pair<int, int> > ev;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		ev.push_back({l, 1});
		ev.push_back({r + 1, -1});
	}
	sort(ev.begin(), ev.end());
	int ptr = 0, t = 0;
	for (int i = 0; i < m; ++i) {
		while (ptr < ev.size() && ev[ptr].first == i) {
			t += ev[ptr].second;
			ptr++;
		}
		a[i] = t;
	}
	/*for (int i = 0; i < m; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;*/
	/*cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}*/
	t_l.init(mx);
	t_r.init(mx);
	for (int i = 0; i < m; ++i) {
		nvp_l[i] = t_l.get(0, a[i]) + 1;
		t_l.relax(a[i], nvp_l[i]);
	}
	/*for (int i = 0; i < m; ++i) {
		cout << nvp_l[i] << " ";
	}
	cout << endl;*/
	for (int i = m - 1; i >= 0; --i) {
		nvp_r[i] = t_r.get(0, a[i]) + 1;
		t_r.relax(a[i], nvp_r[i]);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = max(ans, nvp_l[i] + nvp_r[i] - 1);
	}
	cout << ans << endl;
}