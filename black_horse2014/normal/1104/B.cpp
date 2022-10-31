#include <bits/stdc++.h>
using namespace std;

string s;
vector<char> O;

int main() {
	cin >> s;
	int cur = 0, cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		cur++;
		if (i + 1 == s.length() || s[i] != s[i + 1]) {
			if (cur & 1) {
				cnt += cur / 2;
				cur = 0;
				O.push_back(s[i]);
			}
			else {
				cnt += cur / 2;
				cur = 0;
				if (i + 1 < s.length() && !O.empty() && s[i + 1] == O.back()) {
					cur = 1;
					O.pop_back();
				}
			}
		}
	}
	printf("%s\n", cnt & 1 ? "Yes" : "No");
	return 0;
}