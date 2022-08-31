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

ll s[N], a[N], b[N], v1[N], v2[N];

int main() {
	fast_cin();
	int n, S;
	cin >> n >> S;
	ll sum = 0, sum1 = 0, sum2 = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> a[i] >> b[i];
		if (a[i] >= b[i]) {
			v1[a[i] - b[i]] += s[i];
			ans += b[i] * s[i];
			sum1 += s[i];
		}
		else {
			v2[b[i] - a[i]] += s[i];
			ans += a[i] * s[i];
			sum2 += s[i];
		}
		sum += s[i];
	}
	ll m = (sum / S) + !!(sum % S), m1 = (sum1 / S) + !!(sum1 % S), m2 = (sum2 / S) + !!(sum2 % S);
	ll t1 = 0, t2 = 0, s1 = (m - m2) * S, s2 = (m - m1) * S;
	for (int i = N - 1; i >= 1; --i) {
		t1 += v1[i] * i;
		t2 += v2[i] * i;
		if (v1[i] and s1) {
			t2 += i * min(v1[i], s1);
			s1 -= min(v1[i], s1);
		}
		if (v2[i] and s2) {
			t1 += i * min(v2[i], s2);
			s2 -= min(v2[i], s2);
		}
	}
	cout << ans + max(t1, t2);
}