#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111;

char s[N], t[N];
bool ok = false;
int n, p;

int dfs(int pos, int flag) {
	if (pos == n + 1) {
		return flag;
	}
	if (flag) {
		for(int i = 0; i < p; i++) {
			char ind = i + 'a';
			if (pos > 1 && ind == t[pos - 1]) {
				continue;
			}
			if (pos > 2 && ind == t[pos - 2]) {
				continue;
			}
			t[pos] = ind;
			if (dfs(pos + 1, flag)) {
				return 1;
			}
		}
	} else {
		for(int i = s[pos] - 'a'; i < p; i++) {
			char ind = i + 'a';
			if (pos > 1 && ind == t[pos - 1]) {
				continue;
			}
			if (pos > 2 && ind == t[pos - 2]) {
				continue;
			}
			t[pos] = ind;
			if (dfs(pos + 1, i > s[pos] - 'a')) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &p);
	scanf("%s", s + 1);
	if (dfs(1, 0)) {
		printf("%s", t + 1);
	} else {
		printf("NO\n");
	}
	return 0;
}