#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstring>
#define null NULL
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

const int mx = 2000100;
pair<int, int> t[5*mx];

void push (int v) {
	if (t[v] != make_pair(-1, -1)) {
		t[v*2+1] = t[v];
		t[v*2] = t[v];
		t[v] = {-1, -1};
	}
}

void update (int v, int tl, int tr, int l, int r, pair<int, int> color) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = color;
	else {
		push (v);
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), color);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, color);
	}
}

pair<int, int> get (int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	push (v);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return get (v*2, tl, tm, pos);
	else
		return get (v*2+1, tm+1, tr, pos);
}

int n, k;
vector<string> s;
vector<vector<int> > v;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	int tmp;
	for (int i = 0; i < 5*mx; ++i) {
		t[i] = {-1, -1};
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		s.push_back(str);
		v.push_back(vector<int> ());
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> tmp;
			v.back().push_back(tmp);
			update(1, 0, mx-1, tmp-1, tmp + str.length() - 2, {i, tmp-1});
		}
	}
	int m = mx;
	for (int i = mx-1; i >= 0; --i) {
		if (get(1, 0, mx-1, i) != make_pair(-1, -1)) {
			m = i;
			break;
		}
	}
	for (int i = 0; i <= m; ++i) {
		pair<int, int> x = get(1, 0, mx-1, i);
		if (x.first != -1)
			cout << s[x.first][i-x.second];
		else
			cout << 'a';
	}
	cout << '\n';
	return 0;
}