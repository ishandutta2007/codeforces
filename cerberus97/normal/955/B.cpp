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

const int N = 1e5 + 10;

int main() {
	string s;
	cin >> s;
	map<char, int> mp;
	for (auto &i : s) {
		++mp[i];
	}
	if (mp.size() <= 1 or mp.size() >= 5) {
		cout << "No";
	} else if (mp.size() == 3 and s.length() <= 3) {
		cout << "No";
	} else if (mp.size() == 2 and (mp.begin()->second == 1 or mp.rbegin()->second == 1)) {
		cout << "No";
	} else {
		cout << "Yes";
	}
}