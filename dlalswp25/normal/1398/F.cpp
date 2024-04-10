#include <bits/stdc++.h>

using namespace std;

int N;
char A[1010101];
int R[1010101];
int p[1010101];

vector<int> v[3];

vector<int> evt[1010101];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

int main() {
	scanf("%d", &N);
	scanf("%s", A + 1);

	int t0 = -1, t1 = -1;
	int l = 0;
	for(int i = 1; i <= N; i++) {
		if(A[i] == '1') {
			if(t1 == -1 && t0 != -1) {
				for(int j = l; j <= t0; j++) {
					R[j] = i - j;
				}
				l = t0 + 1;
			}
			t1 = i;
			t0 = -1;
		}
		else if(A[i] == '0') {
			if(t0 == -1 && t1 != -1) {
				for(int j = l; j <= t1; j++) {
					R[j] = i - j;
				}
				l = t1 + 1;
			}
			t0 = i;
			t1 = -1;
		}
	}

	for(int i = l; i <= N; i++) R[i] = N + 1 - i;
	// for(int i = 1; i <= N; i++) printf("%d ", R[i]); puts("");

	for(int i = 1; i <= N; i++) evt[R[i]].push_back(i);
	for(int i = 1; i <= N + 1; i++) p[i] = i;

	for(int i = 1; i <= N; i++) {
		for(int j : evt[i - 1]) unite(j, j + 1);
		int x = par(1);
		int ans = 0;
		while(x <= N) {
			ans++;
			x += i;
			x = par(x);
		}
		printf("%d ", ans);
	}
	puts("");

	return 0;
}