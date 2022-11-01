#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 7;

int n, m;
char str[N];

int main() {
	scanf("%d", &m);
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (char c = 'a'; c <= 'z'; c++) {
		bool flag = true;
		int p = 0;
		for (int i = 1; i <= n; i++) {
			if (str[i] <= c) {
				p = i;
			} else if (i - p == m) {
				flag = false;
				break;
			}
		}
		vector<char> result;
		if (flag) {
			int ptr = 0;
			p = 0;
			for (int i = 1; i <= n; i++) {
				if (str[i] < c) {
					result.push_back(str[p = i]);
					continue;
				}
				if (str[i] == c) {
					ptr = i;
				}
				if (i - p == m) {
					result.push_back(str[p = ptr]);
				}
			}
			sort(result.begin(), result.end());
			for (auto cc : result) {
				printf("%c", cc);
			}
			puts("");
			return 0;
		}
	}
	return 0;
}