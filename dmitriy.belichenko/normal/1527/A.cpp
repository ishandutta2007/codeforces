#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ld long double
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int x = 1;
		bitset<32> t = n;
		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			if (t[i]) {
				ans = i;
				break;
			}
		}
		cout << max(0, (2 << (ans - 1)) - 1) << "\n";
	}
}