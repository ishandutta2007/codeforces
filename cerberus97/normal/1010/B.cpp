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

const int N = 60 + 10;

bool correct[N];

bool query(int x);

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		correct[i] = !query(1);
	}
	int id = 0;
	int lo = 2, hi = m;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		bool less = query(mid) xor !correct[id];
		id = (id + 1) % n;
		if (less) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	query(lo);
}

bool query(int x) {
	cout << x << endl;
	int res; cin >> res;
	if (!res) {
		exit(0);
	} else {
		return (res == -1);
	}
}