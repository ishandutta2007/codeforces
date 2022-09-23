#include <bits/stdc++.h>

using namespace std;

int L, R;
int N;
int A[131313];
int ans;

void f(int b, int s, int e) {
	if(b < 0) return;
	int m = s + e >> 1;
	if(R <= m) {
		if(A[1] & 1 << b) ans |= 1 << b;
		f(b - 1, s, m); return;
	}
	if(L > m) {
		if(~A[1] & 1 << b) ans |= 1 << b;
		f(b - 1, m + 1, e); return;
	}

	vector<int> vl, vr;
	for(int i = 1; i <= N; i++) {
		if(A[i] & 1 << b) vr.push_back(A[i]);
		else vl.push_back(A[i]);
	}

	if(vl.size() != m - L + 1) {
		ans |= 1 << b;
		swap(vl, vr);
	}

	for(int i = b - 1; i >= 0; i--) {
		int cnt[2] = {0, 0};
		for(int j : vl) cnt[j >> i & 1]++;
		if(cnt[0] > cnt[1]) { ans |= 1 << i; continue; }
		cnt[0] = cnt[1] = 0;
		for(int j : vr) cnt[j >> i & 1]++;
		if(cnt[1] > cnt[0]) { ans |= 1 << i; continue; }
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &L, &R);
		N = R - L + 1;
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		ans = 0;
		f(16, 0, (1 << 17) - 1);
		printf("%d\n", ans);
	}
	return 0;
}