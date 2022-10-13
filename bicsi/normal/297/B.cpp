#include <bits/stdc++.h>

using namespace std;

map<int, int> Count;

int main() {
	int n, m, k;

	int a;

	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		Count[a] += 1;
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &a);
		Count[a] -= 1;
	}

	int total = 0;
	for(auto it = Count.rbegin(); it != Count.rend(); ++it) {
		total += it->second;
		if(total > 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}