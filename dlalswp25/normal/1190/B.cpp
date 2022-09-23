#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[101010];
ll s;
int z;
int c;

map<ll, int> mp;

int main() {
	scanf("%lld", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		if(mp[A[i]] > 0) c++;
		if(A[i] == 0) z++;
		s += A[i];
		mp[A[i]]++;
	}

	sort(A + 1, A + N + 1);
	for(int i = 3; i <= N; i++) {
		if(A[i] == A[i - 1]) {
			if(A[i - 2] >= A[i - 1] - 1) {
				puts("cslnb");
				return 0;
			}
		}
	}

	if(z >= 2 || c >= 2) {
		puts("cslnb");
		return 0;
	}

	if(((N - 1) * N / 2 - s) % 2) puts("sjfnb");
	else puts("cslnb");

	return 0;
}