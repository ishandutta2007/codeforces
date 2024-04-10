#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int L[101010];
int R[101010];
int C[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		map<pii, int> mp;
		set<pii> vl, vr;

		int lft = 1010101010, rgt = 0;

		for(int i = 1; i <= N; i++) {
			scanf("%d%d%d", &L[i], &R[i], &C[i]);
			pii p = {L[i], R[i]};
			if(mp.find(p) == mp.end()) mp[p] = C[i];
			else mp[p] = min(mp[p], C[i]);

			lft = min(lft, L[i]);
			rgt = max(rgt, R[i]);
			p = {lft, rgt};

			vl.insert({L[i], C[i]});
			vr.insert({-R[i], C[i]});

			int ans = vl.begin()->second + vr.begin()->second;
			if(mp.find(p) != mp.end()) {
				ans = min(ans, mp[p]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}