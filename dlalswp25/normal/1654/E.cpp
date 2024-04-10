#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int MX = 100000;
const int BSZ = 350;
const int OFFSET = BSZ * MX;

int N;
int A[101010];
pii cnt[35353535];
pii cnt2[101010];

int solve() {
	for(int i = 0; i < 35353535; i++) cnt[i] = {0, 0};
	int id = 1;
	int ret = 0;
	for(int i = 0; i <= BSZ; i++) {
		for(int j = 1; j <= N; j++) {
			int t = A[j] - i * j + OFFSET;
			if(cnt[t].first != id) cnt[t] = {id, 1};
			else cnt[t].second++;
			ret = max(ret, cnt[t].second);
		}
		id++;
	}

	for(int i = 0; i <= MX; i++) cnt2[i] = {0, 0};
	id = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = i - 1; j >= i - BSZ; j--) {
			if(j <= 0) break;
			if(A[j] > A[i]) continue;
			if((A[i] - A[j]) % (i - j)) continue;
			int t = (A[i] - A[j]) / (i - j);
			if(cnt2[t].first != id) cnt2[t] = {id, 1};
			else cnt2[t].second++;
			ret = max(ret, cnt2[t].second + 1);
		}
		for(int j = i + 1; j <= i + BSZ; j++) {
			if(j > N) break;
			if(A[j] < A[i]) continue;
			if((A[j] - A[i]) % (j - i)) continue;
			int t = (A[j] - A[i]) / (j - i);
			if(cnt2[t].first != id) cnt2[t] = {id, 1};
			else cnt2[t].second++;
			ret = max(ret, cnt2[t].second + 1);
		}
		id++;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	int ans = solve();
	for(int i = 1; i <= N; i++) A[i] = MX + 1 - A[i];
	ans = max(ans, solve());
	printf("%d\n", N - ans);
	return 0;
}