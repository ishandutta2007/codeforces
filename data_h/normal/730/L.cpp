#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

#define plus PLUS

const int MOD = 1e9 + 7;
const int N = 4e5 + 7;
const int LOG = 20;

int n;
int match[N], dep[N];
vector<int> plus[N], times[N];
char s[N];
int f[N][LOG], g[N][LOG], go[N][LOG];
int suffix[N], prefix[N], nxt_opt[N], bv[N];

void add(int &a, int b) {
	if ((a += b) >= MOD) a -= MOD;
}

void mul(int &a, int b) {
	a = 1LL * a * b % MOD;
}

bool is_digit(char c) {
	return '0' <= c && c <= '9';
}

int power(int a, int n) {
	int ret = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (n & i) {
			mul(ret, a);
		}
		mul(a, a);
	}
	return ret;
}

int dfs(int l, int r, int cur) {
/*
	for (int i = l; i <= r; i++) {
		printf("%c", s[i]);
	}
	puts("");
*/
	if (s[l] == '(' && s[r] == ')' && match[l] == r) {
		return bv[l] = bv[r] = dfs(l + 1, r - 1, cur + 1);
	} else {
		int ret = 0;
		// plus;
		int pos = lower_bound(plus[cur].begin(), plus[cur].end(), l) - plus[cur].begin();
		if (pos < plus[cur].size() && plus[cur][pos] < r) {
			ret = 0;
			vector<int> tmp;
			for (int i = pos; i < plus[cur].size() && plus[cur][i] < r; i++) {
				tmp.push_back(plus[cur][i]);
			}
			assert(tmp.size() > 0);
			//printf("%d %d\n", tmp[0], tmp.back());
			add(ret, dfs(l, tmp[0] - 1, cur));
			for (int i = 0; i + 1 < tmp.size(); i++) {
				add(ret, f[tmp[i]][0] = dfs(tmp[i] + 1, tmp[i + 1] - 1, cur));
				go[tmp[i]][0] = tmp[i + 1];
			}
			//printf("%d %d %d\n", l, r, tmp.back());
			add(ret, dfs(tmp.back() + 1, r, cur));
			return ret;
		}
		pos = lower_bound(times[cur].begin(), times[cur].end(), l) - times[cur].begin();
		if (pos < times[cur].size() && times[cur][pos] < r) {
			ret = 1;
			vector<int> tmp;
			for (int i = pos; i < times[cur].size() && times[cur][i] < r; i++) {
				tmp.push_back(times[cur][i]);
			}
			assert(tmp.size() > 0);
			mul(ret, dfs(l, tmp[0] - 1, cur));
			for (int i = 0; i + 1 < tmp.size(); i++) {
				mul(ret, g[tmp[i]][0] = dfs(tmp[i] + 1, tmp[i + 1] - 1, cur));
				go[tmp[i]][0] = tmp[i + 1];
			}
			mul(ret, dfs(tmp.back() + 1, r, cur));
			return ret;
		}

		for (int i = l; i <= r; i++) {
			assert(is_digit(s[i]));
			prefix[i] = (prefix[i - 1] * 10LL + s[i] - '0') % MOD;
			nxt_opt[i] = r + 1;
		}
		for (int i = r, base = 1; i >= l; i--) {
			suffix[i] = (suffix[i + 1] + 1LL * (s[i] - '0') * base) % MOD;
			base = base * 10LL % MOD;
		}
		return prefix[r];
	}
}

void prepare() {
	vector<int> lb;
	for (int i = 1, cur_dep = 0; i <= n; i++) {
		if (s[i] == '(') {
			cur_dep++;
			lb.push_back(i);
		} else if (s[i] == ')') {
			cur_dep--;
			match[i] = lb.back();
			match[lb.back()] = i;
			lb.pop_back();
		} else if (s[i] == '+') {
			plus[cur_dep].push_back(i);
		} else if (s[i] == '*') {
			times[cur_dep].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		go[i][0] = 0;
	}
	dfs(1, n, 0);
}

int get_number(int l, int r) {
	return 1LL * (suffix[l] + MOD - suffix[r + 1]) % MOD * power(power(10, nxt_opt[l] - r - 1), MOD - 2) % MOD;
}

int get_first_number(int &l, int r) {
	int ret;
	if (s[l] == '(') {
		ret = bv[l];
		l = match[l] + 1;
	} else {
		assert(is_digit(s[l]));
		if (nxt_opt[l] == nxt_opt[r]) {
			ret = get_number(l, r);
			l = r + 1;
			return ret;
		}
		ret = suffix[l];
		l = nxt_opt[l];
	}
	return ret;
}

int solve(int l, int r) {
	if (l > r || l < 1 || r > n) return -1;
	if (s[l] == '+' || s[r] == '+' || s[l] == '*' || s[r] == '*' || s[l] == ')') {
		return -1;
	}
	int first = get_first_number(l, r);
	if (l == r + 1) return first;
	if (l > r || s[l] == ')') return -1;
	assert(s[l] != '(');
	if (s[l] == '*') {
		for (int i = LOG - 1; i >= 0; i--) {
			if (go[l][i] != 0 && go[l][i] <= r) {
				mul(first, g[l][i]);
				l = go[l][i];
			}
		}
		l++;
		//printf("first = %d l = %d\n", first, l);
		int second = get_first_number(l, r);
		mul(first, second);
		if (l == r + 1) {
			return first;
		}
	}
	if (l > r || s[l] == ')') return -1;
	assert(s[l] == '+');
	for (int i = LOG - 1; i >= 0; i--) {
		if (go[l][i] != 0 && go[l][i] <= r) {
			add(first, f[l][i]);
			l = go[l][i];
		}
	}
	l++;
	int second = get_first_number(l, r);
	if (l == r + 1) return (first + second) % MOD;
	if (l > r || s[l] == ')') return -1;
	assert(s[l] == '*');
	for (int i = LOG - 1; i >= 0; i--) {
		if (go[l][i] != 0 && go[l][i] <= r) {
			mul(second, g[l][i]);
			l = go[l][i];
		}
	}
	l++;
	int third = get_first_number(l, r);
	mul(second, third);
	if (l == r + 1) return (first + second) % MOD;
	return -1;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	prepare();
	for (int i = 0; i + 1 < LOG; i++) {
		for (int j = 1; j <= n; j++) {
			go[j][i + 1] = go[go[j][i]][i];
			f[j][i + 1] = (f[j][i] + f[go[j][i]][i]) % MOD;
			g[j][i + 1] = 1LL * g[j][i] * g[go[j][i]][i] % MOD;
		}
	}
	/*
	for (int i = 1; i <= n; i++) {
		printf("%d\n", go[i][0]);
	}*/
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", solve(l, r));
	}
	return 0;
}