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

const int N = 1e3 + 10;

struct student {
	int s, id;
	bool operator<(const student &o) {
		if (s != o.s) {
			return s > o.s;
		}
		return id < o.id;
	}
} g[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		g[i].s = 0;
		g[i].id = i;
		for (int j = 0; j < 4; ++j) {
			int a; cin >> a;
			g[i].s += a;
		}
	}
	sort(g + 1, g + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (g[i].id == 1) {
			cout << i << endl;
			break;
		}
	}
}