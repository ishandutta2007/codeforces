/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200001, INF = 1000 * 1000 * 1000 + 8;
int x[N], y[N], t[N];
bool vis[N];
int n, k;
map <int, vector <pair <int, int>>> mpx, mpy;
pair <int, int> an1[N], an2[N], an3[N], an4[N];

inline bool is_valid (int q) {
	if (q == n)
		return true;
	if (q == -1)
		return false;
	queue <int> v;
	set <int> st;
	for (int i = 0; i <= n; i++)
		vis[i] = false;
	for (int i = 0; i < n; i++) {
		st.insert(i);
		if (t[i] <= q) {
			vis[i] = true;
			v.push(i);
		}
	}
	while (!v.empty()) {
		int i = v.front();
		int x1 = x[i], y1 = y[i];
		v.pop();
		st.erase(i);
		auto in1 = an1[i],
		in2 = an2[i],
		in3 = an3[i],
		in4 = an4[i];
		if (in1.F != -INF && !vis[(in1).S] && abs(y1 - (in1).F) <= k) {
			vis[(in1).S] = true;
			v.push((in1).S);
		}
		if (in2.F != -INF && !vis[(in2).S] && abs(y1 - (in2).F) <= k) {
			vis[(in2).S] = true;
			v.push((in2).S);
		}
		if (in3.F != -INF  && !vis[(in3).S] && abs(x1 - (in3).F) <= k) {
			vis[(in3).S] = true;
			v.push((in3).S);
		}
		if (in4.F != -INF && !vis[(in4).S] && abs(x1 - (in4).F) <= k) {
			vis[(in4).S] = true;
			v.push((in4).S);
		}
	}
	if (st.size() <= q + 1) 
		return true;
	int cnt = 0;
	while (!st.empty()) {
		cnt++;
		if (cnt > q + 1)
			return false;
		int i2 = *st.begin();
		v.push(i2);
		while (!v.empty()) {
			int i = v.front();
			int x1 = x[i], y1 = y[i];
			v.pop();
			st.erase(i);
			auto in1 = an1[i],
			in2 = an2[i],
			in3 = an3[i],
			in4 = an4[i];
			if (in1.F != -INF && !vis[(in1).S] && abs(y1 - (in1).F) <= k) {
				vis[(in1).S] = true;
				v.push((in1).S);
			}
			if (in2.F != -INF && !vis[(in2).S] && abs(y1 - (in2).F) <= k) {
				vis[(in2).S] = true;
				v.push((in2).S);
			}
			if (in3.F != -INF && !vis[(in3).S] && abs(x1 - (in3).F) <= k) {
				vis[(in3).S] = true;
				v.push((in3).S);
			}
			if (in4.F != -INF && !vis[(in4).S] && abs(x1 - (in4).F) <= k) {
				vis[(in4).S] = true;
				v.push((in4).S);
			}
		}

	}
	return cnt <= (q + 1);
}

inline void solve() {
	cin >> n >> k;
	mpx.clear();
	mpy.clear();
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> t[i];
		mpx[x[i]].push_back({y[i], i});
		mpy[y[i]].push_back({x[i], i});
	}
	for (auto [l, k] : mpx) {
		sort(mpx[l].begin(), mpx[l].end());
	}
	for (auto [l, k] : mpy) {
		sort(mpy[l].begin(), mpy[l].end());
	}
	for (int i = 0; i < n; i++) {
		auto in1 = lower_bound(mpx[x[i]].begin(), mpx[x[i]].end(), make_pair(y[i], -1)) - 1,
			 in2 = upper_bound(mpx[x[i]].begin(), mpx[x[i]].end(), make_pair(y[i], N)),
			 in3 = lower_bound(mpy[y[i]].begin(), mpy[y[i]].end(), make_pair(x[i], -1)) - 1,
			 in4 = upper_bound(mpy[y[i]].begin(), mpy[y[i]].end(), make_pair(x[i], N));
		an1[i] = (in1 < mpx[x[i]].begin() ? make_pair(-INF, -1) : *in1);
		an2[i] = (in2 >= mpx[x[i]].end() ? make_pair(-INF, -1) : *in2);
		an3[i] = (in3 < mpy[y[i]].begin() ? make_pair(-INF, -1) : *in3);
		an4[i] = (in4 >= mpy[y[i]].end() ? make_pair(-INF, -1) : *in4);
	}
	int l = -1, r = n;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}