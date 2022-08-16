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

pii b[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(b + 1, b + n + 1);
	int p = 1;
	for (int i = 1; i <= n; ++i) {
		if (p < i and b[p].first < b[i].first) {
			++p;
		}
	}
	cout << p - 1 << endl;
}