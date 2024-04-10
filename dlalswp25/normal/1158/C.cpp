#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int A[505050];
vector<pii> V;
int ans[505050];

int F[505050];
int N;

void upd(int x) {
	//printf("%d upd\n", x);
	for(int i = x; i <= N; i += i&-i) F[i]++;
}
int query(int x) {
	int ret = 0;
	for(int i = x; i; i -= i&-i) ret += F[i];
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		V.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) ans[i] = -1;
		for(int i = 1; i <= N; i++) F[i] = 0;
		bool ok = true;
		for(int i = 1; i <= N; i++) if(A[i] != -1 && A[i] <= i) ok = false;
		if(!ok) {
			puts("-1");
			continue;
		}
		for(int i = 1; i <= N; i++) V.push_back({A[i], -i});
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());

		int id = N;
		for(int i = 0; i < V.size(); i++) {
			//for(int j = 1; j <= N; j++) printf("%d ", ans[j]); puts("");
			if(V[i].first != -1 && query(V[i].first - 1) - query((-V[i].second)) > 0) ok = false;
			if(V[i].first == N + 1) {
				ans[-V[i].second] = id; id--;
				upd(-V[i].second);
				continue;
			}
			if(V[i].first != -1 && ans[V[i].first] == -1) {
				ans[V[i].first] = id; id--;
				upd(V[i].first);
			}
			if(ans[-V[i].second] != -1) continue;
			ans[-V[i].second] = id; id--;
			upd(-V[i].second);
		}
		if(!ok) { puts("-1"); continue; }
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}