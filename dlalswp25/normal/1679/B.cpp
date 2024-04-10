#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q, X;
int A[202020];
int T[202020];

int main() {
	scanf("%d%d", &N, &Q);
	ll s = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		s += A[i];
	}
	int t2 = -1;
	for(int q = 1; q <= Q; q++) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int i, x; scanf("%d%d", &i, &x);
			if(T[i] > t2) s += (x - A[i]);
			else s += (x - X);
			A[i] = x; T[i] = q;
		}
		else {
			scanf("%d", &X);
			t2 = q;
			s = (ll)X * N;
		}
		printf("%lld\n", s);
	}
	return 0;
}