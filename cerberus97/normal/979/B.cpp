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

const int N = 1e5 + 10, alpha = 200;

int get_score(string s, int n);

int main() {
	vector<pair<int, string>> names = {{0, "Kuro"}, {0, "Shiro"}, {0, "Katie"}};
	int n; cin >> n;
	for (int i = 0; i < 3; ++i) {
		string s; cin >> s;
		names[i].first = get_score(s, n);
	}
	sort(names.begin(), names.end());
	if (names[2].first == names[1].first) {
		cout << "Draw";
	} else {
		cout << names[2].second;
	}
}

int get_score(string s, int n) {
	int len = s.length();
	int ctr[alpha] = {0};
	for (auto &i : s) {
		++ctr[i];
	}
	int best = 0;
	for (int i = 0; i < alpha; ++i) {
		if (n == 1 and ctr[i] == len) {
			best = max(best, len - 1);
		} else {
			best = max(best, min(len, ctr[i] + n));
		}
	}
	return best;
}