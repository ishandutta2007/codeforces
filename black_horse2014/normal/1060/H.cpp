#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int d, p;

const int MX = 105;
int id[MX], x[MX];
int CNT;

LL modExp(LL a, LL n, int m) {
	LL r;
	
	a = (a % m + m) % m;
	for (r = 1; n; n /= 2) {
		if (n & 1) r = r * a % m;
		a = a * a % m;
	}
	return r;
}

int solve(int a[MX][MX], int b[MX], int m, int n, int p) {
	int i, j, r, s;
	LL tp;
	
	for (s = 0; s < n; s++) id[s] = s;
	for (r = 0; r < m; r++) {
		for (; m > r; m--) {
			i = m - 1;
			for (s = r; s < n; s++) {
				if (a[i][s]) break;
			}
			if (s < n) break;
			if (b[i]) return 0;
		}
		if (m == r) break;
		for (j = 0; j < n; j++) swap(a[r][j], a[i][j]);
		swap(b[r], b[i]);
		for (i = 0; i < m; i++) swap(a[i][r], a[i][s]);
		swap(id[r], id[s]);
		
		tp = modExp(a[r][r], p - 2, p);
		for (j = 0; j < n; j++) a[r][j] = a[r][j] * tp % p;
		b[r] = b[r] * tp % p;
		for (i = r + 1; i < m; i++) {
			tp = p - a[i][r];
			for (j = r; j < n; j++) a[i][j] = (a[i][j] + tp * a[r][j]) % p;
			b[i] = (b[i] + tp * b[r]) % p;
		}
	}
	
	if (r < n) return 2;
	for (i = n - 1; i >= 0; i--) {
		for (j = i + 1; j < n; j++) b[i] = (b[i] + LL(p - b[j]) * a[i][j]) % p;
		x[id[i]] = b[i];
	}
	return 1;
}

int ZERO = 4900;
int MINUS = 4901;

void Plus(int a, int b, int to) {
	++CNT;
	printf("+ %d %d %d\n", a, b, to);
}

void Pow(int a, int b) {
	++CNT;
	printf("^ %d %d\n", a, b);
}

void make(int C, int ToC) {
	if (C % 2 == 0) C += p;
	Pow(5000, ToC);
	for (int i = 1; i <= 30; i++) {
		if ((C >> i) & 1) {
			Plus(ToC, 5000-i, ToC);
		}
	}
}

void mul(int a, int C, int ToC) {
	Plus(ZERO, a, 4950);
	for (int i = 0; i <= 30; i++) {
		Plus(4950-i, 4950-i, 4950-i-1);
	}
	Plus(ZERO, ZERO, ToC);
	for (int i = 0; i <= 30; i++) {
		if ((C >> i) & 1) {
			Plus(ToC, 4950 - i, ToC);
		}
	}
}

vector<int> solve() {
	int a[MX][MX], b[MX];
	for (int i = 0; i <= d; i++) {
		for (int j = 0; j <= d; j++) {
			a[i][j] = modExp(j, i, p);
			long long C = 1;
			for (int k = d-i+1; k <= d; k++) C *= k;
			for (int k = 1; k <= i; k++) C /= k;
			a[i][j] = 1LL * a[i][j] * C % p;
		}
		b[i] = (i == d-2) ? 1 : 0;
	}
	assert(solve(a, b, d+1, d+1, p) == 1);
	vector<int> vec;
	for (int i = 0; i <= d; i++) vec.push_back(x[i]);
	return vec;
}

void makeSqr(int a, int To) {
	vector<int> S = solve();
	for (int i = 0; i <= d; i++) make(i, i+10);
	Plus(ZERO, ZERO, To);
	for (int i = 0; i <= d; i++) {
		Plus(a, i+10, i+30);
		Pow(i+30, i+30);
		mul(i+30, S[i], i+30);
		Plus(To, i+30, To);
	}
}

int main() {
	cin >> d >> p;
	for (int i = 0; i <= 30; i++) {
		Plus(5000-i, 5000-i, 5000-i-1);
	}
	make(p, ZERO);
	make(p-1, MINUS);
	Plus(1, 2, 3);
	makeSqr(1, 100);
	makeSqr(2, 101);
	makeSqr(3, 102);
	mul(100, p-1, 100);
	mul(101, p-1, 101);
	Plus(100, 101, 103);
	Plus(102, 103, 103);
	mul(103, (p+1)/2, 10);
	puts("f 10");
	return 0;
}