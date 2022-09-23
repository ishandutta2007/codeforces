#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char A[100005];
ll L[100005];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &L[i]);

	scanf("%s", A + 1);

	ll ans = 0;
	bool w = false;
	ll s1 = 0, s2 = 0;

	for(int i = 1; i <= N; i++) {
		if(A[i] == 'L') {
			ans += L[i];
			if(s1 >= L[i]) {
				ans += L[i];
				s1 -= L[i];
			}
			else {
				ans += s1;
				L[i] -= s1; s1 = 0;

				if(s2 >= L[i]) {
					ans += 2 * L[i];
					s2 -= L[i];
				}
				else {
					ans += 2 * s2;
					L[i] -= s2; s2 = 0;
					if(!w) ans += 5 * L[i];
					else ans += 3 * L[i];
				}
			}
		}
		else if(A[i] == 'G') {
			ans += L[i];
			if(s1 >= L[i]) {
				ans += L[i];
				s1 -= L[i];
				s2 += 2 * L[i];
			}
			else {
				ans += s1;
				s2 += 2 * s1;
				L[i] -= s1; s1 = 0;

				ans += 2 * L[i];
				s2 += L[i];
			}
		}
		else {
			w = true;
			ans += 2 * L[i];
			s1 += L[i];
		}
	}
	printf("%lld\n", ans);

	return 0;
}