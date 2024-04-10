#include <bits/stdc++.h>

using namespace std;

char A[101010];
char B[101010];
int N;
vector<int> ans;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans.clear();
		scanf("%d", &N);
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		int l = 1, r = N;
		for(int i = N; i >= 1; i--) {
			int x = N - i;
			if(x % 2 == 0) {
				if(A[l] == B[i]) ans.push_back(1);
				ans.push_back(i);
				l++;
			}
			else {
				if(A[r] != B[i]) ans.push_back(1);
				ans.push_back(i);
				r--;
			}
		}

		printf("%d ", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}