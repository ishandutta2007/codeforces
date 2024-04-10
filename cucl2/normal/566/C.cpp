#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int w[200005];
vector<pair<int, int> > nei[200005];
int siz[200005], mxs[200005];
bool ban[200005];
vector<int> nds;
int ansp;
double ansv;

void predfs(int now, int lst) {
	siz[now] = 1;
	mxs[now] = 0;
	nds.push_back(now);
	for (auto &it : nei[now]) {
		int to = it.first;
		if (to == lst || ban[to]) continue;
		predfs(to, now);
		siz[now] += siz[to];
		mxs[now] = max(mxs[now], siz[to]);
	}
}

double calc(int now, int lst, int dep, bool cal) {
	double ans = w[now] * sqrt(dep) * (cal ? dep : 1);
	for (auto &it : nei[now]) {
		int to = it.first;
		if (to == lst) continue;
		ans += calc(to, now, dep + it.second, cal);
	}
	return ans;
}

void fendge(int now) {
	nds.clear();
	predfs(now, -1);
	int _rt = now;
	for (int to : nds) {
		mxs[to] = max(mxs[to], siz[now] - siz[to]);
		if (mxs[to] < mxs[_rt]) _rt = to;
	}
	now = _rt;
	double mxres = -1e18;
	int mxid = -1;
	for (auto &it : nei[now]) {
		int to = it.first;
		if (ban[to]) continue;
		double res = calc(to, now, it.second, 0);
		if (res > mxres) {
			mxres = res;
			mxid = to;
		}
	}
	double nres = calc(now, -1, 0, 1);
	if (nres < ansv) {
		ansv = nres;
		ansp = now;
	}
	ban[now] = 1;
	if (~mxid) fendge(mxid);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", w + i);
	for (int i = 1; i < N; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		nei[u].emplace_back(v, w);
		nei[v].emplace_back(u, w);
	}
	ansv = 1e45;
	fendge(1);
	printf("%d %.10lf\n", ansp, ansv);
	return 0;
}