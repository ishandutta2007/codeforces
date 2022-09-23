#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MX = 40000;

int N;
vector<int> P;
int D[40404][505];

int main() {
	for(int i = 1; i <= MX; i++) {
		int tmp = i;
		vector<int> v;
		while(tmp) {
			v.push_back(tmp % 10);
			tmp /= 10;
		}
		bool ok = true;
		for(int j = 0; j < v.size(); j++) {
			if(v[j] != v[(int)v.size() - 1 - j]) ok = false;
		}
		if(ok) P.push_back(i);
	}

	int M = P.size();
	for(int i = 0; i < M; i++) D[0][i] = 1;
	for(int i = 1; i <= MX; i++) {
		for(int j = 0; j < M; j++) {
			D[i][j] = D[i][j - 1];
			if(P[j] <= i) D[i][j] = (D[i][j] + D[i - P[j]][j]) % MOD;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		printf("%d\n", D[N][M - 1]);
	}
	return 0;
}