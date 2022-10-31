#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int x = n, y = 0;
	vector<pair<int, int>> ans;
	while(x >= 0 and y <= m) {
		ans.emplace_back(x, y);
		x--;
		y++;
	}
	printf("%d\n", (int)ans.size());
	for(auto t : ans) printf("%d %d\n", t.first, t.second);
	return 0;
}