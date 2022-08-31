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
const double inf = 1e30;

int main() {
	int n, m;
	cin >> n >> m;
	double best = inf;
	for (int i = 0; i < n; ++i) {
		double a, b;
		cin >> a >> b;
		double temp = (a / b) * m;
		if (temp < best) {
			best = temp;
		}
	}

	cout << fixed << setprecision(8) << best << endl;
}