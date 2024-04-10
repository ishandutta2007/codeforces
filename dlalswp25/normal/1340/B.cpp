#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[2020][10];

char B[10][10] = {
	"1110111",
	"0010010",
	"1011101",
	"1011011",
	"0111010",
	"1101011", "1101111", "1010010", "1111111", "1111011"
};

bool D[2020][2020];
bool vst[2020][2020];

int num(int a, int n) {
	int ret = 0;
	for(int i = 0; i < 7; i++) {
		if(A[a][i] == '1' && B[n][i] == '0') return -1;
		if(A[a][i] != B[n][i]) ret++;
	}
	return ret;
}

bool f(int n, int k) {
	if(n > N) return D[n][k] = (k == 0);
	if(vst[n][k]) return D[n][k];

	vst[n][k] = true;
	D[n][k] = false;

	for(int i = 0; i <= 9; i++) {
		int t = num(n, i);
		if(t == -1 || t > k) continue;
		D[n][k] |= f(n + 1, k - t);
	}
	return D[n][k];
}

int main() {
	scanf("%d%d\n", &N, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%s", A[i]);
	}

	bool t = f(1, K);
	if(!t) { puts("-1"); return 0; }

	for(int i = 1; i <= N; i++) {
		for(int j = 9; j >= 0; j--) {
			int t = num(i, j);
			if(t == -1 || t > K) continue;
			if(f(i + 1, K - t)) {
				printf("%d", j);
				K -= t;
				break;
			}
		}
	}
	puts("");

	return 0;
}