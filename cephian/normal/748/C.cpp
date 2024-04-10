#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n;
string s;
set<char> past;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n;
	cin >> s;
	past.insert('U');
	past.insert('D');
	int ans = 0;
	for(int i = 0; i < s.size(); ++i) {
		past.insert(s[i]);
		if((past.count('U') && past.count('D')) || (past.count('L') && past.count('R'))) {
			++ans;
			past.clear();
			past.insert(s[i]);
		}
	}
	cout << ans << "\n";

	return 0;
}