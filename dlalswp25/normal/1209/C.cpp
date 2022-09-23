#include <bits/stdc++.h>

using namespace std;

int T;
char S[202020];
vector<int> v[11];
int ans[202020];

int main() {
	scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 0; i < 10; i++) v[i].clear();
		
		scanf("%s", S + 1);
		for(int i = 1; i <= N; i++) {
			v[S[i] - '0'].push_back(i);
			ans[i] = 0;
		}

		int mx = 0;
		for(int i = 0; i < 10; i++) {
			bool ok = true;
			for(int j : v[i]) {
				if(j < mx) { ok = false; continue; }
				ans[j] = 1;
			}
			for(int j : v[i]) { mx = max(mx, j); }

			if(!ok) break;
		}

		mx = 0;
		bool ok = true;
		for(int j = 1; j <= N; j++) {
			if(ans[j]) continue;
			if(mx > S[j]) ok = false;
			mx = max(mx, (int)S[j]);
		}
		if(!ok) puts("-");
		else {
			for(int j = 1; j <= N; j++) printf(ans[j] ? "1" : "2"); puts("");
		}
	}
	return 0;
}