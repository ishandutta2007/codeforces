#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

bool home;
int M;
const int FACTN = 5000 + 7;

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

void dvup(int& a, int b) {
	a = dv(a, b);
}

int fact[FACTN], ifact[FACTN];

void computeFactorials() {
	fact[0] = 1;
	for (int i = 1; i < FACTN; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	ifact[FACTN - 1] = dv(1, fact[FACTN - 1]);
	for (int i = FACTN - 2; i >= 0; i--) {
		ifact[i] = mul(ifact[i + 1], i + 1);
	}
}

const int N = 5000 + 7;
int pt[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	n = 8;
	M = 998244353;

	home = true;
#ifdef ONLINE_JUDGE
	home = false;
	cin >> n >> M;
#endif 
	computeFactorials();
	for (int x = 0; x <= n; x++) {
		pt[x][0] = 1;
		for (int i = 1; i <= n; i++) {
			pt[x][i] = mul(pt[x][i - 1], x);
		}
	}
	int print = 0;
	for (int sum = 1; sum <= n; sum++) {
		for (int cnt = 1; 2 * cnt <= sum; cnt++) {
			int coef = 1;
			mulup(coef, ifact[cnt]);
			mulup(coef, ifact[cnt - 1]);
			mulup(coef, ifact[sum - 2 * cnt]);
			mulup(coef, fact[sum - cnt - 1]);
			mulup(coef, ifact[n - sum]);
			mulup(coef, pt[n - 1][cnt]);
			mulup(coef, pt[sum - cnt][n - sum]);
			addup(print, coef);
		}
	}
	mulup(print, fact[n]);
	cout << print << "\n";
}