#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> Map;
int Val[200000];


int main() {

	int n, val;
	scanf("%d", &n);
	Map[{1, (int)1e9}] = 0;

	for(int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		Val[i] = val;
		auto it = Map.lower_bound({val, 1e9 + 1});
		--it;

		if(i > 1)
		printf("%d ", Val[it->second]);
		
		Map[{it->first.first, val - 1}] = i;
		Map[{val + 1, it->first.second}] = i;
		Map.erase(it);
	}
}