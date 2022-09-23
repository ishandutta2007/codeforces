#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int BSZ1 = 1010;
const int BSZ2 = 200;

int N;
char A[202020];
int B[40404040];
int C[202020];

ll ans;

//map<int, int> mp;
int R[202020];

void calc(int i, int r, int zero) {
	int t = (zero + R[r]) / i;
	int u = zero / i; if(zero % i != 0) u++;
	if(t > BSZ2) {
		u = max(u, BSZ2 + 1);
		ans += (t - u + 1);
	}
}

int main() {
	scanf("%s", A + 1);
	N = strlen(A + 1);

	for(int i = N - 1; i >= 1; i--) {
		if(A[i + 1] == '0') R[i] = R[i + 1] + 1;
		else R[i] = 0;
	}

	for(int i = 1; i <= BSZ1; i++) {
		int l = 1, r = 1;
		int zero = 0, cnt = 0;
		while(r <= N && cnt < i) {
			if(A[r] == '1') cnt++;
			else zero++;
			r++;
		}
		if(cnt < i) continue;
		r--;

		while(1) {
			while(A[l] == '0') {
				calc(i, r, zero);
				l++; zero--;
			}
			calc(i, r, zero);

			l++; r++;
			while(r <= N) {
				if(A[r] == '1') break;
				else zero++;
				r++;
			}
			
			if(r > N) break;
		}
	}

	// for(int i = 0; i <= BSZ2; i++) {
	// 	mp.clear(); mp[0]++;
	// 	int c = 0;
	// 	for(int j = 1; j <= N; j++) {
	// 		if(A[j] == '1') c += i;
	// 		else c--;
	// 		ans += mp[c];
	// 		mp[c]++;
	// 	}
	// }

	for(int i = 0; i <= BSZ2; i++) {
		B[N]++; C[0] = N;
		int c = N;
		for(int j = 1; j <= N; j++) {
			if(A[j] == '1') c += i;
			else c--;
			ans += B[c];
			B[c]++;
			C[j] = c;
		}
		for(int j = 0; j <= N; j++) B[C[j]] = 0;
	}
	printf("%lld\n", ans);

	return 0;
}