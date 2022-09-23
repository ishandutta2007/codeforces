#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
pii A[202020];
pii ans[202020];
bool vst[202020];
queue<int> q;
map<pii, int> mp;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i].first, &A[i].second);
		mp[A[i]] = i;
	}

	for(int i = 1; i <= N; i++) {
		int x, y; tie(x, y) = A[i];
		for(int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if(!mp[{nx, ny}]) {
				vst[i] = true;
				ans[i] = {nx, ny};
				q.push(i);
			}
		}
	}

	while(q.size()) {
		int i = q.front(); q.pop();
		int x, y; tie(x, y) = A[i];
		for(int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			int t = mp[{nx, ny}];
			if(!t || vst[t]) continue;
			vst[t] = true;
			ans[t] = ans[i];
			q.push(t);
		}
	}

	for(int i = 1; i <= N; i++) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}