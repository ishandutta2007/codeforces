#include <bits/stdc++.h>

using namespace std;

int N;
int ans[105];
int A[105];

int query() {
	printf("? ");
	for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
	scanf("%d", &N);
	int mx = N;
	int r = N;
	while(mx) {
		while(r && ans[r]) r--;
		if(!r) break;
		vector<int> v; v.push_back(r);
		int c = 2;
		while(c <= N) {
			for(int i = 1; i <= N; i++) {
				if(i == r) A[i] = c;
				else if(ans[i]) A[i] = N;
				else A[i] = 1;
			}
			int t = query();
			if(!t) break;
			v.push_back(t);
			c++;
		}

		mx -= (int)v.size();
		c = 1;
		for(int i : v) {
			ans[i] = mx + c;
			c++;
		}
	}

	printf("! "); for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	fflush(stdout);
	return 0;
}