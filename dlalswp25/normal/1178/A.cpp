#include <bits/stdc++.h>

using namespace std;

int A[101];
int N;
int ts = 0;
vector<int> v;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) { scanf("%d", &A[i]); ts += A[i]; }

	int s = A[1];
	v.push_back(1);
	for(int i = 2; i <= N; i++) if(A[i] * 2 <= A[1]) {
		s += A[i];
		v.push_back(i);
	}

	if(s * 2 > ts) {
		printf("%d\n", v.size());
		for(int i : v) printf("%d ", i); puts("");
	}
	else puts("0");
	return 0;
}