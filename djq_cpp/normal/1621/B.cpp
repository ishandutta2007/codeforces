#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve()
{
	int n, mn = INF, mx = -1;
	int vn = INF, vx = INF, vnx = 2 * INF;
	scanf("%d", &n);
	rep(i, n) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		if(mn > l) {
		    mn = l; vn = INF; vnx = 2 * INF;
		}
		if(mx < r) {
		    mx = r; vx = INF; vnx = 2 * INF;
		}
		if(mn == l) vn = min(vn, c);
		if(mx == r) vx = min(vx, c);
		if(mn == l && mx == r) vnx = min(vnx, c);
		printf("%d\n", min(vn + vx, vnx));
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0; 
}