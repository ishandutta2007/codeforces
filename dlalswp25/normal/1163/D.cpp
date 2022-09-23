#include <bits/stdc++.h>

using namespace std;

int D[1010][55][55];
bool chk[1010][55][55];
char C[1010];
char S[55];
char T[55];
int N, A, B;
int nxts[55][30];
int nxtt[55][30];
int ns0;
int nt0;

int f(int n, int s, int t) {
	if(chk[n][s][t]) return D[n][s][t];
	//printf("%d %d %d\n", n, s, t);
	chk[n][s][t] = true;
	int& ret = D[n][s][t];
	ret = -987654321;
	if(s == A) return ret = 1 + f(n, ns0, t);
	if(t == B) return ret = -1 + f(n, s, nt0);
	if(n > N) return ret = 0;
	if(C[n] != '*') {
		int ns = nxts[s][C[n] - 'a'];
		int nt = nxtt[t][C[n] - 'a'];
		//printf("%d %d %d %d %d\n", n, s, t, ns, nt);
		return ret = f(n + 1, ns, nt);
	}
	for(int i = 'a'; i <= 'z'; i++) {
		int ns = nxts[s][i - 'a'];
		int nt = nxtt[t][i - 'a'];
		ret = max(ret, f(n + 1, ns, nt));
	}
	return ret;
}

int main() {
	scanf("%s", C + 1); scanf("%s", S + 1); scanf("%s", T + 1);
	N = strlen(C + 1);
	A = strlen(S + 1);
	B = strlen(T + 1);


	for(int i = 0; i <= A; i++) {
		for(int j = 0; j < 26; j++) {
			for(int k = 0; k <= i; k++) {
				bool ok = true;
				int l = 1;
				for(; k + l <= i; l++) {
					if(S[k + l] != S[l]) ok = false;
				}
				if(ok && S[l] == j + 'a') {
					nxts[i][j] = max(nxts[i][j], i + 1 - k);
				}
			}
		}
	}

	for(int i = 0; i <= B; i++) {
		for(int j = 0; j < 26; j++) {
			for(int k = 0; k <= i; k++) {
				bool ok = true;
				int l = 1;
				for(; k + l <= i; l++) {
					if(T[k + l] != T[l]) ok = false;
				}
				if(ok && T[l] == j + 'a') {
					nxtt[i][j] = max(nxtt[i][j], i + 1 - k);
				}
			}
		}
	}

	for(int i = 2; i <= A; i++) {
		bool ok = true;
		for(int j = 0; i + j <= A; j++) {
			if(S[1 + j] != S[i + j]) ok = false;
		}
		if(ok) ns0 = max(ns0, A - i + 1);
	}
	for(int i = 2; i <= B; i++) {
		bool ok = true;
		for(int j = 0; i + j <= B; j++) {
			if(T[1 + j] != T[i + j]) ok = false;
		}
		if(ok) nt0 = max(nt0, B - i + 1);
	}

	printf("%d\n", f(1, 0, 0));
	//printf("%d\n", D[3][1][1]);

	return 0;
}