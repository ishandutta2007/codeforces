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
 
const int N = 2e5 + 10;
 
bool ok[N];
 
int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	string a; cin >> a;
	string b = a;
	for (int i = 0; i < n; ++i) {
		if (i >= k) {
			b[i] = b[i - k];
		}
	}
	if (b >= a) {
		cout << n << '\n' << b << endl;
	} else {
		for (int p = k - 1; p >= 0; --p) {
			if (b[p] != '9') {
				for (int i = 0; i < n; ++i) {
					if (i % k == p) {
						++b[i];
					} else if (i % k > p) {
						b[i] = '0';
					}
				}
				break;
			}
		}
		cout << n << '\n' << b << endl;
	}
}