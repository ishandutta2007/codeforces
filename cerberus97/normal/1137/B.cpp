/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10;

int ctr_s[2], suff[N][2];

vector<int> compute_Z(string s);

int main() {
	fast_cin();
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	for (auto &i : s) {
		ctr_s[i - '0']++;
	}
	suff[m][0] = suff[m][1] = 0;
	// cout << "HERE" << endl;
	for (int i = m - 1; i >= 0; --i) {
		suff[i][0] = suff[i + 1][0];
		suff[i][1] = suff[i + 1][1];
		suff[i][t[i] - '0']++;
	}
	if (ctr_s[0] < suff[0][0] or ctr_s[1] < suff[0][1]) {
		cout << s << endl;
		return 0;
	}
	vector<int> z = compute_Z(t);
	int p = m;
	for (int i = 1; i < m; ++i) {
		if (z[i] == m - i) {
			p = i;
			break;
		}
	}
	int len = m;
	string cur = t;
	ctr_s[0] -= suff[0][0];
	ctr_s[1] -= suff[0][1];
	while (true) {
		if (ctr_s[0] < suff[m - p][0] or ctr_s[1] < suff[m - p][1]) {
			break;
		}
		ctr_s[0] -= suff[m - p][0];
		ctr_s[1] -= suff[m - p][1];
		cur += t.substr(m - p, p);
		len += p;
	}
	while (ctr_s[0]) {
		--ctr_s[0];
		cur += '0';
	}
	while (ctr_s[1]) {
		--ctr_s[1];
		cur += '1';
	}
	cout << cur << endl;
}

vector<int> compute_Z(string s) {
	int n = s.length();
	vector<int> z(n, 0);
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (r >= i) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n and s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}