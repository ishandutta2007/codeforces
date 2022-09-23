#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int A[202020];
vector<int> vl[202020];
vector<int> vr[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &L, &R);
		for(int i = 1; i <= N; i++) {
			vl[i].clear(); vr[i].clear();
		}
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(i <= L) vl[A[i]].push_back(i);
			else vr[A[i]].push_back(i);
		}
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			while(vl[i].size() && vr[i].size()) {
				vl[i].pop_back();
				vr[i].pop_back();
				L--; R--;
			}
		}

		if(L > R) {
			int t = 0;
			for(int i = 1; i <= N; i++) t += vl[i].size() / 2;
			ans += (R + L) / 2;
			if(t * 2 < L - R) ans += (L - R - t * 2) / 2;
		}
		else {
			int t = 0;
			for(int i = 1; i <= N; i++) t += vr[i].size() / 2;
			ans += (R + L) / 2;
			if(t * 2 < R - L) ans += (R - L - t * 2) / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}