#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
vector<int> nei[1005];
vector<pair<int, int> > aes;
int dis[2][1005], mxd, mxp;
bool lgl[1005];
vector<int> nds;

void dfs(int now, int lst, int did) {
	if (!~lst) dis[did][now] = 0;
	if (mxd < dis[did][now]) mxd = dis[did][now], mxp = now;
	lgl[now] = 1; nds.push_back(now);
	for (int to : nei[now]) {
		if (to == lst) continue;
		dis[did][to] = dis[did][now] + 1;
		dfs(to, now, did);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].push_back(v); nei[v].push_back(u);
	}
	vector<pair<int, int> > zx;
	for (int i = 1; i <= N; ++i) if (!lgl[i]) {
		nds.clear();
		mxd = -1; dfs(i, -1, 0);
		nds.clear();
		mxd = -1; dfs(mxp, -1, 1);
		int d = (mxd + 1) / 2;
		dfs(mxp, -1, 0);
		for (int to : nds) if (dis[0][to] == d && dis[1][to] == mxd / 2) {
			zx.emplace_back(d, to);
			break;
		}
	}
	sort(zx.begin(), zx.end());
	for (int i = 0; i < SZ(zx) - 1; ++i) {
		aes.emplace_back(zx[i].second, zx.back().second);
		nei[zx[i].second].push_back(zx.back().second);
		nei[zx.back().second].push_back(zx[i].second);
	}
	mxd = -1;
	dfs(1, -1, 0);
	mxd = -1;
	dfs(mxp, -1, 0);
	printf("%d\n", mxd);
	for (auto &it : aes) printf("%d %d\n", it.first, it.second);
	return 0;
}