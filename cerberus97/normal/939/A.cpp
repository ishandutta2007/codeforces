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

int f[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
	bool ans = false;
	for (int i = 1; i <= n; ++i) {
		int p = i;
		for (int j = 0; j < 3; ++j) {
			p = f[p];
		}
		if (p == i) {
			ans = true;
			break;
		}
	}
	if (ans) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}