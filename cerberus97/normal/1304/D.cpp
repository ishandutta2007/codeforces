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
#include <numeric>

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
	int t; cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;
		s = " " + s;
		int nxt = n;
		s[0] = '>';
		for (int i = 0; i < n;) {
			int p1 = i;
			while (p1 < n and s[p1] != '<') {
				++p1;
			}
			int p2 = p1;
			while (p2 < n and s[p2] != '>') {
				++p2;
			}
			for (int val = nxt - (p2 - p1), cnt = 0; cnt < (p1 - i); ++cnt, --val) {
				cout << val << ' ';
			}
			for (int val = nxt - (p2 - p1) + 1, cnt = 0; cnt < (p2 - p1); ++cnt, ++val) {
				cout << val << ' ';
			}
			nxt -= (p2 - i);
			i = p2;
		}
		cout << '\n';
		nxt = 1;
		s[0] = '<';
		for (int i = 0; i < n;) {
			int p1 = i;
			while (p1 < n and s[p1] != '>') {
				++p1;
			}
			int p2 = p1;
			while (p2 < n and s[p2] != '<') {
				++p2;
			}
			for (int val = nxt + (p2 - p1), cnt = 0; cnt < (p1 - i); ++cnt, ++val) {
				cout << val << ' ';
			}
			for (int val = nxt + (p2 - p1) - 1, cnt = 0; cnt < (p2 - p1); ++cnt, --val) {
				cout << val << ' ';
			}
			nxt += (p2 - i);
			i = p2;
		}
		cout << '\n';
	}
}