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

int t[N];
bool seen[N];

int main() {
	fast_cin();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}

	int ans = 0;
	for (int i = n; i >= 0; --i) {
		if (seen[i]) {
			continue;
		} else {
			++ans;
			int j = i;
			while (j and !seen[t[j]]) {
				seen[t[j]] = true;
				j = t[j];
			}
		}
	}

	cout << ans << endl;
}