#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int M = 17;
int n, m, a[100005][5], w[100005], mask[100005], f[500005], ans = INT_MAX;
int mx[131072];
vector<int> chv;

uniform_int_distribution<int> dis(0, M - 1);
mt19937 rng(time(0));

void solve()
{
	rep(i, chv.size()) f[i] = dis(rng);
	rep(i, 1 << M) mx[i] = INF;
	rep(i, n) {
		mask[i] = 0;
		rep(j, m) mask[i] |= 1 << f[a[i][j]];
		mx[mask[i]] = min(mx[mask[i]], w[i]);
	}
	rep(i, M) rep(j, 1 << M) if(j >> i & 1) mx[j] = min(mx[j], mx[j ^ 1 << i]);
	rep(i, n) {
		int cur = mx[(1 << M) - 1 - mask[i]];
		if(cur != INF) ans = min(ans, cur + w[i]);
	}
}

int main()
{
	double beg = clock();
	scanf("%d%d", &n, &m);
	rep(i, n) {
		rep(j, m) scanf("%d", &a[i][j]); scanf("%d", &w[i]);
	}
	rep(i, n) rep(j, m) chv.push_back(a[i][j]);
	sort(chv.begin(), chv.end());
	chv.resize(unique(chv.begin(), chv.end()) - chv.begin());
	rep(i, n) rep(j, m) a[i][j] = lower_bound(chv.begin(), chv.end(), a[i][j]) - chv.begin();
	
	while((clock() - beg) / CLOCKS_PER_SEC <= 2) solve();
	printf("%d\n", ans == INT_MAX ? -1 : ans);
	return 0;
}