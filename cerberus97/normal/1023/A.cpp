/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int p = s.find("*");
	if (m < n - 1) {
		cout << "NO\n";
		return 0;
	}
	if (p != -1) {
		s = s.substr(0, p) + t.substr(p, m - n + 1) + s.substr(p + 1, n);
	}
	// cout << s << ' ' << t << endl;
	if (s == t) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}