#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
pii A[101010];
pii B[101010];
int pos[101010];
int p[101010];
int up[101010];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i].first); A[i].second = i;
		}
		for(int i = 1; i <= N; i++) {
			scanf("%d", &B[i].first); B[i].second = i;
		}
		sort(A + 1, A + N + 1);
		reverse(A + 1, A + N + 1);
		for(int i = 1; i <= N; i++) pos[A[i].second] = i;
		for(int i = 1; i <= N; i++) up[A[i].second] = A[i - 1].second;
		for(int i = 1; i <= N; i++) p[i] = i;

		sort(B + 1, B + N + 1);
		for(int i = 1; i < N; i++) {
			int x = B[i].second, y = B[i + 1].second;
			x = par(x); y = par(y);
			if(pos[x] >= pos[y]) continue;
			while(x != y) {
				unite(y, up[y]);
				y = par(y);
			}
		}
		for(int i = 1; i <= N; i++) {
			int t = par(i);
			if(!up[t]) printf("1");
			else printf("0");
		}
		puts("");
	}
	return 0;
}