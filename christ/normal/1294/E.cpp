#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e6+2, MOD = 1e9+7, LOG = 15, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
int shift[MN];
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	vector<vector<int>> a(n+2,vector<int>(m+2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf ("%d",&a[i][j]);
		}
	}
	int ret = 0;
	for (int j = 1; j <= m; j++) {
		for (int i = 0; i <= n; i++) shift[i] = 0;
		for (int i = 1; i <= n; i++) if (a[i][j]%m == j%m) {
			int have = (a[i][j]-j)/m+1;
			if (have > n) continue;
			int go = (i-have+n)%n;
			++shift[go];
		}
		int mn = 1e9;
		for (int go = 0; go <= n-1; go++) mn = min(mn,n - shift[go] + go);
		ret += mn;
	}
	printf ("%d\n",ret);
    return 0;
}