#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(2222);
int n, m;
long long bt[N][N];
void inc(int x, int y, int delta) {
	for(int i(x); i <= n; i += i & -i) {
		for(int j(y); j <= m; j += j & -j) {
			bt[i][j] += delta;
		}
	}
}
long long getSum(int x, int y) {
	long long res(0);
	for(int i(x); i; i -= i & -i) {
		for(int j(y); j; j -= j & -j) {
			res += bt[i][j];
		}
	}
	return res;
}
int main() {
	int k;
	scanf("%d%d%d", &n, &m, &k);
	static vector<pair<pair<int, int>, int> > g[N];
	for(int i(1); i <= k; i++) {
		int len;
		scanf("%d", &len);
		for(int j(0); j < len; j++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			g[i].push_back(make_pair(make_pair(x, y), z));
		}
	}
	int Q;
	static int x1[N], y1[N], x2[N], y2[N];
	int nq(0);
	static int stt[N], q[N][N];
	static long long ans[N];
	scanf("%d", &Q);
	for(int i(1); i <= k; i++) {
		stt[i] = 1;
	}
	static char st[111];
	for(int i(1); i <= Q; i++) {
		scanf("%s", st);
		if(!strcmp(st, "SWITCH")) {
			int x;
			scanf("%d", &x);
			stt[x] ^= 1;
		}else {
			++nq;
			scanf("%d%d%d%d", &x1[nq], &y1[nq], &x2[nq], &y2[nq]);

			memcpy(q[nq], stt, sizeof(stt));
		}
	}
	for(int i(1); i <= k; i++) {
		for(int j(0); j < (int)g[i].size(); j++) {
			inc(g[i][j].first.first, g[i][j].first.second, g[i][j].second);
		}
		for(int j(1); j <= nq; j++) {
			if(q[j][i]) {
				ans[j] += getSum(x2[j], y2[j]) - getSum(x1[j] - 1, y2[j]) - getSum(x2[j], y1[j] - 1) + getSum(x1[j] - 1, y1[j] - 1);
			}
		}
		for(int j(0); j < (int)g[i].size(); j++) {
			inc(g[i][j].first.first, g[i][j].first.second, -g[i][j].second);
		}
	}
	for(int i(1); i <= nq; i++) {
		printf("%I64d\n", ans[i]);
	}
}