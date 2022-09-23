#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[303030];
int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	int t = 0;
	ll sum = 0;
	for(int i = 1; i <= N; i++) {
		if(A[i] & 1) {
			if(i & 1) t++;
			else t--;
		}
		sum += A[i];
	}	

	printf("%lld\n", (sum - abs(t)) / 2);

	return 0;
}