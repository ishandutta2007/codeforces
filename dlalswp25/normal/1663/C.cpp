#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	int ans = 0;
	for(int i = 1; i <= N; i++) ans += A[i];
	printf("%d\n", ans);
	return 0;
}