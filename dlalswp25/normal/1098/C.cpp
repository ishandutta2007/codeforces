#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll s, ll e) {
	return e * (e + 1) / 2 - s * (s - 1) / 2;
}

int num[100005];
vector<int> V[100005];

int main() {
	ll N, S; scanf("%lld%lld", &N, &S);
	if(S < N) {
		puts("No"); return 0;
	}
	S -= N;

	if(S > N * (N - 1) / 2 || S < N - 1) {
		puts("No");
		return 0;
	}

	if(S == N * (N - 1) / 2) {
		puts("Yes");
		for(int i = 2; i <= N; i++) printf("%d ", i - 1); puts("");
		return 0;
	}

	int b;

	for(b = 2; b <= N - 1; b++) {
		ll s = 0;
		ll t = 1;
		ll tmp = 0;
		for(int i = 1; ; i++) {
			t = t * b;
			if(t + tmp >= N - 1) {
				s += i * (N - 1 - tmp);
				break;
			}
			s += i * t;
			tmp += t;
		}
		if(s <= S) break;
	}

	int lft = N - 1;
	num[0] = 1;

	for(int i = 1; i <= N - 1; i++) {
		if(lft == 0) break;
		ll j = 1;
		for(; j <= lft && j <= num[i - 1] * b; j++) {
			if(i * j + f(i + 1, (i + 1) + (lft - j) - 1) < S) break;
		}
		j--;
		num[i] = j; S -= i * j; lft -= j;
	}
	puts("Yes");

	V[0].push_back(1);
	int ID = 2;
	for(int i = 1; i <= N; i++) {
		int p = 0;
		int cnt = 0;
		for(int j = 0; j < num[i]; j++) {
			printf("%d ", V[i - 1][p]); cnt++;
			if(cnt >= b) { cnt = 0; p++; }
			V[i].push_back(ID); ID++;
		}
	}
	puts("");

	return 0;
}