#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, A, B, C;
char S[101010];
int one, zero;
vector<pii> zeros;
ll ans;

void gen() {
	one = zero = 0;
	zeros.clear();
	for(int i = 1; i <= N; i++) {
		if(S[i] == '1' && S[i - 1] == '1') one++;
		if(S[i] == '0' && S[i - 1] == '0') zero++;
	}

	int l = 1;
	while(l <= N && S[l] == '0') l++;
	if(l > N) { zeros.emplace_back(N, 0); return; }
	int r = N;
	while(S[r] == '0') r--;

	int i = l;
	while(i <= r) {
		if(S[i] == '1') { i++; continue; }
		for(int j = i; ; j++) {
			if(S[j] == '1') {
				zeros.emplace_back(j - i, 1);
				i = j;
				break;
			}
		}
	}

	sort(zeros.begin(), zeros.end());
	if(l > 1) zeros.emplace_back(l - 1, 0);
	if(r < N) zeros.emplace_back(N - r, 0);
}

void work(int turn) {
	int p = 0;
	ll cur = 0;
	while(1) {
		ll tmp = (ll)(A + B) * min(zero, one);
		if(turn == 0 && zero > one) tmp += A;
		if(turn == 1 && one > zero) tmp += B;
		ans = max(ans, cur + tmp);

		if(turn == 0) {
			while(p < zeros.size() && zeros[p].first == 0) p++;
			if(p >= zeros.size()) break;
			if(zeros[p].first == 1) {
				cur -= C;
				one += zeros[p].second;
				p++;
			}
			else {
				cur += A;
				zeros[p].first--;
				zero--;
			}
		}
		else {
			if(!one) break;
			cur += B;
			one--;
		}
		ans = max(ans, cur);
		turn = 1 - turn;
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%d", &N, &A, &B, &C);
		scanf("%s", S + 1);

		gen();

		ans = 0;
		work(0);

		gen();
		work(1);

		printf("%lld\n", ans);
	}
	return 0;
}