#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string s;
vector<int> answers;

int main() {
	cin >> s;
	int n = s.length(), cnt = 0, last = -1;
	for(int i = 0; i < n; i++) {
		if (s[i] == '(') {
			cnt++;
		} else if (s[i] == '#' || s[i] == ')') {
			if (--cnt < 0) {
				puts("-1");
				return 0;
			}
			if (s[i] == '#') {
				answers.push_back(1);
				last = i;
			}
		}
	}
	if (cnt > 0) {
		if (answers.size() == 0) {
			puts("-1");
			return 0;
		} else {
			answers.back() += cnt;
		}
	}
	int lcnt = cnt;
	cnt = 0;
	for(int i = 0; i < n; i++) {
		if (s[i] == '(') {
			cnt++;
		} else if (s[i] == '#') {
			cnt--;
			if (i == last) {
				cnt -= lcnt;
			}
		} else {
			cnt--;
		}
		if (cnt < 0) {
			puts("-1");
			return 0;
		}
	}
	for(int i = 0; i < (int)answers.size(); i++) {
		printf("%d\n", answers[i]);
	}
	return 0;
}