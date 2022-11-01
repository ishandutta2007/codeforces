#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int DEBUG = false;

typedef pair<int, int> EXP_VAL;

#define plus PLUS
#define minus MINUS

vector<int> plus[N], minus[N];
int power10[N][2];
int match[N];
char s[N];
int n;

int power(int a, int b, int mod = MOD) {
	int ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			ret = 1LL * ret * a % mod;
		}
		a = 1LL * a * a % mod;
	}
	return ret;
}

EXP_VAL concat(EXP_VAL a, EXP_VAL b) {
	return {(1LL * a.first * b.second % MOD + b.first) % MOD,
		1LL * a.second * b.second % MOD};
}

EXP_VAL parse_exp(int dep, int l, int r);

int parse_number(int l, int r, int mod) {
	if (DEBUG) cout << "parse number " << string(s + l, s + r + 1) << endl;
	int ret = 0;
	for (int i = l; i <= r; i++) {
		ret = (ret * 10LL + s[i] - '0') % mod;
	}
	return ret;
}

int sum(int a, int b[2]) {
	// return a^0 + ... a^(b-1) % MOD
	if (a == 1) {
		return b[0] % MOD;
	}
	int upper = power(a, b[1], MOD) + MOD - 1;
	int lower = a + MOD - 1;
	return 1LL * upper % MOD * power(lower % MOD, MOD - 2, MOD) % MOD;
}

EXP_VAL brute_force(int x) {
	EXP_VAL ret = {0, 1};
	for (int i = 1; i <= x; i++) {
		int p = 1, t = i;
		while (t) {
			(p *= 10) %= MOD;
			t /= 10;
		}
		ret = concat(ret, {i, p});
	}
	return ret;
}

EXP_VAL get_val(int r, long long number[2], int l) {
	int p = power10[l][0];
	if (DEBUG) cout << r << " " << number[1] << " " << p << endl;
	// number = r - l
	assert(p != 1);
	int ret = 0;
	if (p == 1) {
		ret = 1LL * r * (number[0] + 1) % MOD;
		ret -= 1LL * number[0] * (number[0] + 1) / 2 % MOD;
	} else {
		int n = number[1];
		ret = 1LL * r * (power(p, n + 1) + MOD - 1) % MOD * power(p - 1, MOD - 2) % MOD;
		int ms = 1LL * number[0] * power(p, n + 1) % MOD;
		ms -= 1LL * (power(p, n + 1) - 1) * power(p - 1, MOD - 2) % MOD;
		ms ++;
		ms = 1LL * (ms % MOD + MOD) % MOD * power(p - 1, MOD - 2) % MOD;
		ret -= ms;
	}
	if (ret < 0) ret += MOD;
	return {ret, power(10, 1LL * (number[1] + 1) * l % (MOD - 1))};
}

EXP_VAL calc(string s, int op = 0) {
	if (DEBUG) cout << "parse calc " << s << " op = " << op << endl;
	static int a[N];
	int m = s.size();
	for (int i = 0; i < m; i++) {
		a[i] = s[m - i - 1] - '0';
	}
	if (s == "0" || (s == "1" && op == 1)) {
		return {0, 1};
	}
	if (op) {
		a[0]--;
		for (int i = 0; i < m; i++) {
			if (a[i] < 0) {
				a[i] += 10;
				a[i + 1]--;
			}
		}
		while (m > 1 && a[m - 1] == 0) m--;
	}
	EXP_VAL ret = {0, 1};
	for (int i = 1; i < m; i++) {
		long long number[2] = {
			(power10[i][0] - 1 - power10[i - 1][0] + MOD) % MOD,
			(power10[i][1] - 1 - power10[i - 1][1] + MOD - 1) % (MOD - 1)};
		ret = concat(ret, get_val((power10[i][0] + MOD - 1) % MOD, number, i));
	}
	int r[2] = {0};
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < 2; j++) {
			int mod = (MOD - j);
			r[j] = (r[j] * 10LL + a[i]) % mod;
		}
	}
	long long number[2] = {
		(r[0] - power10[m - 1][0] + MOD) % MOD,
		(r[1] - power10[m - 1][1] + MOD - 1) % (MOD - 1)};
	ret = concat(ret, get_val(r[0], number, m));
	if (DEBUG) cout << "result = " << ret.first << " " << ret.second << endl;
	return ret;
}

EXP_VAL parse_term(int dep, int l, int r) {
	if (DEBUG) cout << "parse term " << string(s + l, s + r + 1) << endl;
	if (s[r] == ')') {
		int p = match[r];
		auto e = parse_exp(dep + 1, p + 1, r - 1);
		int number[2] = {parse_number(l, p - 1, MOD), parse_number(l, p - 1, MOD - 1)};
		return {1LL * e.first * sum(e.second, number) % MOD, power(e.second, number[1])};
	} else {
		int i = upper_bound(minus[dep].begin(), minus[dep].end(), r) - minus[dep].begin() - 1;
		if (i < 0 || minus[dep][i] < l) return {parse_number(l, r, MOD), power10[r - l + 1][0]};
		int p = minus[dep][i];
		auto eval_l = calc(string(s + l, s + p), 1);
		auto eval_r = calc(string(s + p + 1, s + r + 1));
		int second = 1LL * eval_r.second * power(eval_l.second, MOD - 2) % MOD;
		int first = eval_r.first - 1LL * eval_l.first * second % MOD;
		if (first < 0) first += MOD;
		return {first, second};
	}
}

EXP_VAL parse_exp(int dep, int l, int r) {
	if (DEBUG) cout << "parse exp " << string(s + l, s + r + 1) << endl;
	// found plus;
	int i = upper_bound(plus[dep].begin(), plus[dep].end(), r) - plus[dep].begin() - 1;
	if (i < 0 || plus[dep][i] < l) return parse_term(dep, l, r);
	int p = plus[dep][i];
	auto a = parse_exp(dep, l, p - 1), b = parse_term(dep, p + 1, r);
	return concat(a, b);
}

void prepare() {
	power10[0][0] = power10[0][1] = 1;
	for (int i = 0; i < n; i++) {
		power10[i + 1][0] = power10[i][0] * 10LL % MOD;
		power10[i + 1][1] = power10[i][1] * 10LL % (MOD - 1);
	}
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	prepare();
	vector<int> stack;
	for (int i = 0, cur = 0; i < n; i++) {
		switch (s[i]) {
		case '(' : cur++; stack.push_back(i); break;
		case ')' : cur--; match[stack.back()] = i, match[i] = stack.back(); stack.pop_back(); break;
		case '+' : plus[cur].push_back(i); break;
		case '-' : minus[cur].push_back(i); break;
		}
	}
	cout << parse_exp(0, 0, n - 1).first << endl;
	return 0;
}