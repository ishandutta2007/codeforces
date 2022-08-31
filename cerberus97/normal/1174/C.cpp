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

int a[N];
bool prime[N];	

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		prime[i] = true;
	}
	int id = 1;
	for (int i = 2; i <= n; ++i) {
		if (prime[i]) {
			for (int j = i; j <= n; j += i) {
				a[j] = id;
				prime[j] = false;
			}
			++id;
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << a[i] << ' ';
	}
}