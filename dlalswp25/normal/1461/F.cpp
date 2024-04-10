#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];
int D[50];
int path[50];
char S[5];

char ans[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	scanf("%s", S);
	int M = strlen(S);
	if(M == 1) {
		for(int i = 1; i < N; i++) printf("%d%c", A[i], S[0]);
		printf("%d\n", A[N]);
		return 0;
	}
	sort(S, S + M);
	if(S[0] != '*') {
		for(int i = 1; i < N; i++) printf("%d+", A[i]);
		printf("%d\n", A[N]);
		return 0;
	}
	if(S[1] == '-') {
		int z = 0;
		for(int i = 1; i <= N; i++) if(!A[i] && !z) z = i;
		if(z <= 1) {
			for(int i = 1; i < N; i++) printf("%d*", A[i]);
			printf("%d\n", A[N]);
			return 0;
		}

		for(int i = 1; i < z - 1; i++) printf("%d*", A[i]);
		printf("%d-", A[z - 1]);
		for(int i = z; i < N; i++) printf("%d*", A[i]);
		printf("%d\n", A[N]);
		return 0;
	}

	int p = 1;
	while(1) {
		if(p > N) break;
		if(A[p] <= 1) { ans[p] = '+'; p++; continue; }

		vector<int> v, w, st;
		int l = p;
		while(1) {
			int t = 1;
			st.push_back(p);
			while(p <= N && A[p] > 1) {
				if(t <= 1000000) t *= A[p];
				p++;
			}
			v.push_back(t);

			if(p > N) break;

			if(A[p] == 0) { ans[p - 1] = '+'; break; }
			int cnt = 0;
			while(p <= N && A[p] == 1) {
				cnt++; p++;
			}
			w.push_back(cnt);
			if(p > N) break;
			if(A[p] == 0) { ans[p - 1] = '+'; break; }
		}

		int tmp = p - 1;
		if(v.size() == w.size()) {
			while(tmp > 0 && A[tmp] == 1) {
				ans[tmp - 1] = '+';
				tmp--;
			}
			w.pop_back();
		}

		ll tot = 1;
		for(int i : v) {
			if(tot <= 1000000) tot *= i;
		}
		if(tot > 1000000) {
			for(int i = l; i < tmp; i++) ans[i] = '*';
			continue;
		}

		// printf("%lld\n", tot);
		// printf("%d\n", p);

		M = v.size();
		for(int i = 0; i < M; i++) D[i] = path[i] = 0;
		D[0] = v[0]; path[0] = -1;

		for(int i = 1; i < M; i++) {
			int mult = v[i];
			path[i] = i - 1;
			for(int j = i; j > 0; j--) {
				if(D[i] < mult + w[j - 1] + D[j - 1]) {
					D[i] = mult + w[j - 1] + D[j - 1];
					path[i] = j - 1;
				}
				mult *= v[j - 1];
			}
			if(D[i] < mult) { D[i] = mult; path[i] = -1; }
		}

		int q = M - 1;
		while(q >= 0) {
			int nxt = path[q];
			for(int i = st[nxt + 1]; i < tmp; i++) {
				ans[i] = '*';
			}
			if(nxt >= 0) {
				tmp = st[nxt + 1] - 1;
				for(int i = 0; i <= w[nxt]; i++) {
					ans[tmp] = '+';
					tmp--;
				}
				tmp++;
				q = nxt;
			}
			else break;
		}
	}

	for(int i = 1; i < N; i++) printf("%d%c", A[i], ans[i]);
	printf("%d\n", A[N]);

	return 0;
}