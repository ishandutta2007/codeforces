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

set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

int main() {
	int n; string s;
	cin >> n >> s;
	bool v = false;
	for (auto &i : s) {
		if (vowels.find(i) != vowels.end()) {
			if (!v) {
				cout << i;
				v = true;
			}
		} else {
			cout << i;
			v = false;
		}
	}
}