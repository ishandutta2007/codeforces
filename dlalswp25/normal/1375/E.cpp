#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[1010];
vector<pii> v;
vector<pii> ans;

void put(int u, int v) {
	if(u > v) swap(u, v);
	ans.emplace_back(u, v);
	swap(A[u], A[v]);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = N; i >= 1; i--) {
		v.clear();
		for(int j = 1; j < i; j++) {
			if(A[j] > A[i]) v.emplace_back(A[j], j);
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		int tmp = A[i];

		// for(pii j : v) printf("%d %d : %d\n", j.first, j.second, i);
		for(int j = 0; j < v.size(); j++) {
			put(v[j].second, i);
			if(j == 0) {
				cnt = 1;
				for(int k = v[j].second + 1; k < i; k++) {
					if(A[k] == tmp) put(v[j].second, k);
				}
			}
			else {
				if(v[j].first == v[j - 1].first) cnt++;
				else {
					if(cnt >= 2) {
						for(int k = j - 1; k > j - cnt && v[k].first == v[j - 1].first; k--) {
							if(v[k].second < v[j].second) break;
							put(v[j].second, v[k].second);
						}
					}
					cnt = 1;
				}
			}
		}
	}

	printf("%d\n", ans.size());
	for(pii i : ans) printf("%d %d\n", i.first, i.second);
	return 0;
}