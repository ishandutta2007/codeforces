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

int main()
{
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	set <string> st;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			st.insert(s.substr(0, i) + t.substr(0, j));
		}
	}

	cout << *st.begin() << endl;
}