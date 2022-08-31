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

const int N = 100 + 10;

char s[4][N];

int main() {
	int n, k;
	cin >> n >> k;
	cout << "YES\n";
	for (int i = 1; i <= 2; ++i) {
		for (int j = 1; j < n / 2; ++j) {
			if (k >= 2) {
				s[i][j] = s[i][n - j - 1] = '#';
				k -= 2;
			} else {
				break;
			}
		}
	}
	for (int i = 1; i <= 2; ++i) {
		if (k) {
			s[i][n / 2] = '#';
			--k;
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j]) {
				cout << s[i][j];
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
}