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
	string s;
	cin >> s;
	int phase = 1, c1 = 0, c2 = 0, c3 = 0;
	for (auto &i : s) {
		if (i == 'a') {
			if (phase != 1) {
				phase = -1;
				break;
			} else {
				++c1;
			}
		} else if (i == 'b') {
			if (phase == 1) {
				phase = 2;
			} else if (phase != 2) {
				phase = -1;
				break;
			}
			++c2;
		} else {
			if (phase == 2) {
				phase = 3;
			} else if (phase != 3) {
				phase = -1;
				break;
			}
			++c3;
		}
	}
	if (phase == 3 and (c1 == c3 or c2 == c3) and c1 and c2) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}