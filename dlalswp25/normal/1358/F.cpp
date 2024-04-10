#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[202020];
ll B[202020];

vector<int> ans;
ll tmp;

bool fg = false;

void putans() {
	if(fg) {
		if(ans.size() == 0 || ans.back() != 1) ans.push_back(1);
		else ans.pop_back();
	}
	tmp = 0;
	for(int i : ans) tmp += (i == 2);
	if(tmp <= 200000) {
		puts("SMALL");
		printf("%d\n", ans.size());

		reverse(ans.begin(), ans.end());
		for(int i : ans) {
			if(i == 1) printf("R");
			else printf("P");
		}
		puts("");
		return;
	}
	puts("BIG");
	printf("%lld\n", tmp);
}

void no() {
	puts("IMPOSSIBLE");
}

bool chk() {
	for(int i = 1; i <= N; i++) if(A[i] != B[i]) return false;
	return true;
}

int main() {
	ll mn = (1LL << 60);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		mn = min(mn, A[i]);
	}
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);

	if(N == 1) {
		if(A[1] == B[1]) {
			putans();
		}
		else {
			no();
		}
		return 0;
	}

	if(chk()) {
		putans();
		return 0;
	}

	if(A[1] > A[2]) {
		fg = true;
		reverse(A + 1, A + N + 1);
	}

	if(N == 2) {
		ll x = B[1], y = B[2];

		while(1) {
			// printf("%lld %lld\n", x, y);
			if(x == A[1] && y == A[2]) break;
			if(min(x, y) < mn) {
				no();
				return 0;
			}
			if(x > y) { swap(x, y); continue; }

			if(x == A[1]) {
				if(y < A[2]) { no(); return 0; }
				if((y - A[2]) % x) { no(); return 0; }
				tmp += ((y - A[2]) / x);
				break;
			}
			else {
				ll k = y / x;
				y -= k * x;
				tmp += k;
			}
		}

		if(tmp > 200000) {
			puts("BIG");
			printf("%lld\n", tmp);
			return 0;
		}
	}

	if(chk()) {
		putans();
		return 0;
	}

	while(1) {
		ll mnb = (1LL << 60);
		for(int i = 1; i <= N; i++) mnb = min(mnb, B[i]);

		if(mnb < mn) {
			no();
			return 0;
		}

		int asc;
		if(B[2] == B[1]) asc = -1;
		else if(B[1] < B[2]) asc = 1;
		else asc = 0;

		for(int i = 3; i <= N; i++) {
			if(asc == -1) continue;
			if(B[i] == B[i - 1]) asc = -1;
			else if(asc == 0 && B[i - 1] < B[i]) asc = -1;
			else if(asc == 1 && B[i - 1] > B[i]) asc = -1;
		}

		if(asc == -1) {
			if(chk()) {
				putans();
				return 0;
			}
			reverse(B + 1, B + N + 1);
			ans.push_back(1);

			if(chk()) {
				putans();
				return 0;
			}

			no();
			return 0;
		}

		if(chk()) {
			putans();
			return 0;
		}

		if(asc == 1) {
			for(int i = N; i >= 2; i--) {
				B[i] -= B[i - 1];
			}
			ans.push_back(2);
		}
		else {
			reverse(B + 1, B + N + 1);
			ans.push_back(1);
		}

	}
	return 0;
}