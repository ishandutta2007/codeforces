#include <bits/stdc++.h>

using namespace std;

int N;
int deg[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) deg[i] = 0;
		for(int i = 2; i <= N; i++) {
			int p; scanf("%d", &p);
			deg[p]++;
		}
		vector<int> v;
		for(int i = 1; i <= N; i++) if(deg[i]) v.push_back(deg[i]);
		v.push_back(1);
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int l = 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			int extra = 0;
			for(int i = 0; i < v.size(); i++) {
				extra += max(0, i + v[i] - m);
			}
			if(v.size() + extra > m) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}