#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long long ll;
const int M = (int) 1e9 + 7;
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

int main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif 
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		vector<int> inv(n + 1);
		for (int i = 0; i <= n; i++) {
			inv[i] = dv(1, pw(2, i));
		}
		vector<int> pwin(n, 0);
		int ptr = n - 1, sum = 1;
		for (int i = n - 1; i >= 1; i--) {
			// [j, i] => length i - j + 1
			// [0, j - 1] => length j
			/*
			i - j + 1 >= j
			i >= 2 * j - 1
			i + 1 >= 2 * j
			j <= (i + 1) / 2
			
		
		
			*/
			int j = (i + 1) / 2;
			//cout << " : " << i << " -> " << j << "\n";
			// [j, i] is fixed if i < n - 1 and [j, i - 1] is fixed if i == n - 1
			if (i == n - 1) {
				pwin[i] = inv[i - j];
			}	else {
				pwin[i] = inv[i - j + 1];
				// this needs to happen and also no one after him should win
				while (ptr >= 2 * i + 1) {
					addup(sum, -pwin[ptr--]);		
				}
				pwin[i] = mul(pwin[i], sum);
			}
		}
		for (auto &p : pwin) {
			cout << p << "\n";
		}
	}
  return 0;
}