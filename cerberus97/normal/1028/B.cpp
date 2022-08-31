/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	int s1 = 0, s2 = 0;
	string a = "", b = "";
	while (s1 < n or s2 < n) {
		a += '1';
		b += '8';
		++s1; s2 += 9;
	}
	a += '1';
	b += '9';
	cout << a << endl << b << endl;
}