#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[202020];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
	ll mn = 1LL << 60;
	
	ll s = 0;
	for(int i = 1; i < N; i += 2) s += A[i];
	mn = s;

	int p = N - 2;
	for(int i = 1; i < N; i++) {
		p = (p + 2) % N;
		s += A[p];
		s -= A[(p + 1) % N];
		mn = min(mn, s);
	}

	s = 0;
	for(int i = 0; i < N; i++) s += A[i];
	printf("%lld\n", s - mn);

	return 0;
}