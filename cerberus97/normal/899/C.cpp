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

const int N = 6e4 + 10, D = 10;

int main() {
	int n;
	cin >> n;
	ll s1 = 0, s2 = 0;
	vector <int> v1, v2;
	for (int i = n; i >= 1; i -= 2) {
		if (s1 >= s2) {
			s2 += i;
			s1 += i - 1;
			v2.pb(i);
			v1.pb(i - 1);
		} else {
			s2 += i - 1;
			s1 += i;
			v2.pb(i - 1);
			v1.pb(i);
		}
	}

	cout << abs(s1 - s2) << endl;
	if (v1.back() == 0) {
		v1.pop_back();
	}

	cout << v1.size() << ' ';
	for (auto &i : v1) {
		if (i) {
			cout << i << ' ';
		}
	}
}