#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > A, B;
priority_queue<int> X;
int sa, sb;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		while(A.size()) A.pop();
		while(B.size()) B.pop();
		while(X.size()) X.pop();

		sa = sb = 0;

		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			A.push(a);
			sa += a;
		}
		for(int i = 1; i <= N; i++) {
			int b; scanf("%d", &b);
			B.push(b);
			sb += b;
		}

		int ans = 0;
		for(; ; ans++) {
			int r = N + ans;

			while(A.size() > r - r / 4) {
				sa -= A.top(); A.pop();
			}
			while(B.size() > r - r / 4) {
				sb -= B.top();
				X.push(B.top());
				B.pop();
			}
			while(B.size() < r - r / 4) {
				sb += X.top();
				B.push(X.top());
				X.pop();
			}

			if(sa >= sb) break;

			sa += 100; A.push(100);
			X.push(0);
		}
		printf("%d\n", ans);
	}
	return 0;
}