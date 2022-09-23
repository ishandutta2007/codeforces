#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
vector<int> v[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		v[A[i]].push_back(i);
	}
	for(int i = 0; i <= N; i++) v[i].push_back(N + 1);
	int x = 0, y = 0;
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(A[i] == x || A[i] == y) continue;
		auto it = lower_bound(v[x].begin(), v[x].end(), i);
		int ix = *it;
		it = lower_bound(v[y].begin(), v[y].end(), i);
		int iy = *it;
		if(ix < iy) {
			ans++; y = A[i]; continue;
		}
		else {
			ans++; x = A[i]; continue;
		}
	}
	printf("%d\n", ans);
	return 0;
}