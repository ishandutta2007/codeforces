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

const int N = 1e5 + 10, kT = 43200;

int main() {
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	h %= 12;
	t1 %= 12;
	t2 %= 12;
	h = (h * 3600 + m * 60 + s);
	m = (m * 720 + 12 * s);
	s = (s * 720);
	t1 *= 3600;
	t2 *= 3600;
	// cout << h << ' ' << m << ' ' << s << ' ' << t1 << ' ' << t2 << endl;
	while (t1 != t2) {
		int temp = (t1 + 1) % kT;
		if (temp == h or temp == m or temp == s) {
			break;
		}
		t1 = temp;
	}

	while (t1 != t2) {
		int temp = (t1 + kT - 1) % kT;
		if (temp == h or temp == m or temp == s) {
			break;
		}
		t1 = temp;
	}

	if (t1 == t2) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}