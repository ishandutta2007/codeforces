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

const int N = 2e5 + 10;

vector<int> a[N];
stack<int> ones, zeroes;

int main() {
	fast_cin();
	string s;
	cin >> s;
	int k = 0;
	for (auto &i : s) {
		if (i == '1') {
			--k;
		} else {
			++k;
		}
	}
	if (k <= 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < k; ++i) {
		ones.push(i);
	}
	int ctr = 1;
	for (auto &i : s) {
		if (i == '0') {
			if (ones.empty()) {
				cout << -1;
				return 0;
			}
			int j = ones.top();
			ones.pop();
			a[j].pb(ctr);
			zeroes.push(j);
		} else {
			if (zeroes.empty()) {
				cout << -1;
				return 0;
			}
			int j = zeroes.top();
			zeroes.pop();
			a[j].pb(ctr);
			ones.push(j);
		}
		++ctr;
	}
	if (!ones.empty()) {
		cout << -1;
	} else {
		cout << k << endl;
		for (int i = 0; i < k; ++i) {
			cout << a[i].size() << ' ';
			for (auto &j : a[i]) {
				cout << j << ' ';
			}
			cout << endl;
		}
	}
}