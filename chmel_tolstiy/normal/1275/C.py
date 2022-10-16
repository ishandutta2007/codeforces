#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	string s; cin >> s;
	sort(s.begin(), s.end());
	cout << s << endl;
	return true;
}

int main() {
	int t; cin >> t;
	while (solve())
		;
	return 0;
}