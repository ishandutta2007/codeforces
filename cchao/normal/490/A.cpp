#include <bits/stdc++.h>
using namespace std;

vector<int> a[3];
int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int t; scanf("%d", &t);
		a[t-1].push_back(i);
	}
	int tmp = min(a[0].size(), min(a[1].size(), a[2].size()));
	cout << tmp << endl;
	for(int i = 0; i < tmp; ++i) {
		printf("%d %d %d\n", a[0][i], a[1][i], a[2][i]);
	}
	return 0;
}