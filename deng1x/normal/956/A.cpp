#include <bits/stdc++.h>

#define MAXN (60)

int n, m;
char str[MAXN];
std::bitset<MAXN> bit[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) {
		scanf("%s", str);
		bit[i].reset();
		for (int j = 0; j < m; ++ j) {
			if (str[j] == '#') {
				bit[i].set(j);
			}
		}
	}
	std::vector<std::bitset<MAXN> > vec;
	for (int i = 0; i < n; ++ i) {
		bool flag = true;
		for (int j = 0; j < vec.size(); ++ j) {
			if (bit[i] == vec[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			vec.push_back(bit[i]);
		}
	}
	for (int i = 0; i < vec.size(); ++ i) {
		for (int j = i + 1; j < vec.size(); ++ j) {
			if ((vec[i] & vec[j]).count()) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}