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
	int n; string s;
	cin >> n >> s;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == '1' and s[i + 1] == '1') {
			cout << "No";
			return 0;
		}
	}
	for (int i = 1; i < n - 1; ++i) {
		if (s[i - 1] == '0' and s[i] == '0' and s[i + 1] == '0') {
			cout << "No";
			return 0;
		}
	}
	if (n > 1 and s[0] == '0' and s[1] == '0') {
		cout << "No";
	} else if (n > 1 and s[n - 2] == '0' and s[n - 1] == '0') {
		cout << "No";
	} else if (n == 1 and s[0] == '0') {
		cout << "No";
	} else {
		cout << "Yes";
	}
}