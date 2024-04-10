#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

typedef long long ll;
const int M = 998244353;
const int FACTN = 300000 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int add(int a, int b, int c) {
  return add(add(a, b), c);
}

int mul(int a, int b, int c) {
  return mul(mul(a, b), c);
}

int add(int a, int b, int c, int d) {
  return add(add(a, b, c), d);
}

int mul(int a, int b, int c, int d) {
  return mul(mul(a, b, c), d);
}

int add(int a, int b, int c, int d, int e) {
  return add(add(a, b, c, d), e);
}

int mul(int a, int b, int c, int d, int e) {
  return mul(mul(a, b, c, d), e);
}

int add(int a, int b, int c, int d, int e, int f) {
  return add(add(a, b, c, d, e), f);
}

int mul(int a, int b, int c, int d, int e, int f) {
  return mul(mul(a, b, c, d, e), f);
}

int add(int a, int b, int c, int d, int e, int f, int g) {
  return add(add(a, b, c, d, e, f), g);
}

int mul(int a, int b, int c, int d, int e, int f, int g) {
  return mul(mul(a, b, c, d, e, f), g);
}

int add(int a, int b, int c, int d, int e, int f, int g, int h) {
  return add(add(a, b, c, d, e, f, g), h);
}

int mul(int a, int b, int c, int d, int e, int f, int g, int h) {
  return mul(mul(a, b, c, d, e, f, g), h);
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
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

void dvup(int& a, int b) {
  a = dv(a, b);
}

int fact[FACTN], ifact[FACTN];

void computeFACT() {
  fact[0] = 1;
  for (int i = 1; i < FACTN; i++) fact[i] = mul(fact[i - 1], i);
  ifact[FACTN - 1] = dv(1, fact[FACTN - 1]);
  for (int i = FACTN - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
}

int comb(int n, int k) {
	assert(0 <= k && k <= n && n < FACTN);
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int main() {
	computeFACT();
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<ll> prefix_sum(n + 1);
		prefix_sum[0] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			prefix_sum[i + 1] = prefix_sum[i] + a[i];			
		}
		function<ll(int, int)> getsum = [&] (int l, int r) {
			assert(0 <= l && l <= r && r < n);
			return prefix_sum[r + 1] - prefix_sum[l];
		};
		
		function<int(int, int)> solve = [&] (int l, int r) {
			assert(0 <= l && l <= r && r < n);
			if (getsum(l, r) == 0) {
				return pw(2, r - l + 1 - 1);
			}
			if (a[l] == 0 && a[r] == 0) {
				int sol = 0;
				int l2 = l, r2 = r;
				while (a[l2] == 0) {
					l2++;
					assert(l2 <= r);
				}
				while (a[r2] == 0) {
					r2--;
					assert(l <= r2);
				}
				assert(l2 <= r2);
				int cnt1 = l2 - l;
				int cnt2 = r - r2;
				for (int cnt = 0; cnt <= min(cnt1, cnt2); cnt++) {
					addup(sol, mul(comb(cnt1, cnt), comb(cnt2, cnt)));
				}	
				//cout << " = " << cnt1 << " and " << cnt2 << "\n";
				assert(l < l2);
				assert(l2 <= r2);
				assert(r2 < r);
				return mul(sol, solve(l2, r2));
			}
			assert(a[l] != 0 || a[r] != 0);
			int l2 = l, r2 = r;
			while (1) {
			//cout << " : " << l << ", " << r << " : " << l2 << " " << r2 << "\n";
				if (getsum(l, l2) == getsum(r2, r)) {
					break;
				}
				if (getsum(l, l2) < getsum(r2, r)) {
					assert(l2 + 1 <= r);
					l2++;
				} else {
					assert(l <= r2 - 1);
					r2--;
				}
			}
			assert(getsum(l, l2) == getsum(r2, r));
			if (l2 == r || r2 == l) {
				return 1;
			}
			//cout << " = " << l << " " << r << " | " << l2 << " " << r2 << "\n";
			assert(l <= l2 && l2 < r2 && r2 <= r);
			assert(a[l2] > 0 && a[r2] > 0);
			if (l2 + 1 == r2) {
				// empty inside
				return 2;
			}
			assert(l <= l2 && l2 + 2 <= r2 && r2 <= r);
			if (getsum(l2 + 1, r2 - 1) == 0) {
				return pw(2, r2 - l2);
			}
			l = l2 + 1;
			r = r2 - 1;
			l2 = l;
			r2 = r;
			
			while (a[l2] == 0) {
				l2++;
				assert(l2 <= r);
			}
			while (a[r2] == 0) {
				r2--;
				assert(l <= r2);
			}
			assert(l2 <= r2);
			int cnt1 = l2 - l;
			int cnt2 = r - r2;
			int sol = 0;
			for (int cnt = 0; cnt <= min(cnt1 + 1, cnt2 + 1); cnt++) {
				addup(sol, mul(comb(cnt1 + 1, cnt), comb(cnt2 + 1, cnt)));
			}	
			assert(l2 <= r2);
			return mul(sol, solve(l2, r2));
		};
		
		int sol = solve(0, n - 1);
		cout << sol << "\n";	
	}
	
	return 0;
}
/*
solution = 
1
2
3
4
2
150994942
*/