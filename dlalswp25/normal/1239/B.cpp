#include <bits/stdc++.h>

using namespace std;

char S[303030];
int A[303030];
int L[303030];
int R[303030];

int N;
int ans;
int x1, x2;
int mn = 10101010;

void f(int s, int e, int p) {
	int l = s, r = e;
	while(l <= e) {
		if(S[l] == '(') break;
		l++;
	}
	if(l > e) return;

	while(r >= s) {
		if(S[r] == ')') break;
		r--;
	}
	if(r < s || r < l) return;

	int cnt = 0;

	for(int i = l; i < r; i++) if(A[i] == p) cnt++;
	if(p == mn + 2) {
		if(ans < cnt + L[l] + R[r]) { ans = cnt + L[l] + R[r]; x1 = l; x2 = r; }
	}
	else {
		if(ans < cnt) { ans = cnt; x1 = l; x2 = r; }
	}
}

int main() {
	scanf("%d", &N);
	scanf("%s", S + 1);
	for(int i = 1; i <= N; i++) {
		if(S[i] == '(') A[i] = A[i - 1] + 1;
		else A[i] = A[i - 1] - 1;
	}

	if(A[N] != 0) { printf("0\n1 1\n"); return 0; }
	x1 = x2 = 1;

	for(int i = 1; i <= N; i++) mn = min(mn, A[i]);
	for(int i = 1; i <= N; i++) if(A[i] == mn) ans++;
	for(int i = 1; i <= N; i++) L[i] = L[i - 1] + (A[i] == mn);
	for(int i = N; i >= 1; i--) R[i] = R[i + 1] + (A[i] == mn);

	f(1, N, mn);

	int p = 1, bf = 0;
	while(p <= N) {
		if(A[p] > mn) { p++; continue; }
		f(bf + 1, p, mn + 1); bf = p; p++;
	}

	p = 1, bf = 0;
	while(p <= N) {
		if(A[p] > mn + 1) {
			p++; continue;
		}
		f(bf + 1, p, mn + 2); bf = p; p++;
	}

	if(mn == 0) {
		printf("%d\n%d %d\n", ans, x1, x2);
		return 0;
	}

	int ml = 0, mr;
	for(int i = 1; i <= N; i++) {
		if(A[i] == mn) {
			mr = i;
			if(!ml) ml = i;
		}
	}

	int cnt = 0;
	for(int i = 1; i < ml; i++) if(A[i] == mn + 1) cnt++;
	for(int i = mr + 1; i <= N; i++) if(A[i] == mn + 1) cnt++;
	if(cnt > ans) { ans = cnt; x1 = ml; x2 = mr + 1; }
	
	ml = 0, mr;
	for(int i = 1; i <= N; i++) {
		if(A[i] <= mn + 1) {
			mr = i;
			if(!ml) ml = i;
		}
	}

	if(S[ml] == ')' && S[mr + 1] == '(') {
		cnt = 0;
		for(int i = 1; i < ml; i++) if(A[i] == mn + 2) cnt++;
		for(int i = ml; i <= mr; i++) if(A[i] == mn) cnt++;
		for(int i = mr + 1; i <= N; i++) if(A[i] == mn + 2) cnt++;
		if(cnt > ans) { ans = cnt; x1 = ml; x2 = mr + 1; }
	}

	printf("%d\n%d %d\n", ans, x1, x2);

	return 0;
}