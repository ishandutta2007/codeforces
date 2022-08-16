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

int d[N];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		++d[u];
		++d[v];
	}
	int ctr = 0, centre = 1;
	for (int i = 1; i <= n; ++i) {
		if (d[i] > 2) {
			++ctr;
			centre = i;
		}
	}
	if (ctr > 1) {
		cout << "No";
	} else {
		cout << "Yes\n" << d[centre] << '\n';
		for (int i = 1; i <= n; ++i) {
			if (d[i] == 1 and i != centre) {
				cout << centre << ' ' << i << '\n';
			}
		}
	}
}