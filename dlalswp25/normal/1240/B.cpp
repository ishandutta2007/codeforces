#include <bits/stdc++.h>

using namespace std;

int L[303030];
int R[303030];
int A[303030];
int N, T;
vector<int> v;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) L[i] = R[i] = 0;
		v.clear();

		int c = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(!L[A[i]]) { L[A[i]] = i; v.push_back(A[i]); }
			R[A[i]] = i;
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int ans = 0;

		int cnt = 1;
		for(int i = 1; i < v.size(); i++) {
			ans = max(ans, cnt);
			if(R[v[i - 1]] < L[v[i]]) cnt++;
			else cnt = 1;
		}
		ans = max(ans, cnt);
		printf("%d\n", (int)v.size() - ans);
	}
	return 0;
}