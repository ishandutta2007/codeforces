#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int A[303030];
int B[303030];
int N;
int x, y;
vector<pii> V;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i], &B[i]);
		if(A[i] > B[i]) x++;
		else y++;
	}

	if(x > y) {
		printf("%d\n", x);
		for(int i = 1; i <= N; i++) if(A[i] > B[i]) V.push_back({B[i], i});
		sort(V.begin(), V.end());
		for(pii i : V) printf("%d ", i.second); puts("");
	}
	else {
		printf("%d\n", y);
		for(int i = 1; i <= N; i++) if(A[i] < B[i]) V.push_back({B[i], i});
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());
		for(pii i : V) printf("%d ", i.second); puts("");
	}
	return 0;
}