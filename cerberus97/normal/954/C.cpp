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
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main() {
	int n; cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int x = 1, y;
	bool f = true;
	for (int i = 2; i <= n; ++i) {
		if (a[i] == a[i - 1]) {
			cout << "NO\n";
			return 0;
		} else if (abs(a[i] - a[i - 1]) > 1) {
			f = false;
			y = abs(a[i] - a[i - 1]);
			break;
		}
	}
	if (f) {
		cout << "YES\n 1 " << mx;
		return 0;
	}
	int px = (a[1] - 1) / y, py = (a[1] - 1) % y;
	++px; ++py;
	x = px;
	for (int i = 2; i <= n; ++i) {
		int nx = (a[i] - 1) / y + 1;
		int ny = (a[i] - 1) % y + 1;
		f = false;
		x = max(x, nx);
		if (ny > y) {
			cout << "NO";
			return 0;
		}
		for (int d = 0; d < 4; ++d) {
			if (px + dx[d] == nx and py + dy[d] == ny) {
				f = true;
				px = nx;
				py = ny;
				break;
			}
		}
		if (!f) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n" << x << ' ' << y;
}