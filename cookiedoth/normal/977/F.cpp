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
const int mx = 3e5;

int n, a[mx], r[mx], dp[mx];
map<int, int> last_pos;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		if (last_pos.find(a[i] + 1) == last_pos.end()) {
			r[i] = -1;
		}
		else {
			r[i] = last_pos[a[i] + 1];
		}
		last_pos[a[i]] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (r[i] == -1) {
			dp[i] = 1;
		}
		else {
			dp[i] = dp[r[i]] + 1;
		}
	}
	int best_pos = 0;
	for (int i = 1; i < n; ++i) {
		if (dp[i] > dp[best_pos]) {
			best_pos = i;
		}
	}
	vector<int> res;
	while (best_pos != -1) {
		res.push_back(best_pos);
		best_pos = r[best_pos];
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] + 1 << " ";
	}
	cout << endl;
}