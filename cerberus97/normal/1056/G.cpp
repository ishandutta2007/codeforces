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

bool vis[N];
int target[N], pos[N];	

int main() {
	fast_cin();
	int n, m, s; ll t;
	cin >> n >> m >> s >> t;
	--s;
	while (t % n) {
		int temp = t % n;
		if (s < m) {
			s += temp;
		} else {
			s -= temp;
			s += n;
		}
		s %= n;
		--t;
	}
	int it = 0;
	t /= n;
	while (t) {
		if (vis[s]) {
			ll period = it - pos[s];
			t %= period;
			while (t--) {
				s = target[s];
			}
			break;
		} else {
			vis[s] = true;
			pos[s] = it;
			int v = s;
			for (int i = n - 1; i >= 1; --i) {
				if (v < m) {
					v += i;
				} else {
					v -= i;
					v += n;
				}
				v %= n;
			}
			target[s] = v;
			s = v;
		}
		--t;
		++it;
	}
	cout << s + 1 << endl;
}