#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MX = 400000;

char S[202020];
ll D[402020];
int N, K;
priority_queue<pii, vector<pii>, greater<pii> > pq;

ll T[4 * 404040];

void upd(int idx, int s, int e, int p, ll x) {
	if(e < s || p < s || e < p) return;
	if(s == e) { T[idx] = x; return; }
	int m = s + e >> 1;
	upd(idx << 1, s, m, p, x);
	upd(idx << 1 | 1, m + 1, e, p, x);
	T[idx] = min(T[idx << 1], T[idx << 1 | 1]);
}

ll get(int idx, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return (1LL) << 60;
	if(p <= s && e <= q) return T[idx];
	int m = s + e >> 1;
	return min(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
}

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", S + 1);

	D[N] = N;
	upd(1, 1, MX, N, N);
	if(S[N] == '1') pq.push({N, N});

	for(int i = N - 1; i >= 1; i--) {
		if(S[i] == '1') D[i] = get(1, 1, MX, i + 1, i + K + 1) + i;
		else D[i] = D[i + 1] + i;

		while(pq.size() && pq.top().second > i + K) pq.pop();
		if(pq.size()) {
			D[i] = min(D[i], pq.top().first);
		}
		upd(1, 1, MX, i, D[i]);
		if(S[i] == '1') pq.push({get(1, 1, MX, i + 1, i + K + 1) + i, i});
	}
	//for(int i = 1; i <= N; i++) printf("%lld ", D[i]);
	printf("%lld\n", D[1]);

	return 0;
}