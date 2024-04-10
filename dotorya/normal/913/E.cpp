#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 16;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <pair<string, int>> Vl[100];
string ans[256][2];
int mycheck(string s) {
	int c = 0;
	for (auto it : s) {
		if (it == '(') c++;
		if (it == ')') c--;
		if (c == 0 && it == '|') return 1;
	}
	return 0;
}

class datax {
public:
	string s;
	int n1, n2;
	datax() {
		*this = datax(string(""), 0, 0);
	}
	datax(string s, int n1, int n2) : s(s), n1(n1), n2(n2) {}
	bool operator < (const datax &l) const {
		if (s.size() != l.s.size()) return s.size() > l.s.size();
		return s > l.s;
	}
};
priority_queue <datax> Hx;
void hpush(string s, int n1, int n2) {
	if (ans[n1][n2].size() < s.size()) return;
	else if (ans[n1][n2].size() == s.size() && ans[n1][n2] <= s) return;
	ans[n1][n2] = s;
	Hx.emplace(s, n1, n2);
}
int main() {
	for (int i = 0; i < 256; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 100; k++) ans[i][j] += 'z' + 1;
	
	Vl[1].emplace_back(string("x"), (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4));
	Vl[1].emplace_back(string("y"), (1 << 7) | (1 << 6) | (1 << 3) | (1 << 2));
	Vl[1].emplace_back(string("z"), (1 << 7) | (1 << 5) | (1 << 3) | (1 << 1));
	for (int i = 0; i < 3; i++) {
		auto it = Vl[1][i];
		Vl[1].emplace_back(string("!") + it.first, it.second ^ 255);
	}
	for (auto it : Vl[1]) hpush(it.first, it.second, 0);
	while (!Hx.empty()) {
		datax u = Hx.top();
		Hx.pop();
		if (ans[u.n1][u.n2] != u.s) continue;

		hpush(string("!(") + u.s + string(")"), u.n1 ^ 255, 0);
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 2; j++) {
				if (ans[i][j][0] == 'z' + 1) continue;
				hpush(u.s + "|" + ans[i][j], u.n1 | i, 1);
				hpush(ans[i][j] + "|" + u.s, i | u.n1, 1);
			}
		}

		string s = u.s;
		if (u.n2) s = string("(") + s + string(")");
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 2; j++) {
				if (ans[i][j][0] == 'z' + 1) continue;
				string s2 = ans[i][j];
				if (j) s2 = string("(") + s2 + string(")");

				hpush(s + "&" + s2, u.n1 & i, 0);
				hpush(s2 + "&" + s, i & u.n1, 0);
			}
		}
	}

	for (int i = 0; i < 256; i++) {
		datax u1 = datax(ans[i][0], 0, 0);
		datax u2 = datax(ans[i][1], 0, 0);
		if (u1 < u2) ans[i][0] = ans[i][1];
	}

	int N;
	scanf("%d", &N);
	while (N--) {
		char u[10];
		scanf("%s", u);

		int v = 0;
		for (int i = 0; i < 8; i++) v += (u[i] - '0') << i;
		printf("%s\n", ans[v][0].c_str());
	}
	return 0;
}