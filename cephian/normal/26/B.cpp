#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	int height = 0;
	int len = 0;
	for(char c : s) {
		if(c == ')') {
			if(height != 0) {
				--height;
				++len;
			}
		} else {
			++height;
			++len;
		}
	}
	len -= height;
	cout << len << "\n";
}