/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int kN = 18, kK = 6;

int a[kN];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int temp = 0;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			temp |= (x << j);
		}
		a[temp]++;
	}

	int types = (1 << k);
	int subsets = (1 << types);
	bool ans = false;
	for (int i = 1; i < subsets; ++i) {
		int ctr[kK] = {0}, total = 0;
		bool temp = true;
		for (int j = 0; j < types; ++j) {
			if (i & (1 << j)) {
				if (!a[j]) {
					temp = false;
					break;
				}
				++total;
				for (int l = 0; l < k; ++l) {
					if (j & (1 << l)) {
						ctr[l]++;
					}
				}
			}
		}
		if (temp) {
			ans = true;
			for (int l = 0; l < k; ++l) {
				if (2 * ctr[l] > total) {
					ans = false;
					break;
				}
			}
			if (ans) {
				break;
			}
		}
	}

	if (ans) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}