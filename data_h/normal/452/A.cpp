#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

string s[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
	string ss;
	int n;
	cin >> n;
	cin >> ss;
	for(int i = 0; i < 8; i++) {
		if (ss.length() != s[i].length()) {
			continue;
		}
		bool flag = true;
		for(int j = 0; j < (int)s[i].length(); j++) {
			if (ss[j] != '.' && s[i][j] != ss[j]) {
				flag = false;
			}
		}
		if (flag) {
			cout << s[i] << endl;
			break;
		}
	}
	return 0;
}