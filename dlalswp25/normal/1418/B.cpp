#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];
int B[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		vector<int> v;
		for(int i = 1; i <= N; i++) if(!B[i]) v.push_back(A[i]);
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int p = 0;
		for(int i = 1; i <= N; i++) if(!B[i]) A[i] = v[p++];
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}