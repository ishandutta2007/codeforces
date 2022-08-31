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
 
const int N = 1e5 + 10; 
 
int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int r, c;
		cin >> r >> c;
		vector<string> a(r);
		for (auto& i : a) {
			cin >> i;
		}
		vector<int> cnt_r(r, 0), cnt_c(c, 0);
		bool corner = false, any = false, all = true;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (a[i][j] == 'A') {
					any = true;
					corner |= (i == 0 or i == r - 1) and (j == 0 or j == c - 1);
					++cnt_r[i];
					++cnt_c[j];
				} else {
					all = false;
				}
			}
		}
		if (all) {
			cout << 0 << '\n';
		} else if (max(cnt_r[0], cnt_r[r - 1]) == c or max(cnt_c[0], cnt_c[c - 1]) == r) {
			cout << 1 << '\n';
		} else if (corner or *max_element(cnt_r.begin(), cnt_r.end()) == c or *max_element(cnt_c.begin(), cnt_c.end()) == r) {
			cout << 2 << '\n';
		} else if (cnt_r[0] or cnt_r[r - 1] or cnt_c[0] or cnt_c[c - 1]) {
			cout << 3 << '\n';
		} else if (any) {
			cout << 4 << '\n';
		} else {
			cout << "MORTAL\n";
		}
	}	
}