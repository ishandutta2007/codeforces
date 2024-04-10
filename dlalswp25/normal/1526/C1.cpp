#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[202020];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	ll s = 0;
	for(int i = 1; i <= N; i++) {
		s += A[i]; pq.push(A[i]);
		while(s < 0) { s -= pq.top(); pq.pop(); }
	}

	printf("%d\n", pq.size());
	return 0;
}