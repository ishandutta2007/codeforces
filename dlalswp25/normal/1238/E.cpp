#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

char S[101010];
int N, M;
int D[1212121];
int E[1212121][22];
int F[1212121];

int C[22][22];

int f(int x) {
	if(x == (1 << M) - 1) return F[x]; 
	if(D[x] != -1) return D[x];

	int& ret = D[x]; ret = INF;
	for(int i = 0; i < M; i++) {
		if(x & (1 << i)) continue;
		ret = min(ret, f(x | (1 << i)));
	}
	return ret = ret + F[x];
}

int main() {
	scanf("%d%d", &N, &M);
	scanf("%s", S + 1);
	for(int i = 2; i <= N; i++) {
		int a = S[i - 1] - 'a';
		int b = S[i] - 'a';
		C[a][b]++; C[b][a]++;
	}

	for(int i = 0; i < 1212121; i++) D[i] = -1;

	for(int i = 1; i < (1 << M); i++) {
		int t = 0;
		while(1) {
			if(i & (1 << t)) break;
			t++;
		}
		for(int j = 0; j < M; j++) {
			if(i & (1 << j)) continue;
			E[i][j] = E[i ^ (1 << t)][j] + C[t][j];
			F[i] += E[i][j];
		}
	}

	printf("%d\n", f(0));

	return 0;
}