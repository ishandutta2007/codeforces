#include <bits/stdc++.h>

using namespace std;

struct fenwick
{
	vector<int> t;
	fenwick() {}
	void init(int n) {
		t.resize(n);
	}
	void update(int pos, int delta) {
		while (pos < t.size()) {
			t[pos] += delta;
			pos = pos | (pos + 1);
		}
	}
	int sum(int r) {
		int res = 0;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l-1);
	}
};

int getint(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
}

const int mx = 150000;
int n, q, a[mx], t, pos, l, r;
char c;
string s;
fenwick f[4][11][10];

void make(int pos, int let, int mod) {
	for (int j = 1; j <= 10; ++j) {
		f[let][j][pos % j].update(pos, mod);
	}
}

int main() {
	cin >> s;
	n = s.length();
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j <= 10; ++j) {
			for (int k = 0; k < j; ++k) {
				f[i][j][k].init(n);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		a[i] = getint(s[i]);
		make(i, a[i], 1);
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> t;
		if (t == 1) {
			cin >> pos >> c;
			pos--;
			make(pos, a[pos], -1);
			make(pos, getint(c), 1);
			a[pos] = getint(c);
		}
		else {
			cin >> l >> r >> s;
			l--;
			r--;
			int res = 0, e = s.length();
			for (int j = 0; j < min(e, r-l+1); ++j) {
				res += f[getint(s[j])][e][(l + j) % e].sum(l, r);
            }
			cout << res << endl;
		}
	}
}