#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[1009], d[1009]; vector<pair<int, int>>L;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	
	int s = a[0] + 1; vector<int>vec; for (int i = 0; i < n; i++) vec.push_back(a[i]);
	for (int i = 1; i <= s; i++) {
		for (int j = i + 1; j <= s; j++) { L.push_back(make_pair(i, j)); d[i]++; d[j]++; }
		
		for (int j = 0; j < vec.size(); j++) vec[j]--;
		if (vec[vec.size() - 1] == 0) {
			vector<int>vec2;
			for (int j = 1; j < (int)vec.size() - 1; j++) vec2.push_back(vec[j]);
			if (vec2.size() >= 1) s = i + vec2[0] + 1;
			else break;
			vec = vec2;
		}
	}

	printf("%d\n", L.size());
	for (int i = 0; i < L.size(); i++) printf("%d %d\n", L[i].first, L[i].second);
	return 0;
}