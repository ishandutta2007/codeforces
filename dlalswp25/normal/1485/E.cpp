#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1010101010;

int N, mx;
ll A[202020];
ll D[202020];
vector<int> adj[202020];
vector<int> vs[202020];
int dep[202020];
ll mxP[202020];
ll mxM[202020];
ll mxA[202020];
ll mnA[202020];

void dfs(int v, int p) {
	dep[v] = dep[p] + 1;
	mx = max(mx, dep[v]);
	for(int i : adj[v]) {
		if(i != p) dfs(i, v);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 2; i <= N; i++) {
			int x; scanf("%d", &x);
			adj[x].push_back(i);
			adj[i].push_back(x);
		}
		for(int i = 2; i <= N; i++) scanf("%lld", &A[i]);
		dfs(1, 0);
		for(int i = 1; i <= mx; i++) vs[i].clear();
		for(int i = 1; i <= N; i++) vs[dep[i]].push_back(i);
		for(int i = 1; i <= mx; i++) { mxP[i] = mxM[i] = mxA[i] = -INF; mnA[i] = INF; }
		for(int i = 1; i <= N; i++) D[i] = 0;

		for(int i : vs[mx]) {
			D[i] = 0;
			mxP[mx] = max(mxP[mx], D[i] + A[i]);
			mxM[mx] = max(mxM[mx], D[i] - A[i]);
			mxA[mx] = max(mxA[mx], A[i]);
			mnA[mx] = min(mnA[mx], A[i]);
		}
		for(int i = mx - 1; i >= 1; i--) {
			for(int j : vs[i]) {
				ll tmn = INF, tmx = -INF;
				for(int x : adj[j]) {
					if(dep[x] < dep[j]) continue;
					tmn = min(tmn, A[x]); tmx = max(tmx, A[x]);
					D[j] = max(D[j], D[x] + max(abs(mnA[i + 1] - A[x]), abs(mxA[i + 1] - A[x])));
				}
				D[j] = max(D[j], max(mxP[i + 1] - tmn, mxM[i + 1] + tmx));
				mxP[i] = max(mxP[i], D[j] + A[j]);
				mxM[i] = max(mxM[i], D[j] - A[j]);
				mxA[i] = max(mxA[i], A[j]);
				mnA[i] = min(mnA[i], A[j]);
			}
		}
		printf("%lld\n", D[1]);
	}
	return 0;
}