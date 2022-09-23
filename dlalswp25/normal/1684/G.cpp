#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int A[1010];
bool chk[1010];
vector<pair<ll, ll>> ans;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);
	for(int i = N; i >= 1; i--) {
		if(chk[i]) continue;
		bool ok = false;
		for(int j = i - 1; j >= 1; j--) {
			if(chk[j]) continue;
			if(A[i] % A[j]) continue;
			if((ll)A[i] * 2 + A[j] > M) continue;
			if(A[i] == A[j]) continue;
			ans.emplace_back((ll)A[i] * 2 + A[j], A[i] + A[j]);
			chk[j] = true;
			ok = true; break;
		}
		if(!ok) {
			if((ll)A[i] * 3 > M) { puts("-1"); return 0; }
			ans.emplace_back((ll)A[i] * 3, A[i] * 2);
		}
	}
	printf("%d\n", ans.size());
	for(auto& i : ans) printf("%lld %lld\n", i.first, i.second);
	return 0;
}