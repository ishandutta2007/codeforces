#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int nz = 0;
		for(int i = 1; i <= N; i++) nz += (A[i] != 0);
		if(nz & 1) { puts("-1"); continue; }

		vector<pii> ans;
		int p = 1;
		while(p <= N && A[p] == 0) {
			ans.emplace_back(p, p); p++;
		}

		while(p <= N) {
			int np = p;
			vector<int> v;
			while(np <= N) {
				if(A[np] != 0) {
					if(v.size() >= 2) break;
					v.push_back(np);
				}
				np++;
			}

			if((v[0] + (A[v[0]] == 1)) % 2 == (v[1] + (A[v[1]] == 1)) % 2) {
				ans.emplace_back(v[0], v[0]);
				ans.emplace_back(v[0] + 1, np - 1);
			}
			else {
				if(!ans.size()) ans.emplace_back(v[0], np - 1);
				else ans.back().second = np - 1;
			}

			p = np;
		}
		printf("%d\n", ans.size());
		for(pii i : ans) printf("%d %d\n", i.first, i.second);
	}
	return 0;
}