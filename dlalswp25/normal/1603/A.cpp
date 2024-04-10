#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		ll L = 2;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i] % L == 0) { ok = false; break; }
			ll g = gcd(L, (i + 2));
			L = L * (i + 2) / g;
			if(L > 1000000000) break;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}