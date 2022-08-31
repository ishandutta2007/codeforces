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
#include <cassert>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	int n;
	cin >> n;
	vector<int> a = {1}, b = {};
	while (n--) {
		auto tmp = a;
		bool ok = true;
		tmp.insert(tmp.begin(), 0);
		int d = b.size();
		for (int i = 0; i < d; ++i) {
			if (tmp[i] + b[i] > 1 or tmp[i] + b[i] < -1) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			for (auto& i : tmp) {
				i = -i;
			}
			ok = true;
			for (int i = 0; i < d; ++i) {
				if (tmp[i] + b[i] > 1 or tmp[i] + b[i] < -1) {
					ok = false;
					break;
				}
			}
		}
		assert(ok);
		for (int i = 0; i < d; ++i) {
			tmp[i] += b[i];
		}
		b = a;
		a = tmp;
	}
	if (a.back() == -1) {
		for (auto& i : a) {
			i = -i;
		}
	}
	if (b.back() == -1) {
		for (auto& i : b) {
			i = -i;
		}
	}
	cout << int(a.size()) - 1 << '\n';
	for (auto& i : a) {
		cout << i << ' ';
	}
	cout << '\n' << int(b.size()) - 1 << '\n';
	for (auto& i : b) {
		cout << i << ' ';
	}
	cout << endl;
}