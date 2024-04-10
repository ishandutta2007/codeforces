#include <bits/stdc++.h>

using namespace std;

char S[5050];
int N;

int main() {
	scanf("%s", S);
	N = strlen(S);
	bool ok = false;
	for(int i = 1; i < N; i++) if(S[i] != S[0]) ok = true;
	if(!ok || N == 1) {
		puts("Impossible"); return 0;
	}
	if(N & 1) {
		ok = false;
		for(int i = 0; i < N; i++) {
			if(i == (N - 1) / 2) continue;
			if(S[i] != S[0]) ok = true;
		}
		if(!ok) { puts("Impossible"); return 0; }
	}

	for(int i = 0; i < N - 1; i++) {
		bool ok = true;
		for(int j = 0; j < N; j++) {
			int l = (i + j + 1) % N;
			int r = (i + N - j) % N;
			if(S[l] != S[r]) ok = false;
		}
		bool sm = true;
		for(int j = 0; j < N; j++) {
			if(S[j] != S[(j + i + 1) % N]) sm = false;
		}
		if(ok && !sm) { puts("1"); return 0; }
	}
	puts("2");
	return 0;
}