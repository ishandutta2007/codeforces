#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[202020];
vector<int> v[202020];
set<int> H, L;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);

		vector<int> w;

		H.clear(); L.clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			w.push_back(A[i]);
			H.insert(i);
		}

		sort(w.begin(), w.end());
		w.erase(unique(w.begin(), w.end()), w.end());
		for(int i = 1; i <= N; i++) A[i] = lower_bound(w.begin(), w.end(), A[i]) - w.begin() + 1;

		M = w.size();
		for(int i = 1; i <= M + 1; i++) v[i].clear();
		for(int i = 1; i <= N; i++) v[A[i]].push_back(i);

		bool ok = false;
		int x, y, z;

		for(int i = 1; i <= M; i++) {
			for(int j : v[i - 1]) L.insert(j);
			for(int j : v[i]) H.erase(j);

			if(v[i].size() > 2) {
				if(i == M) {
					x = v[i][1] - 1; y = 1; z = N - v[i][1];
					ok = true;
					break;
				}

				int l = *H.begin(), r = *(--H.end());
				auto it = lower_bound(v[i].begin(), v[i].end(), l);

				bool in = false;
				if(it != v[i].end() && *it < r) {
					in = true;
				}

				int lft = it - v[i].begin();
				it = lower_bound(v[i].begin(), v[i].end(), r);
				int rgt = v[i].end() - it;

				if(!lft || !rgt) continue;

				auto it2 = L.lower_bound(l);
				if(it2 != L.end() && *it2 < r) continue;

				if(in) {
					x = l - 1; y = r - l + 1; z = N - r;
					ok = true;
					break;
				}

				bool fl = false, fr = false;
				if(lft >= 2 && A[l - 1] == i) fl = true;
				if(rgt >= 2 && A[r + 1] == i) fr = true;
				if(!fl && !fr) continue;
				else if(fl) { x = l - 2; y = r - l + 2; z = N - r; ok = true; }
				else { x = l - 1; y = r - l + 2; z = N - r - 1; ok = true; }
			}

			if(ok) break;
		}
		if(!ok) puts("NO");
		else printf("YES\n%d %d %d\n", x, y, z);
	}
	return 0;
}