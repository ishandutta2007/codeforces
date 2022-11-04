#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M, K;
vector<int> nei[200005], nee[200005];
int dis[200005];
vector<pair<int, int> > egs;
char res[200005];

void bfs(int now) {
	queue<int> q;
	q.push(1);
	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	while (SZ(q)) {
		int now = q.front(); q.pop();
		for (int to : nei[now]) {
			if (!~dis[to]) {
				dis[to] = dis[now] + 1;
				q.push(to);
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	repi(i, M) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].push_back(v);
		nei[v].push_back(u);
		egs.push_back(make_pair(u, v));
	}
	bfs(1);
	ll sm = 1;
	rep(i, M) {
		int u, v; tie(u, v) = egs[i];
		if (dis[u] == dis[v] + 1) nee[u].push_back(i);
		if (dis[v] == dis[u] + 1) nee[v].push_back(i);
	}
	for (int i = 2; i <= N; ++i) {
		sm *= SZ(nee[i]);
		if (sm > K) sm = K;
	}
	printf("%lld\n", sm);
	rep(i, K) {
		rep(i, M) res[i] = '0';
		int nk = i;
		for (int j = 2; j <= N; ++j) {
			int jz = SZ(nee[j]);
			res[nee[j][nk % jz]] = '1';
			nk /= jz;
		}
		if (nk) break;
		printf("%s\n", res);
	}
	return 0;
}