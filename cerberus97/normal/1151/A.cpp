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

const int N = 1e5 + 10, inf = 1e9 + 42;

int cost(char a, char b);

int main() {
	fast_cin();
	int n; string s;
	cin >> n >> s;
	int ans = inf;
	string res = "ACTG";
	for (int i = 0; i < n - 3; ++i) {
		string t = s.substr(i, 4);
		int temp = 0;
		for (int j = 0; j < 4; ++j) {
			temp += cost(t[j], res[j]);
		}
		ans = min(ans, temp);
	}
	cout << ans << endl;
}

int cost(char a, char b) {
	int c1 = (a - b + 26) % 26;
	int c2 = (b - a + 26) % 26;
	return min(c1, c2);
}