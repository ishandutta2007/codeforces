#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, p[200005];
vector<int> a[200005];
bool cmp(int i, int j)
{
	rep(k, n) if(a[k][i] != a[k][j]) return a[k][i] < a[k][j];
	return i < j;
}

void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) {
		a[i].resize(m);
		rep(j, m) scanf("%d", &a[i][j]);
	}
	rep(i, m) p[i] = i;
	sort(p, p + m, cmp);
	int l = -1, r = -1;
	rep(i, m) if(p[i] != i) {
		if(l == -1) l = i; r = i;
	}
	rep(i, m) p[i] = i;
	if(l == -1) l = r = 0;
	swap(p[l], p[r]);
	rep(i, m - 1) rep(j, n) if(a[j][p[i]] > a[j][p[i + 1]]) {
		printf("-1\n"); return;
	}
	printf("%d %d\n", l + 1, r + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}