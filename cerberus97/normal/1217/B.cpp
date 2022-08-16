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
	int t; cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int finish = 0, damage = 0;
		for (int i = 0; i < n; ++i) {
			int d, h;
			cin >> d >> h;
			finish = max(finish, d);
			damage = max(damage, d - h);
		}
		if (x <= finish) {
			cout << 1 << '\n';
		} else if (damage == 0) {
			cout << -1 << '\n';
		} else {
			cout << (x - finish + damage - 1) / damage + 1 << '\n';
		}
	}	
}