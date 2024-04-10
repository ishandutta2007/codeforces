#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { if(a + b == 0) return 0; while(b) { a %= b; swap(a, b); } return a; }

int N, M;
ll A[202020];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	sort(A + 1, A + N + 1);
	ll g = 0;
	for(int i = 2; i <= N; i++) g = gcd(g, (A[i] - A[i - 1]));
	for(int i = 1; i <= M; i++) {
		ll b; scanf("%lld", &b);
		printf("%lld ", gcd(b + A[1], g));
	}
	puts("");
	return 0;
}