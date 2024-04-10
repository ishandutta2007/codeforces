/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
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

#define Nope return puts("0")
int n, k;
vector<int> nei[1 << 19], hv[1 << 19];
int p[1 << 19];
int pre[1 << 19], suc[1 << 19];
int ch[1 << 19], id[1 << 19], cid;
int deg[1 << 19];

int main() {
	scanf("%d%d", &n, &k);
	cont(i, n) scanf("%d", p + i);
	cont(i, k) {
		int u, v; scanf("%d%d", &u, &v);
		if(pre[v] || suc[u]) Nope;
		else pre[v] = u, suc[u] = v;
	}
	cont(i, n) if(!pre[i]) {
		int now = i, cnt = 0; ++cid;
		while(now) {
			if(ch[now]) Nope;
			hv[cid].pub(now);
			ch[now] = cid;
			id[now] = ++cnt;
			now = suc[now];
		}
	}
	cont(i, n) if(!ch[i]) Nope;
	int rt;
	cont(i, n) {
		if(!p[i]) {
			if(pre[i]) Nope;
			rt = ch[i];
		} else {
			if(ch[p[i]] != ch[i]) nei[ch[p[i]]].pub(ch[i]), ++deg[ch[i]];
			else if(id[p[i]] > id[i]) Nope;
		}
	}
	queue<int> q; q.push(rt);
	vector<int> ans;
	while(SZ(q)) {
		int x = q.front(); q.pop();
		loop(i, SZ(hv[x])) ans.pub(hv[x][i]);
		loop(i, SZ(nei[x])) {
			int to = nei[x][i];
			--deg[to];
			if(!deg[to]) q.push(to);
		}
	}
	if(SZ(ans) != n) Nope;
	loop(i, SZ(ans)) printf("%d%c", ans[i], " \n"[i == SZ(ans) - 1]);
	return 0;
}