#include <bits/stdc++.h>

using namespace std;

map<long long, int> Has;
int V[500000], Start[500000], Sol[500000];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", V + i);
		V[i + n] = V[i];
	}

	long long s = 0;
	Has[0] = 0;
	for(int i = 1; i <= 2 * n; ++i) {
		s += V[i];
		auto it = Has.find(s);
		if(it != Has.end()) {
			Sol[i] = Sol[it->second] + 1;
			Start[i] = Start[it->second];
		} else {
			Start[i] = i;
			Sol[i] = 0;
		}
		
		Has[s] = i;
	}

	int ans = 0;

	for(int i = 1; i <= 2 * n; ++i) {
		if(Start[i] == i - n)
			ans = max(ans, Sol[i]);
	}

	cout << n - ans;
	return 0;
}