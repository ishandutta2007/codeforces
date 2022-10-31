#include <bits/stdc++.h>
using namespace std;

char s[220000];

vector<int> S[220000];
set<int> T[2];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int m = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			cnt--;
			if (T[0].empty()) {
				puts("-1");
				return 0;
			}
			int j = *T[0].begin();
			T[0].erase(j);
			S[j].push_back(i);
			T[1].insert(j);
		} else {
			cnt++;
			if (!T[1].empty()) {
				int j = *T[1].begin();
				T[1].erase(j);
				S[j].push_back(i);
				T[0].insert(j);
			} else {
				T[0].insert(m);
				S[m++].push_back(i);
			}
		}
	}
	if (cnt != m) {
		puts("-1");
		return 0;
	}
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		printf("%d", S[i].size());
		for (int k : S[i]) printf(" %d", k);
		puts("");
	}
	return 0;
}