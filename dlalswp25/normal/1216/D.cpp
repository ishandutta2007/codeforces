#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int A[202020];
int N;

ll y;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);
	
	int g = A[2] - A[1];
	for(int i = 2; i < N; i++) g = gcd(g, A[i + 1] - A[i]);

	for(int i = 1; i < N; i++) y += (A[N] - A[i]) / g;
	printf("%lld %d\n", y, g);

	return 0;
}