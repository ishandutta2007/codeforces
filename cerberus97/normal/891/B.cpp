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

const int N = 25;

pii a[N];
int p[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + 1 + n);
	a[n + 1] = a[1];
	for (int i = 1; i <= n; ++i) {
		p[a[i].second] = a[i + 1].first;
	}

	for (int i = 1; i <= n; ++i) {
		cout << p[i] << ' ';
	}
}