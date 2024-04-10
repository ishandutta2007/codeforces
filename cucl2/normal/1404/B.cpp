/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n, a, b, A, B;
vector<int> nei[1 << 17];
int dep[1 << 17], mxdep, mxpos;

void dfs(int now, int lst) {
	dep[now] = dep[lst] + 1; mxdep = max(mxdep, dep[now]); if(dep[now] == mxdep) mxpos = now;
	loop(i, SZ(nei[now])) if(nei[now][i] != lst) dfs(nei[now][i], now);
}

void solve() {
	scanf("%d%d%d%d%d", &n, &a, &b, &A, &B); mxdep = 0;
	cont(i, n) nei[i].clear();
	cont(i, n - 1) {
		int a, b; scanf("%d%d", &a, &b);
		nei[a].pub(b); nei[b].pub(a);
	}
	if(A * 2 >= B) return void(puts("Alice"));
	dep[0] = -1; dfs(b, 0);
	if(dep[a] <= A) return void(puts("Alice"));
	dfs(mxpos, 0); if(mxdep <= A * 2) return void(puts("Alice"));
	puts("Bob");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}