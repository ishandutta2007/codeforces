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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

ll a[N];

int main() {
	fast_cin();
	int n, k, m;
	cin >> n >> k >> m;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	ll bnum = 0, bden = 1;
	for (int i = 0; i < n and m > -1; ++i) {
		ll cden = n - i;
		ll cnum = sum + min(cden * k, ll(m));
		if (cnum * bden > cden * bnum) {
			bnum = cnum;
			bden = cden;
		}
		--m;
		sum -= a[i + 1];
	}
	cout << fixed << setprecision(10) << ld(bnum) / bden << endl;
}