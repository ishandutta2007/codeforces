#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int A[2005][2005];
ll DP[2005][2005];
ll F[2005];
ll G[2005];
int N;
int cnt[2005];
bool used[2005];
pii T[2005 * 4];

void update(int idx, int s, int e, int p, int x, bool type) { // 0 : down, 1 : up
	if(e < s || p < s || e < p) return;
	if(s == e) {
		T[idx].second += x;
		if(!type) T[idx].first += x;
		T[idx].first = max(0, T[idx].first);
		T[idx].second = max(0, T[idx].second);
		return;
	}
	int m = (s + e) >> 1;
	update(idx * 2, s, m, p, x, type);
	update(idx * 2 + 1, m + 1, e, p, x, type);
	T[idx].first = T[idx * 2].first + T[idx * 2 + 1].first;
	T[idx].second = T[idx * 2].second + T[idx * 2 + 1].second;
}

int query(int idx, int s, int e, int p, int q, bool type) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) {
		if(!type) return T[idx].first;
		else return T[idx].second;
	}
	int m = (s + e) >> 1;
	return query(idx * 2, s, m, p, q, type) + query(idx * 2 + 1, m + 1, e, p, q, type);
}

void init() {
	for(int i = 1; i <= N; i++) cnt[i] = used[i] = 0;
	for(int i = 1; i <= 4 * N; i++) T[i] = {0, 0};
	for(int i = 1; i <= N; i++) update(1, 1, N, i, 1, 0);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
	F[0] = 1; for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	
	DP[0][2] = 1;
	for(int i = 3; i <= N; i++) DP[0][i] = (i - 1) * (DP[0][i - 1] + DP[0][i - 2]) % MOD;

	G[0] = 1; for(int i = 1; i <= N; i++) G[i] = G[i - 1] * DP[0][N] % MOD;
	
	for(int i = 1; i <= N; i++) {
		DP[i][i] = F[i];
		for(int j = i + 1; j <= N; j++) {
			DP[i][j] = (i * DP[i - 1][j - 1] + (j - i) * DP[i][j - 1]) % MOD;
		}
	}

	ll ans = 0;
	init();
	for(int i = 1; i <= N; i++) {
		int t = query(1, 1, N, 1, A[1][i] - 1, 0);
		ans = (ans + F[N - i] * t % MOD * G[N - 1]) % MOD;
		update(1, 1, N, A[1][i], -1, 0);
	}

	//printf("%d\n", ans);

	for(int i = 2; i <= N; i++) {
		int ov = 0;
		init();
		for(int j = 1; j <= N; j++) {
			int lft = query(1, 1, N, 1, A[i][j] - 1, 0);
			int x = query(1, 1, N, 1, A[i][j] - 1, 1);
			cnt[A[i - 1][j]]++; if(cnt[A[i - 1][j]] > 1) ov++;

			int y = lft - x;
			if(!used[A[i - 1][j]] && A[i][j] > A[i - 1][j]) x--;

			//printf("%d %d %d %d %d\n", i, j, ov, x, y);
			ans = (ans + (x * DP[j - ov][N - j] + y * DP[j - ov - 1][N - j]) % MOD * G[N - i]) % MOD;

			cnt[A[i][j]]++;
			if(cnt[A[i][j]] > 1) ov++;
			update(1, 1, N, A[i - 1][j], -1, 1);
			update(1, 1, N, A[i][j], -1, 0);
			used[A[i][j]] = true;
		}
		//printf("%lld\n", ans);
	}
	printf("%lld\n", ans);

	return 0;
}