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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10, A = 26, D = 10;

string a[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int r, c, k;
		cin >> r >> c >> k;
		int rice = 0;
		for (int i = 0; i < r; ++i) {
			cin >> a[i];
			rice += count(a[i].begin(), a[i].end(), 'R');
		}
		int lo = rice / k, hi = lo + 1;
		int lo_cnt = k - (rice % k);
		string lower(A, 0);
		string upper(A, 0);
		string digits(D, 0);
		iota(lower.begin(), lower.end(), 'a');
		iota(upper.begin(), upper.end(), 'A');
		iota(digits.begin(), digits.end(), '0');
		string all = lower + upper + digits;
		int p = 0, cur = lo;
		for (int i = 0; i < r; ++i) {
			int j_beg = ((i & 1) ? c - 1 : 0);
			int j_end = ((i & 1) ? -1 : c);
			int j_diff = ((i & 1) ? -1 : 1);
			for (int j = j_beg; j != j_end; j += j_diff) {
				if (a[i][j] == 'R') {
					if (cur == 0) {
						++p;
						cur = ((p < lo_cnt) ? lo : hi);
					}
					--cur;
				}
				a[i][j] = all[p];
			}
		}
		for (int i = 0; i < r; ++i) {
			cout << a[i] << '\n';
		}
		// cout << endl;
	}
}