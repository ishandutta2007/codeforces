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
		int s, i, e;
		cin >> s >> i >> e;
		cout << max(0, min(e + 1, (s + e - i + 1) / 2)) << endl;
	}
}