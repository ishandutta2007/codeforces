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

const int N = 1e2 + 10;

string s[N];

int main() {
	string pw; int n;
	cin >> pw >> n;
	bool done = false;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		if (s[i] == pw) {
			done = true;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i][1] == pw[0] and s[j][0] == pw[1]) {
				done = true;
				break;
			}
		}
	}

	if (done) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}