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

const int N = 3000 + 10;

int match_index(string s, string t);
void getLPS(string s, int *lps);
vector<int> KMP(string s, string w);

string w[N], f[N];
int pl[N], pr[N], lps[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
	string s = "", t = "";
	for (int i = 1; i <= n; ++i) {
		if (w[i] == f[i]) {
			pl[i] = pr[i] = -1;
			continue;
		}
		int m = w[i].length(), l = 0;
		while (w[i][l] == f[i][l]) {
			++l;
		}
		int r = m - 1;
		while (w[i][r] == f[i][r]) {
			--r;
		}
		pl[i] = l;
		pr[i] = r;
		if (s == "") {
			s = w[i].substr(l, r - l + 1);
			t = f[i].substr(l, r - l + 1);
		} else if (s != w[i].substr(l, r - l + 1)) {
			cout << "NO\n";
			return 0;
		}
	}
	while (true) {
		char ch = 0;
		for (int i = 1; i <= n; ++i) {
			if (pl[i] == -1) {
				continue;
			} else if (pl[i] == 0) {
				ch = 0;
				break;
			} else if (ch == 0) {
				ch = w[i][pl[i] - 1];
			} else if (ch != w[i][pl[i] - 1]) {
				ch = 0;
				break;
			}
		}
		if (ch) {
			for (int i = 1; i <= n; ++i) {
				if (pl[i] != -1) {
					--pl[i];
				}
			}
			s = ch + s;
			t = ch + t;
		} else {
			break;
		}
	}
	while (true) {
		char ch = 0;
		for (int i = 1; i <= n; ++i) {
			if (pr[i] == -1) {
				continue;
			} else if (pr[i] == w[i].length() - 1) {
				ch = 0;
				break;
			} else if (ch == 0) {
				ch = w[i][pr[i] + 1];
			} else if (ch != w[i][pr[i] + 1]) {
				ch = 0;
				break;
			}
		}
		if (ch) {
			for (int i = 1; i <= n; ++i) {
				if (pr[i] != -1) {
					++pr[i];
				}
			}
			s = s + ch;
			t = t + ch;
		} else {
			break;
		}
	}
	getLPS(s, lps);
	for (int i = 1; i <= n; ++i) {
		int j = match_index(w[i], s);
		if (j != -1) {
			for (auto &c : t) {
				w[i][j++] = c;
			}
		}
		if (w[i] != f[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	cout << s << '\n' << t << '\n';
}

int match_index(string s, string t) {
	vector<int> matches = KMP(s, t);
	if (!matches.empty()) {
		return matches[0];
	} else {
		return -1;
	}
}

void getLPS(string s, int *lps)
{
	int n = s.length();

	lps[0] = -1;
	lps[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		int cur = lps[i-1];
		lps[i] = 0;

		while (cur >= 0)
		{
			if (s[cur] == s[i-1])
			{
				lps[i] = cur+1;
				break;
			}

			cur = lps[cur];
		}
	}
}

vector<int> KMP(string s, string t)
{
	int i = 0, m = 0, n = s.length(), k = t.length();
	vector<int> matches;

	while (i <= n-k)
	{
		if (m == k)
		{
			matches.push_back(i);
			i = i + m - lps[m];
			m = lps[m];
		}

		else if (s[i+m] == t[m])
			++m;

		else
		{
			i = i + m - lps[m];
			m = max(0, lps[m]);
		}
	}
	return matches;
}