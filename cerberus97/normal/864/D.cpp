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

int a[N], ctr[N] = {0};
bool seen[N] = {0}, skip[N] = {0};

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++ctr[a[i]];
	}
	int j = 1, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ctr[a[i]] > 1) {
			while (ctr[j]) {
				++j;
			}
			if (!skip[a[i]] and a[i] < j) {
				skip[a[i]] = true;
			}
			else {
				--ctr[a[i]];
				++ctr[j];
				++ans;
				a[i] = j;
			}
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
}