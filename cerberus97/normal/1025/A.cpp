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
	int n; cin >> n;
	string s; cin >> s;
	map<int, int> colors;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		colors[s[i]]++;
		mx = max(mx, colors[s[i]]);
	}
	if (mx > 1 or colors.size() == 1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}