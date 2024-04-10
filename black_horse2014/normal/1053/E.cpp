#include <bits/stdc++.h>
using namespace std;

void no() {
	cout << "no" << endl;
	exit(0);
}

const int N = 2200000;
vector<int> p[N], rest;
int a[N], nxt[N], ban[N], s[N];

vector<tuple<int, int, int>> ev;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	if (n == 1) return cout << "yes" << endl << "1" << endl, 0;
	int flg = -1;
	for (int i = 0; i < n+n-1; i++) {
		cin >> a[i];
		if (a[i] && flg < 0) flg = i;
	}
	if (flg < 0) a[0] = 1, flg = 0;
	int la = n + n - 2;
	if (a[0] != a[la]) {
		if (a[0] && a[la]) no();
		a[0] = a[la] = max(a[0], a[la]);
	}
	for (int i = flg; i < flg+n+n-1; i++) {
		a[i] = a[i%(n+n-2)];
		if (a[i]) p[a[i]].push_back(i);
		nxt[i] = i+1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < p[i].size(); j++) {
			int d = p[i][j] - p[i][0];
			if (d & 1) no();
			ev.emplace_back(d, p[i][0], p[i][j]);
		}
		if (p[i].empty()) rest.push_back(i);
	}
	sort(ev.begin(), ev.end());
	for (auto t : ev) {
		int p = lower_bound(ev.begin(), ev.end(), t) - ev.begin();
		int d, l, r; tie(d, l, r) = t;
		int c = l;
		deque<int> cv, id;
		int cns = 0;
		while (c != r) {
			cv.push_back(a[c]);
			id.push_back(c);
			if (a[c]) {
				if (ban[a[c]]) no();
				cns++;
			}
			c = nxt[c];
		};
		for (int i = 1; i < cv.size(); i++) ban[cv[i]] = 1;
		d = cv.size();
		nxt[l] = r+1;
		if (cns > d / 2 + 1) no();
		if (d == 2 && cns == 2) continue;
		int wh = -1, mi = 1e9;
		for (int i = 0; i < cv.size(); i++) {
			s[i] = (i ? s[i-1] : 0) + (cv[i] ? 1 : -1);
			if (mi >= s[i]) mi = s[i], wh = i;
		}
		for (int i = 0; i <= wh; i++) {
			int fr = cv.front(); cv.pop_front(), cv.push_back(fr);
			fr = id.front(), id.pop_front(), id.push_back(fr);
		}
		vector<int> sta;
		for (int i = 0; i < cv.size(); i++) {
			if (cv[i]) {
				sta.push_back(cv[i]);
			} else {
				if (sta.size() >= 2) {
					a[id[i]] = sta[sta.size()-2];
					sta.pop_back();
				} else {
					int nw = rest.back();
					a[id[i]] = nw;
					rest.pop_back();
					sta.push_back(nw);
				}
			}
		}
	}
	cout << "yes" << endl;
	for (int i = 0; i < 2*n-1; i++) cout << max(a[i], a[i+n+n-2]) << ' ';
}