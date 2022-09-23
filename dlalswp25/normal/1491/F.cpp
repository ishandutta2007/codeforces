#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> L, R;

int query() {
	printf("? %d %d\n", L.size(), R.size());
	for(int i : L) printf("%d ", i); puts("");
	for(int i : R) printf("%d ", i); puts("");
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {

		scanf("%d", &N);
		int last = 0;
		vector<int> ans;
		for(int i = 2; i <= N; i++) {
			L.clear(); R.clear();
			if(!last) {
				for(int j = 1; j < i; j++) L.push_back(j);
				R.push_back(i);
				int x = query();
				if(x) {
					int l = 1, r = i - 1;
					while(l <= r) {
						int m = l + r >> 1;
						L.clear();
						for(int k = 1; k <= m; k++) L.push_back(k);
						int y = query();
						if(y) r = m - 1;
						else l = m + 1;
					}
					//l
					for(int k = 1; k < i; k++) {
						if(k != l) ans.push_back(k);
					}
					last = i;
				}
			}
			else {
				L.push_back(last);
				R.push_back(i);
				int x = query();
				if(x) last = i;
				else ans.push_back(i);
			}
		}
		printf("! %d ", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
		fflush(stdout);

	}
	return 0;
}