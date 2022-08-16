/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 20;

int a[N], ctr[N];
ll fact[N];
ll g_ans;

void solve(int i);

int main() {
	string s; cin >> s;
	for (auto &c : s) {
		++ctr[c - '0'];
	}
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = i * fact[i - 1];
	}
	solve(0);
	cout << g_ans;
}

void solve(int i) {
	// cout << i << endl;
	if (i < 10) {
		if (ctr[i] == 0) {
			solve(i + 1);
		} else {
			for (int j = 1; j <= ctr[i]; ++j) {
				a[i] = j;
				solve(i + 1);
			}
		}
	} else {
		ll ans = 1, sum = 0, den = 1;
		for (int i = 1; i < 10; ++i) {
			den *= fact[a[i]];
			sum += a[i];
		}
		if (sum == 0) {
			return;
		}
		ans = fact[sum] / den;
		if (a[0]) {
			ll temp = fact[a[0] + sum - 1] / (fact[sum - 1] * fact[a[0]]);
			ans *= temp;
		}
		g_ans += ans;
	}
}