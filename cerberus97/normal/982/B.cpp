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

pii w[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i].first;
		w[i].second = i;
	}
	sort(w + 1, w + 1 + n);
	int p = 1;
	string s; 
	cin >> s;
	stack<int> stk;
	for (int i = 0; i < 2 * n; ++i) {
		if (s[i] == '0') {
			stk.push(w[p].second);
			cout << stk.top() << ' ';
			++p;
		} else {
			cout << stk.top() << ' ';
			stk.pop();
		}
	}
}