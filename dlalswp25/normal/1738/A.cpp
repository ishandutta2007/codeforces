#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];
int B[101010];
vector<int> V[2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		V[0].clear();
		V[1].clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		for(int i = 1; i <= N; i++) {
			V[A[i]].push_back(B[i]);
		}
		sort(V[0].begin(), V[0].end());
		sort(V[1].begin(), V[1].end());
		ll ans = 0;
		for(int z = 0; z < 2; z++) {
			vector<int> tmp[2];
			tmp[0] = V[0]; tmp[1] = V[1];
			int cur = z;
			if(!tmp[cur].size()) continue;
			ll sum = tmp[cur][0];
			vector<int> v; v.push_back(cur);
			tmp[cur].erase(tmp[cur].begin());
			cur = 1 - cur;

			while(tmp[0].size() || tmp[1].size()) {
				if(!tmp[cur].size()) { cur = 1 - cur; continue; }
				if(v.size() && v.back() != cur) sum += tmp[cur].back() * 2;
				else sum += tmp[cur].back();
				tmp[cur].pop_back();
				v.push_back(cur);
				cur = 1 - cur;
			}
			ans = max(ans, sum);
		}
		printf("%lld\n", ans);
	}
	return 0;
}