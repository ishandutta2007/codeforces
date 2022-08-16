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

const int N = 1e5 + 10, A = 500;

int ctr[A];

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	for (auto &i : s) {
		++ctr[i];
	}
	int temp = 0;
	for (char c = 'a'; c <= 'z'; ++c) {
		if (ctr[c] > 1) {
			++temp;
		}
	}
	if (temp < 2) {
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		string t = s.substr(i, n) + s.substr(0, i);
		string x = t;
		reverse(x.begin(), x.end());
		if (t == x and t != s) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
}