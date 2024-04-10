#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

typedef long long ll;

int M;

int add(int a, int b) {
	a += b;
	if (a >= M) {
		return a - M;
	}
	if (a < 0) {
		return a + M;
	}
	return a;
}

int mul(int a, int b) {
	return a * (ll)b % M;
}

int pw(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}

int dv(int a, int b) {
	return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
	a = add(a, b);
}

void mulup(int& a, int b) {
	a = mul(a, b);
}

const int N = (int)1e5 + 7;
int n, a[N], sum;

bool is_in_set(int x) {
	int l = 1, r = n;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) return 1;
		if (a[m] < x) l = m + 1;
		else r = m - 1;
	}
	return 0;
}

bool is_ok(int x, int dif) {
	for (int i = 1; i <= n; i++) {
		if (!is_in_set(x)) return 0;
		addup(x, dif);
	}
	return 1;
}

int helper(int n) {
	return dv(mul(mul(n, add(n, 1)), add(mul(2, n), 1)), 6);
}


int f(int s, int d) {
	int sol = 0, x = 0, y = 0;
	x = helper(n - 1);
	mulup(x, mul(d, d));
	y = dv(mul(n, n - 1), 2);
	mulup(y, mul(2, mul(s, d)));
	addup(sol, add(x, y));
	addup(sol, mul(n, mul(s, s)));
	return sol;
}


signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif
	M = (int)1e9 + 7;

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	cin >> M;
	cin >> n;
	int rl = 0;

	if (n == M) {
		cout << "0 1\n";
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		addup(sum, a[i]);
		addup(rl, mul(a[i], a[i]));
	}
	sort(a + 1, a + n + 1);

	if (n == 1) {
		cout << a[1] << " " << 0 << "\n";
		return 0;
	}
	
	{
		int lmul = dv(2, mul(n, n - 1));
		for (int i = 1; i <= n; i++) {
			int d = mul(add(sum, -mul(n, a[i])), lmul);
			if (d == 0) continue;
			if (f(a[i], d) != rl) continue;
			if (is_ok(a[i], d)) {
				cout << a[i] << " " << d << "\n";
				return 0;
			}
		}
	}
	cout << "-1\n";
}