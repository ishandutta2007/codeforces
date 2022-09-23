#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
char S[101010];
char T[101010];
int cnt[101010][2];
ll x, y;

vector<int> v;

int main() {
	scanf("%s", S + 1);
	N = strlen(S + 1);
	scanf("%lld%lld", &x, &y);

	ll ans = 1LL << 60;

	for(int i = 1; i <= N; i++) {
		T[i] = S[i];
		if(T[i] == '?') {
			T[i] = '0';
			v.push_back(i);
		}
	}

	for(int i = 1; i <= N; i++) {
		cnt[i][0] = cnt[i - 1][0];
		cnt[i][1] = cnt[i - 1][1];
		cnt[i][T[i] - '0']++;
	}

	int t0 = cnt[N][0], t1 = cnt[N][1];

	int M = v.size();
	ll cur = 0;
	for(int i = 1; i <= N; i++) {
		if(T[i] == '0') cur += cnt[i - 1][1] * y;
		else cur += cnt[i - 1][0] * x;
	}

	ans = cur;

	if(x <= y) {
		for(int i = M - 1; i >= 0; i--) {
			int w = v[i];
			cur -= cnt[w - 1][1] * y;
			cur -= (t1 - cnt[w][1] + (M - 1 - i)) * x;
			cur += cnt[w - 1][0] * x;
			cur += (t0 - cnt[w][0] - (M - 1 - i)) * y;
			ans = min(ans, cur);
		}
	}
	else {
		for(int i = 0; i < M; i++) {
			int w = v[i];
			cur -= (cnt[w - 1][1] + i) * y;
			cur -= (t1 - cnt[w][1]) * x;
			cur += (cnt[w - 1][0] - i) * x;
			cur += (t0 - cnt[w][0]) * y;
			ans = min(ans, cur);
		}
	}
	printf("%lld\n", ans);

	return 0;
}