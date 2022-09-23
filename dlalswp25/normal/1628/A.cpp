#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[202020];
int cnt[202020];
bool chk[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i <= N; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mx = N + 1;
		for(int i = 1; i <= N; i++) cnt[A[i]]++;
		for(int i = 0; i <= N; i++) {
			if(!cnt[i]) {
				mx = i; break;
			}
		}
		vector<int> ans;
		for(int i = 0; i <= N; i++) chk[i] = false;
		int t = 0;
		int nxt = mx;
		for(int i = 1; i <= N; i++) {
			if(!mx) {
				ans.push_back(0); continue;
			}
			if(A[i] > mx) continue;
			if(!chk[A[i]]) {
				chk[A[i]] = true;
				t++;
			}
			cnt[A[i]]--;
			if(!cnt[A[i]]) nxt = min(nxt, A[i]);
			if(t == mx) {
				ans.push_back(mx);
				for(int j = 0; j <= mx; j++) chk[j] = false;
				mx = nxt;
				t = 0;
			}
		}
		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}