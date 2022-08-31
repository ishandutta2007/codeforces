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
	int n, a, b, x = 0, y = 0;
	cin >> n >> a >> b;
	while (a * x <= n) {
		int temp = n - a * x;
		if (temp % b == 0) {
			y = temp / b;
			break;
		} else {
			++x;
		}
	}
	if (a * x + b * y == n) {
		int st = 1;
		for (int i = 0; i < x; ++i) {
			for (int j = st + 1; j < st + a; ++j) {
				cout << j << ' ';
			}
			cout << st << ' ';
			st = st + a;
		}
		for (int i = 0; i < y; ++i) {
			for (int j = st + 1; j < st + b; ++j) {
				cout << j << ' ';
			}
			cout << st << ' ';
			st = st + b;
		}
	} else {
		cout << -1;
	}
}