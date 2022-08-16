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
 
const int N = (1 << 14);
 
int main() {
	fast_cin();
	cout << "? ";
	for (int i = 0; i < 100; ++i) {
		cout << i << ' ';
	}
	cout << endl;
	int x; cin >> x;
	int ans = (x >> 7) << 7;
	cout << "? ";
	for (int i = 1; i <= 100; ++i) {
		cout << (i << 7) << ' ';
	}
	cout << endl;
	cin >> x;
	ans |= (x & ((1 << 7) - 1));
	cout << "! " << ans << endl;
}