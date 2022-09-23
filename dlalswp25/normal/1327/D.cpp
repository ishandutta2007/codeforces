#include <bits/stdc++.h>

using namespace std;

int N;
int P[202020];
int C[202020];
bool vst[202020];
vector<int> v;

vector<int> divs[202020];

int main() {
	for(int i = 1; i <= 200000; i++) {
		for(int j = i; j <= 200000; j += i) {
			divs[j].push_back(i);
		}
	}

	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &P[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &C[i]);

		int ans = N;

		for(int i = 1; i <= N; i++) {
			if(vst[i]) continue;
			int x = i;
			int sz = 0;
			while(!vst[x]) {
				v.push_back(C[x]);
				vst[x] = true;
				x = P[x];
				sz++;
			}

			for(int j : divs[sz]) {
				for(int k = 0; k < j; k++) {
					bool ok = true;
					for(int l = k + j; l < sz; l += j) {
						if(v[l] != v[l - j]) ok = false;
					}
					if(ok) ans = min(ans, j);
				}
			}

			v.clear();
		}
		printf("%d\n", ans);

		for(int i = 1; i <= N; i++) vst[i] = false;
	}
	return 0;
}