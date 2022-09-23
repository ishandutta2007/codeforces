#include <bits/stdc++.h>

using namespace std;

char S[1000005];
char A[1000005];
char B[1000005];
int M[150];
int M2[150];
bool used[150];
bool used2[150];
int N;
char term;

bool go_fa(int i) {
	for(; i < N; i++) {
		if(M[S[i]]) {
			if(M[S[i]] < A[i]) return false;
			if(M[S[i]] > A[i]) return true;
		}
		else {
			for(int j = A[i] + 1; j <= term; j++) {
				if(!used[j]) { used[j] = true; M[S[i]] = j; return true; }
			}
			if(used[A[i]]) return false;
			used[A[i]] = true; M[S[i]] = A[i];
		}
	}
	return true;
}
bool go_fb(int i) {
	for(; i < N; i++) {
		if(M[S[i]]) {
			if(M[S[i]] > B[i]) return false;
			if(M[S[i]] < B[i]) return true;
		}
		else {
			for(int j = 'a'; j < B[i]; j++) {
				if(!used[j]) { used[j] = true; M[S[i]] = j; return true; }
			}
			if(used[B[i]]) return false;
			used[B[i]] = true; M[S[i]] = B[i];
		}
	}
	return true;
}

void yes() {

	int p = 'a';

	for(int i = 'a'; i <= term; i++) {
		if(M[i]) continue;
		while(used[p]) p++;
		M[i] = p; used[p] = true;
	}

	puts("YES");
	for(int i = 'a'; i <= term; i++) printf("%c", M[i]); puts("");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int K; scanf("%d", &K);
		term = 'a' + K - 1;
		scanf("%s", S);
		scanf("%s", A);
		scanf("%s", B);

		N = strlen(S);
		for(int i = 'a'; i <= term; i++) { M[i] = 0; used[i] = false; }

		bool fa = true, fb = true;
		bool ok = true;
		bool alt = false;

		int i;

		for(i = 0; i < N; i++) {
			if(!ok) break;
			if(fa && fb) {
				if(M[S[i]]) {
					if(M[S[i]] < A[i] || M[S[i]] > B[i]) { ok = false; continue; }
					if(M[S[i]] < B[i]) fb = false;
					if(M[S[i]] > A[i]) fa = false;
				}
				else {
					if(A[i] == B[i]) {
						if(used[A[i]]) ok = false;
						else {
							M[S[i]] = A[i]; used[A[i]] = true;
						}
					}
					else {
						for(int j = A[i] + 1; j < B[i]; j++) {
							if(!used[j]) { M[S[i]] = j; used[j] = true; fa = fb = false; break; }
						}
						if(!M[S[i]]) {
							if(!used[A[i]] && used[B[i]]) {
								M[S[i]] = A[i]; used[A[i]] = true;
								fb = false;
							}
							else if(used[A[i]] && !used[B[i]]) {
								M[S[i]] = B[i]; used[B[i]] = true;
								fa = false;
							}
							else if(used[A[i]] && used[B[i]]) {
								ok = false;
							}
							else {
								alt = true; fa = fb = false;
							}
						}
					}
				}
			}
			else break;
		}
		if(!ok) { puts("NO"); continue; }
		//printf("%d %d %d %d\n", i, fa, fb, alt);

		if(alt) {
			for(int j = 'a'; j <= term; j++) { used2[j] = used[j]; M2[j] = M[j]; }
			i--;
			M[S[i]] = A[i]; used[A[i]] = true;
			if(go_fa(i + 1)) {
				yes();
				continue;
			}
			for(int j = 'a'; j <= term; j++) { used[j] = used2[j]; M[j] = M2[j]; }
			M[S[i]] = B[i]; used[B[i]] = true;
			//printf("%d\n", i);
			if(go_fb(i + 1)) {
				yes();
			}
			else {
				puts("NO");
			}
		}
		
		else if(fa) {
			if(go_fa(i)) {
				yes();
			}
			else puts("NO");
		}

		else if(fb) {
			if(go_fb(i)) {
				yes();
			}
			else puts("NO");
		}

		else {
			yes();
		}
	}

	return 0;
}