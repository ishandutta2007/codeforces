#include <bits/stdc++.h>
using namespace std;

const int ushitapinichiakun = -1;
vector<int> X[100009]; bool bb[8][8][8];

void init() {
	for (int i = 1; i <= 100000; i++) {
		for (int j = i; j <= 100000; j += i) X[j].push_back(i);
	}
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int ncr(int n, int r) {
	if (r == 0) return 1;
	if (r == 1) return n;
	if (r == 2) return n * (n - 1) / 2;
	if (r == 3) return n * (n - 1) * (n - 2) / 6;
	return ushitapinichiakun;
}

int solve(int a, int b, int c) {
	int v[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	v[7] = (int)X[gcd(a, gcd(b, c))].size();
	v[6] = (int)X[gcd(b, c)].size() - v[7];
	v[5] = (int)X[gcd(a, c)].size() - v[7];
	v[4] = (int)X[c].size() - v[5] - v[6] - v[7];
	v[3] = (int)X[gcd(a, b)].size() - v[7];
	v[2] = (int)X[b].size() - v[3] - v[6] - v[7];
	v[1] = (int)X[a].size() - v[3] - v[5] - v[7];
	
	int ans = 0;
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) bb[i][j][k] = false;
		}
	}
	
	vector<int> sa = {1, 3, 5, 7};
	vector<int> sb = {2, 3, 6, 7};
	vector<int> sc = {4, 5, 6, 7};
	for (int ta : sa) {
		for (int tb : sb) {
			for (int tc : sc) {
				int u[3] = {ta, tb, tc}; sort(u, u + 3);
				if (bb[u[0]][u[1]][u[2]] == true) continue;
				
				bb[u[0]][u[1]][u[2]] = true;
				
				int w[8] = {0, 0, 0, 0, 0, 0, 0, 0};
				w[ta]++; w[tb]++; w[tc]++;
				
				int sum = 1;
				for (int i = 1; i < 8; i++) sum *= ncr(v[i] + w[i] - 1, w[i]);
				ans += sum;
			}
		}
	}
	return ans;
}

int main() {
	init();
	int T, A, B, C; scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d", &A, &B, &C);
		printf("%d\n", solve(A, B, C));
	}
	return 0;
}