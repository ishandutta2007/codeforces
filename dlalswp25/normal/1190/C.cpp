#include <bits/stdc++.h>

using namespace std;

int mx[2];
int mn[2];
char S[101010];
int N, K;

set<int> s0, s1;

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", S + 1);
	for(int i = 1; i <= N; i++) S[i] -= '0';
	mn[0] = mn[1] = 987654321;
	
	for(int i = 1; i <= N; i++) {
		mn[S[i]] = min(mn[S[i]], i);
		mx[S[i]] = max(mx[S[i]], i);

		if(S[i] == 0) s0.insert(i);
		else s1.insert(i);
	}

	if(mx[1] - mn[1] + 1 <= K || mx[0] - mn[0] + 1 <= K || mx[0] == 987654321 || mx[1] == 987654321) {
		puts("tokitsukaze"); return 0;
	}

	int l, r;

	for(int i = 1; i <= N; i++) {
		if(S[i] == 1) { l = i + 1; break; }
	}
	for(int i = N; i >= 1; i--) {
		if(S[i] == 1) { r = i - 1; break; }
	}

	if(r - l + 1 >= K) { puts("once again"); return 0; }

	for(int i = 1; i <= N; i++) {
		if(S[i] == 0) { l = i + 1; break; }
	}
	for(int i = N; i >= 1; i--) {
		if(S[i] == 0) { r = i - 1; break; }
	}

	if(r - l + 1 >= K) { puts("once again"); return 0; }

	l = -1;
	for(int i = 1; i <= N - K; i++) {
		if(S[i] == 1) {
			if(l == -1) l = i;
			else {
				r = i;
				if(r - l >= K) { puts("once again"); return 0; }
			}
		}
	}

	l = -1;
	for(int i = 1; i <= N - K; i++) {
		if(S[i] == 0) {
			if(l == -1) l = i;
			else {
				r = i;
				if(r - l >= K) { puts("once again"); return 0; }
			}
		}
	}

	r = -1;
	for(int i = N; i >= K + 1; i--) {
		if(S[i] == 1) {
			if(r == -1) r = i;
			else {
				l = i;
				if(r - l >= K) { puts("once again"); return 0; }
			}
		}
	}

	r = -1;
	for(int i = N; i >= K + 1; i--) {
		if(S[i] == 0) {
			if(r == -1) r = i;
			else {
				l = i;
				if(r - l >= K) { puts("once again"); return 0; }
			}
		}
	}

	puts("quailty");
	return 0;
}