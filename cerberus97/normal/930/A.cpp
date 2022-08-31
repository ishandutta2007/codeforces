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

int ctr[N], ht[N];

int main() {
	int n;
	cin >> n;
	ht[1] = 0;
	ctr[0] = 1;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		ht[i] = 1 + ht[p];
		++ctr[ht[i]];
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (ctr[i] % 2) {
			++ans;
		}
	}
	cout << ans;
}