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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int sum = 0;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
			sum += i;
		}
		if (sum == 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			sort(a.begin(), a.end());
			if (sum > 0) {
				reverse(a.begin(), a.end());
			}
			for (auto& i : a) {
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
}