#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int zero = 0, one = 0;
		for(int i = 1; i <= N; i++) {
			if(!A[i]) zero++;
			else if(A[i] == 1) one++;
		}
		printf("%lld\n", (ll)one << zero);
	}
	return 0;
}