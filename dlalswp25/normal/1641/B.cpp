#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[505];
int tmp[505];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		map<int, int> mp;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			mp[A[i]]++;
		}

		bool ok = true;
		for(auto& i : mp) {
			if(i.second & 1) ok = false;
		}
		if(!ok) { puts("-1"); continue; }

		vector<pii> qs;
		vector<int> ans;
		for(int i = N; i >= 1; ) {
			int j = i - 1;
			while(j >= 1 && A[j] != A[i]) j--;
			assert(j);

			int p = j - 1;
			for(int k = i - 1; k > j; k--) {
				qs.emplace_back(p, A[k]);
				p++;
				tmp[p] = A[k];
			}
			for(int k = j; k <= i - 2; k++) A[k] = tmp[k];
			ans.push_back(2 * (i - j));
			i -= 2;
		}
		printf("%d\n", qs.size());
		for(auto& i : qs) printf("%d %d\n", i.first, i.second);
		reverse(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}