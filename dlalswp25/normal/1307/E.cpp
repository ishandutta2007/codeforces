#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int S[5050];
vector<int> id[5050];

int F[5050];
int H[5050];
int L[5050];
int R[5050];

int cid[5050];

int N, M;
int mx;
ll ans;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &S[i]);

	for(int i = 1; i <= M; i++) {
		scanf("%d%d", &F[i], &H[i]);
		id[F[i]].push_back(i);
	}

	for(int i = 1; i <= M; i++) {
		int p = 1;
		int cnt = 0;
		while(p <= N) {
			if(S[p] == F[i]) cnt++;
			if(cnt >= H[i]) break;
			p++;
		}
		L[i] = p;

		cid[L[i]] = i;

		p = N;
		cnt = 0;
		while(p >= 1) {
			if(S[p] == F[i]) cnt++;
			if(cnt >= H[i]) break;
			p--;
		}
		R[i] = p;
	}

	// for(int i = 1; i <= M; i++) printf("%d %d\n", L[i], R[i]);

	for(int i = 1; i <= N; i++) {
		if(!cid[i]) continue;

		int tmp = 1;
		ll cnt = 0;
		bool ok = false;
		for(int j : id[F[cid[i]]]) {
			if(j == cid[i]) continue;
			if(R[j] > i) {
				if(!ok) { ok = true; tmp++; }
				cnt++;
			}
		}
		if(!ok) cnt = 1;

		for(int j = 1; j <= N; j++) {
			if(j == F[cid[i]]) continue;

			int c1 = 0, c2 = 0, c3 = 0;

			for(int k : id[j]) {
				if(L[k] <= i && R[k] > i) c3++;
				else if(L[k] <= i) c1++;
				else if(R[k] > i) c2++;
			}
			// printf("%d %d %d %d\n", j, c1, c2, c3);

			if((c1 && c2) || (c2 && c3) || (c3 && c1) || c3 >= 2) {
				tmp += 2;

				ll cnt2 = 0;
				cnt2 += c3 * (c3 - 1);
				cnt2 += c2 * c3;
				cnt2 += c1 * c3;
				cnt2 += c1 * c2;
				cnt2 %= MOD;
				cnt = cnt * cnt2 % MOD;
			}
			else if(c1 + c2 + c3 > 0) {
				tmp++;
				cnt = cnt * (c1 + c2 + 2 * c3) % MOD;
			}
		}

		// printf("%d %d %lld\n", i, tmp, cnt);

		if(tmp > mx) { mx = tmp; ans = cnt; }
		else if(tmp == mx) { ans = (ans + cnt) % MOD; }
	}

	int tmp = 0;
	ll cnt = 1;
	for(int i = 1; i <= N; i++) {
		int sz = 0;
		for(int j : id[i]) if(R[j] > 0) sz++;

		if(sz) {
			cnt = cnt * sz % MOD;
			tmp++;
		}
	}
	// printf("%d %lld\n", tmp, cnt);
	if(tmp > mx) { mx = tmp; ans = cnt; }
	else if(tmp == mx) { ans = (ans + cnt) % MOD; }

	printf("%d %lld\n", mx, ans);

	return 0;
}