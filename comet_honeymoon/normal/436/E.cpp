#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N, M;
int A[300005], B[300005];
int cnt[300005];
struct node {
	ll v; int p;
	bool operator < (const node b) const { return v > b.v; }
}; priority_queue<node> q1, q2, q3, q4, q5;

/*
0			-> a[i]			: (a[i])
a[i]		-> b[i]			: (b[i] - a[i])
a[i]+0		-> 0+b[j]		: (b[j]) (- a[i])
b[i]+0		-> a[i]+b[j]	: (b[j]) (- b[i] + a[i])
*/

void to_0(int u) {
	cnt[u] = 0;
	q1.push((node){A[u], u});
	q3.push((node){B[u], u});
}
void to_1(int u) {
	cnt[u] = 1;
	q2.push((node){B[u] - A[u], u});
	q4.push((node){-A[u], u});
}
void to_2(int u) {
	cnt[u] = 2;
	q5.push((node){-B[u] + A[u], u});
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i], &B[i]);
		q1.push((node){A[i], i});
		q3.push((node){B[i], i});
	}
	long long ans = 0;
	while(M--) {
		while(q1.size() && cnt[q1.top().p] != 0) q1.pop();
		while(q2.size() && cnt[q2.top().p] != 1) q2.pop();
		while(q3.size() && cnt[q3.top().p] != 0) q3.pop();
		while(q4.size() && cnt[q4.top().p] != 1) q4.pop();
		while(q5.size() && cnt[q5.top().p] != 2) q5.pop();
		
		int opt = -1, u = -1, v = -1; ll val = 1e18;
		if(q1.size() && q1.top().v < val) opt = 1, u = q1.top().p, val = q1.top().v;
		if(q2.size() && q2.top().v < val) opt = 2, u = q2.top().p, val = q2.top().v;
		if(q3.size() && q4.size() && q3.top().v + q4.top().v < val)
			opt = 3, u = q4.top().p, v = q3.top().p, val = q3.top().v + q4.top().v;
		if(q3.size() && q5.size() && q3.top().v + q5.top().v < val)
			opt = 4, u = q5.top().p, v = q3.top().p, val = q3.top().v + q5.top().v;
		
		ans += val;
		if(opt == 1) { q1.pop(); to_1(u); }
		if(opt == 2) { q2.pop(); to_2(u); }
		if(opt == 3) { q3.pop(); q4.pop(); to_0(u); to_2(v); }
		if(opt == 4) { q3.pop(); q5.pop(); to_1(u); to_2(v); }
	}
	printf("%lld\n", ans);
	for(int i = 1; i <= N; i++) printf("%d", cnt[i]);
}