#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int N = 1e5 + 7;

string pattern = "Bulbasaur";
const int L = 9;
int cnt_letter[200] = {0};

int main() {
	static char buf[N];
	scanf("%s", buf);
	for (int i = 0; buf[i]; i++) {
		cnt_letter[buf[i]]++;
	}
	int ans = 0;
	while (1) {
		bool flag = true;
		for (int j = 0; j < L; j++) {
			if (--cnt_letter[pattern[j]] < 0) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}