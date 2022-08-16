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
#include <random>
#include <chrono>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = (1 << 12) + 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int a[N], b[N], p[N], q[N], loc[N];

void upd(int i, int j, int x);

int main() {
	fast_cin();
	int k; cin >> k;
	int n = (1 << k);
	int test = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		p[i] = q[i] = i;
		test ^= a[i];
	}
	if (test) {
		cout << "Fou\n";
		return 0;
	}
	shuffle(p, p + n, rng);
	shuffle(q, q + n, rng);
	for (int i = 0; i < n; ++i) {
		b[i] = p[i] ^ q[i];
		loc[p[i]] = i;
	}
	cout << "Shi\n";
	for (int i = 0; i < n - 1; ++i) {
		upd(i, i + 1, b[i] ^ a[i]);
	}
	for (int i = 0; i < n; ++i) {
		cout << p[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; ++i) {
		cout << q[i] << ' ';
	}
	cout << '\n';
}

void upd(int i, int j, int x) {
	int s = i;
	b[i] ^= x;
	b[j] ^= x;
	while ((p[i] ^ q[i]) != b[i]) {
		int t = loc[b[i] ^ q[i]];
		swap(loc[p[i]], loc[p[t]]);
		swap(p[i], p[t]);
		swap(q[t], q[j]);
		i = t;
		if (i > s) {
			break;
		}
	}
}