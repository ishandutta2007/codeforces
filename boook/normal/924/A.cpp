#include <bits/stdc++.h>
using namespace std;

char a[110][110];
int bad1[110], bad2[110];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);

	for (int i = 1; i <= n; i++) {
		vector<int> box;
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '#') {
				if (bad1[j]) {
					puts("No");
					return 0;
				}
				box.push_back(j);
				bad1[j] = 1;
			}
		}

		if (box.size() == 0) continue;
		vector<int> box2;
		for (int j = 0; j < box.size(); j++) {
			int x = box[j];
			for (int k = 1; k <= n; k++) {
				if (a[k][x] == '#') {
					box2.push_back(k);
				}
			}
		}

		sort(box2.begin(), box2.end());
		box2.resize(unique(box2.begin(), box2.end()) - box2.begin());
		for (int j = 0; j < box2.size(); j++) {
			if (bad2[box2[j]]) {
				puts("No");
				return 0;
			}
			bad2[box2[j]] = 1;
		}

		for (int j = 0; j < box2.size(); j++) {
			for (int k = 0; k < box.size(); k++) {
				int x = box2[j];
				int y = box[k];
				if (a[x][y] != '#') {
					puts("No");
					return 0;
				} else {
					a[x][y] = '.';
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != '.') {
				puts("No");
				return 0;
			}
		}
	}

	puts("Yes");
	return 0;

}