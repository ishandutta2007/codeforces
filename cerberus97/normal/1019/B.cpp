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

int n;

int query(int p);
void answer(int p);

int main() {
	cin >> n;
	if (n % 4) {
		answer(-1);
	}
	int v1 = query(1), v2 = query(1 + n / 2);
	if (v1 == v2) {
		answer(1);
	}
	int r1 = 2, r2 = n / 2;
	int r3 = n / 2 + 2, r4 = n;
	if (v1 > v2) {
		swap(r1, r3);
		swap(r2, r4);
	}
	while (r1 < r2) {
		int p1 = (r1 + r2) / 2, p2 = (r3 + r4) / 2;
		v1 = query(p1);
		v2 = query(p2);
		if (v1 == v2) {
			answer(p1);
		} else if (v1 < v2) {
			r1 = p1 + 1;
			r3 = p2 + 1;
		} else {
			r2 = p1 - 1;
			r4 = p2 - 1;
		}
	}
	answer(r1);
}

int query(int p) {
	cout << "? " << p << endl;
	int x; cin >> x;
	return x;
}

void answer(int p) {
	cout << "! " << p << endl;
	exit(0);
}