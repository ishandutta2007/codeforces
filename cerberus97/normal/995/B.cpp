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

const int N = 120;

int a[N];

int main() {
	int n; cin >> n;
	n *= 2;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	set<int> s;
	for (int i = 1; i <= n; ++i) {
		if (s.find(a[i]) != s.end()) {
			int j = i;
			while (a[j] != a[j - 1]) {
				++ans;
				swap(a[j], a[j - 1]);
				--j;
			}
			s.erase(a[j]);
		} else {
			s.insert(a[i]);
		}
	}
	cout << ans;
}