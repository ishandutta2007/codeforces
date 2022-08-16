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

const int N = 2e5 + 10, D = 300, D2 = N / D + 10;

int nxt[N];
int cnt[N * D];

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	s = ' ' + s;
	nxt[n + 1] = n + 1;
	for (int i = n; i >= 1; --i) {
		nxt[i] = nxt[i + 1];
		if (s[i] == '1') {
			nxt[i] = i;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i - 1, ones = 0;
		while (ones <= D2) {
			j = nxt[j + 1];
			if (j == n + 1) {
				break;
			}
			++ones;
			int tmp = nxt[j + 1];
			int l = j - i + 1, r = tmp - i;
			l = max(l, D * ones + 1);
			if (l <= r) {
				ans += r / ones - (l - 1) / ones;
			}
		}
	}
	int offset = n;
	for (int k = 0; k < D; ++k) {
		ll cur = 0;
		cnt[cur + offset]++;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0') {
				--cur;
			} else {
				cur += k;
			}
			ans += cnt[cur + offset];
			++cnt[cur + offset];
		}
		cur = 0;
		--cnt[cur + offset];
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0') {
				--cur;
			} else {
				cur += k;
			}
			cnt[cur + offset] = 0;
		}
	}
	cout << ans << endl;
}