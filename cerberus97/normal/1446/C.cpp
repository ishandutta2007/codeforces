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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, B = 31;

int solve(vector<int>& a, int l, int r, int b);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	cout << n - solve(a, 0, n - 1, B) << '\n';
}

int solve(vector<int>& a, int l, int r, int b) {
	if (r - l + 1 <= 2) {
		return r - l + 1;
	} else {
		int mid = l - 1;
		while (mid < r and ((a[mid + 1] >> b) & 1) == 0) {
			++mid;
		}
		int s1 = solve(a, l, mid, b - 1), s2 = solve(a, mid + 1, r, b - 1);
		return max(s1 + min(s2, 1), s2 + min(s1, 1));
	}
}