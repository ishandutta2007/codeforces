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

const int N = 2e5 + 10;

int a[N];

int main() {
	int h;
	cin >> h;
	for (int i = 0; i <= h; ++i) {
		cin >> a[i];
	}

	bool check = false;
	for (int i = 1; i < h; ++i) {
		if (a[i] > 1 and a[i + 1] > 1) {
			check = true;
			break;
		}
	}

	if (!check) {
		cout << "perfect\n";
	} else {
		cout << "ambiguous\n";
		int l = 0, r = 0;
		for (int i = 0; i <= h; ++i) {
			for (int j = 0; j < a[i]; ++j) {
				cout << l << ' ';
			}

			r = r + a[i];
			l = r - a[i] + 1;
		}

		l = r = 0;
		cout << endl;
		for (int i = 0; i <= h; ++i) {
			int cur = l;
			for (int j = 0; j < a[i]; ++j) {
				cout << cur << ' ';
				cur = min(cur + 1, r);
			}

			r = r + a[i];
			l = r - a[i] + 1;
		}

		cout << endl;
	}
}