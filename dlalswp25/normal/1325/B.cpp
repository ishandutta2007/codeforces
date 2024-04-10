#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		printf("%d\n", v.size());
		v.clear();
	}
	return 0;
}