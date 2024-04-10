#include <bits/stdc++.h>

using namespace std;

int N;
char S[202020];
int A, B, C, D;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%d", &A, &B, &C, &D);
		N = A + B + 2 * (C + D);
		scanf("%s", S + 1);
		int ca = 0;
		for(int i = 1; i <= N; i++) ca += (S[i] == 'A');
		if(ca != A + C + D) { puts("NO"); continue; }
		priority_queue<int, vector<int>, greater<int>> pqA, pqB;
		int x = 0;

		int l = 1;
		S[N + 1] = S[N];
		for(int i = 2; i <= N + 1; i++) {
			if(S[i] == S[i - 1]) {
				if(l + 1 < i) {
					if((i - l) % 2 == 0) {
						if(S[l] == 'A') pqA.push((i - l) / 2);
						else pqB.push((i - l) / 2);
					}
					else x += (i - l) / 2;
				}
				l = i;
			}
		}
		while(pqA.size() && pqA.top() <= C) {
			C -= pqA.top(); pqA.pop();
		}
		while(pqB.size() && pqB.top() <= D) {
			D -= pqB.top(); pqB.pop();
		}
		while(pqA.size()) {
			x += pqA.top() - 1; pqA.pop();
		}
		while(pqB.size()) {
			x += pqB.top() - 1; pqB.pop();
		}
		if(x >= C + D) puts("YES");
		else puts("NO");
	}
	return 0;
}