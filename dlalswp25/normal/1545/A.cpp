#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
vector<int> X, Y;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		X.clear(); Y.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(i & 1) X.push_back(A[i]);
			else Y.push_back(A[i]);
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		reverse(X.begin(), X.end());
		reverse(Y.begin(), Y.end());
		bool ok = true;

		for(int i = 1; i <= N; i++) {
			if(i & 1) {
				if(Y.size() && X.back() > Y.back()) { ok = false; break; }
				X.pop_back();
			}
			else {
				if(X.size() && X.back() < Y.back()) { ok = false; break; }
				Y.pop_back();
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}