#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

priority_queue<int, vector<int>, greater<int> > pq;

int N, K;
ll ans = 0;

int main() {
	scanf("%d%d", &N, &K);
	int b = 0;
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		if(i > 1) pq.push(x - b);
		b = x;
	}
	for(int i = 1; i <= N - K; i++) {
		ans = ans + pq.top(); pq.pop();
	}
	printf("%lld\n", ans);
	return 0;
}