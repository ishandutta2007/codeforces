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

int main() {
	fast_cin();
	int n; string s;
	cin >> n >> s;
	ll ans = (ll(n) * (n - 1)) / 2;
	map<char, int> nxt;
	nxt['A'] = nxt['B'] = n;
	nxt[s[n - 1]] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		char other = s[i] ^ 'A' ^ 'B';
		if (s[i + 1] != s[i]) {
			ans -= (nxt[s[i]] - i - 1);
		} else if (nxt[other] < n) {
			--ans;
		}
		nxt[s[i]] = i;
	}
	cout << ans << endl;
}