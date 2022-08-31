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

bool ravioli_sort(vector<int> a);

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (ravioli_sort(a)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}

bool ravioli_sort(vector<int> a) {
	int n = a.size();
	if (n == 1) {
		return true;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (abs(a[i] - a[i + 1]) > 1) {
			return false;
		}
	}
	int pos = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[pos]) {
			pos = i;
		}
	}
	a.erase(a.begin() + pos);
	return ravioli_sort(a);
}