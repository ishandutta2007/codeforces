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
 
const int N = 4e3 + 10;
 
int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		if (h < c) {
			swap(h, c);
			swap(p, f);
		}
		int temp = min(b / 2, p);
		b -= temp;
		cout << temp * h + min(((b - temp) / 2), f) * c << '\n';
	}
}