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

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	int stk = 0, open = k / 2;
	string ans = "";
	for (auto &i : s) {
		if (i == '(') {
			if (open) {
				ans += i;
				--open;
				++stk;
			}
		} else if (stk) {
			ans += i;
			--stk;
		}
	}
	cout << ans << endl;
}