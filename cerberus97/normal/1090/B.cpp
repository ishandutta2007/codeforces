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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	vector<string> text;
	while (true) {
		string s;
		getline(cin, s);
		if (s == "\\begin{thebibliography}{99}") {
			break;
		}
		text.pb(s);
	}
	vector<string> ref;
	for (auto &t : text) {
		int n = t.length(), i = 0;
		while (i < n) {
			while (i < n and t[i] != '\\') {
				++i;
			}
			int j = i;
			while (j < n and t[j] != '}') {
				++j;
			}
			if (i < n) {
				ref.pb(t.substr(i, j - i + 1));
			}
			i = j + 1;
		}
	}
	for (auto &i : ref) {
		i = "\\bibitem" + i.substr(5, i.length());
	}
	bool ok = true;
	int idx = 0;
	map<string, vector<string>> bib;
	string cur;
	while (true) {
		string s;
		getline(cin, s);
		if (s == "\\end{thebibliography}") {
			break;
		}
		if (s[0] == '\\') {
			int i = s.find('}');
			cur = s.substr(0, i + 1);
			if (cur != ref[idx]) {
				ok = false;
			}
			++idx;
			s = s.substr(i + 1, s.length());
		}
		bib[cur].pb(s);
	}
	// for (auto &m : bib) {
	// 	cout << m.first << endl;
	// 	for (auto &j : m.second) {
	// 		cout << j << '\n';
	// 	}
	// }
	if (ok) {
		cout << "Correct\n";
	} else {
		cout << "Incorrect\n";
		cout << "\\begin{thebibliography}{99}\n";
		for (auto &i : ref) {
			cout << i;
			for (auto &j : bib[i]) {
				cout << j << '\n';
			}
		}
		cout << "\\end{thebibliography}\n";
	}
}