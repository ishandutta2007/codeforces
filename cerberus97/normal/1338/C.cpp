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
const ll one = 1;

int main() {
	fast_cin();
	vector<ll> perm = {0, 2, 3, 1}; 
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll triple = (n - 1) / 3, pos = (n - 1) % 3;
		for (int i = 0; ; i += 2) {
			if (triple >= (one << i)) {
				triple -= (one << i);
			} else {
				vector<ll> here;
				here.pb((one << i) + triple);
				here.pb(0);
				ll& y = here.back();
				for (int j = 0; j < i; j += 2) {
					y |= (perm[triple % 4] << j);
					triple /= 4;
				}
				here[1] += (one << (i + 1));
				here.pb(here[0] ^ here[1]);
				cout << here[pos] << '\n';
				break;
			}
		}
	}
}