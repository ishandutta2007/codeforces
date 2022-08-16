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

const int N = 1e5 + 10;

int a[N], ch[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int s, f;
	cin >> s >> f;
	int ans = 0, ans_p = 1, ctr = 0;
	for (int i = 1; i <= n; ++i) {
		int ss = (s - i + 1);
		int ff = (f - i + 1);
		if (ss < 1) {
			ss += n;
		}
		if (ff < 1) {
			ff += n;
		}
		ch[ss] += a[i];
		ch[ff] -= a[i];
		if (ff < ss) {
			ctr += a[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		ctr += ch[i];
		if (ctr > ans) {
			ans = ctr;
			ans_p = i;
		}
	}
	cout << ans_p << endl;
}