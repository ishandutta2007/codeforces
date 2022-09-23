#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

const ll MOD = 998244353;

int K, Q, H, M;
ll P[7];
int X[7] = {1, 2, 3, 5, 9, 17, };
int win = -1;
int A[35];
vector<pp> v[2];

void process(int st, int state) {
	for(int j = 0; j < M; j++) {
		A[st + j] = K;
	}

	int t = 0;
	for(int j = K; j >= 2; j--) {
		int bef = -1;
		for(int k = 0; k < M; k++) {
			if(A[st + k] != j) continue;
			if(bef != -1) {
				if(state & 1 << t) A[st + k]--;
				else A[bef]--;
				t++;
				bef = -1;
			}
			else bef = st + k;
		}
	}
}

int main() {
	scanf("%d%d%d", &K, &Q, &H);
	M = 1 << K - 1;
	P[0] = Q; P[1] = (ll)Q * Q % MOD;
	for(int i = 2; i <= K; i++) {
		P[i] = P[i - 1];
		for(int j = 0; j < 1 << i - 2; j++) {
			P[i] = P[i] * Q % MOD;
		}
	}

	int st = 0;
	for(int z = 0; z < 2; z++) {
		for(int i = 0; i < 1 << M; i++) {
			process(st, i);

			int x = 0;
			int w = 0;
			for(int i = 0; i < M; i++) {
				if(A[st + i] == 1) w = st + i;
				x = (x + P[A[st + i]] * (st + i + 1)) % MOD;
			}
			// printf("%d %d %d\n", x, w, i);
			v[z].emplace_back(x, pii(w, i));
		}
		st += M;
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	int b[2];

	for(int z = 0; z < 2; z++) {
		if(win != -1) break;
		for(auto& i : v[z]) {
			int nh = (i.first + (i.second.first + 1) * (P[0] + MOD - P[1]) % MOD) % MOD;
			int goal = (H + MOD - nh) % MOD;
			auto it = lower_bound(v[1 - z].begin(), v[1 - z].end(), pp(goal, pii(0, 0)));
			if(it == v[1 - z].end() || it -> first != goal) continue;
			win = i.second.first;
			b[z] = i.second.second;
			b[1 - z] = (it -> second).second;
		}
	}

	if(win == -1) { puts("-1"); return 0; }
	process(0, b[0]);
	process(M, b[1]);
	A[win] = 0;
	for(int i = 0; i < M + M; i++) printf("%d ", X[A[i]]); puts("");

	return 0;
}