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
	string s; cin >> s;
	int n = 0, m = 0;
	for (auto &i : s) {
		if (i == 'o') {
			++n;
		} else {
			++m;
		}
	}
	if (!n or m % n == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}