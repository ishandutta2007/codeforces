#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		ll a = 0, b = 0;
		bool fg = false;
		for(int i = N; i >= 1; i--) {
			if(!fg) {
				if(~A[i] & 1) a += A[i];
			}
			else {
				if(A[i] & 1) b += A[i];
			}
			fg = !fg;
		}
		if(a > b) puts("Alice");
		else if(a < b) puts("Bob");
		else puts("Tie");
	}
	return 0;
}