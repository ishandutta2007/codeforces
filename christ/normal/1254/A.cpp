#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
char grid[105][105];
char ret[105][105];
char place (int which) {
	return which <= 9 ? which + '0' : (which <= 35 ? which-10+'a' : which-36+'A');
}
void solve () {
	int n,m,k;
	scanf ("%d %d %d",&n,&m,&k); int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf ("%s",grid[i]+1);
		for (int j = 1; j <= m; j++) cnt += grid[i][j] == 'R';
	}
	int mn = cnt/k, extra = cnt%k, which = 0, cur = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i&1?1:m; i&1?j<=m:j>=1; i&1?j++:j--) {
			cur += grid[i][j] == 'R';
			ret[i][j] = place(which);
			if (cur == mn + (which < extra)) {
				++which;
				which = min(which,k-1);
				cur = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++, putchar(10))
		for (int j = 1; j <= m; j++)
			putchar(ret[i][j]);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}