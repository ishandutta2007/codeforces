/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#define ll long long
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const int mx = 3e5;
int n, k, a[mx];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (k == 0) {
		if (a[0] == 1) {
			cout << -1 << endl;
		}
		else {
			cout << 1 << endl;
		}
		return 0;
	}
	if (k == n) {
		cout << INF << endl;
		return 0;
	}
	if (a[k - 1] == a[k]) {
		cout << -1 << endl;
		return 0;
	}
	else {
		cout << a[k - 1] << endl;
	}
}