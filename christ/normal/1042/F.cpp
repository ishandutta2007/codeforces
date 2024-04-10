#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e6 + 2, LOG = 21, INF = 1e8;
vector<int> adj[MN]; int depth[MN],k,pp[MN];
priority_queue<int,vector<int>,greater<int>> st[MN];
void dfs (int cur, int p = -1) {
	int big = 0;
	for (int i : adj[cur]) if (i != p) {
		depth[i] = depth[cur] + 1;
		dfs(i,cur);
		if (st[pp[i]].size() > st[pp[big]].size()) big = i;
	}
	if (!big) {st[cur].push(depth[cur]); pp[cur] = cur; return;}
	pp[cur] = pp[big]; int go = pp[cur];
	for (int i : adj[cur]) if (i != p && i != big) 
		while (!st[pp[i]].empty()) st[go].push(st[pp[i]].top()), st[pp[i]].pop();
	while ((int)st[go].size() > 1) {
		int top = st[go].top(); st[go].pop(); int second = st[go].top();
		if (top + second - 2 * depth[cur] > k) {st[go].push(top); break;} 
	}
}
int main () { 
	int n;
	scanf ("%d %d",&n,&k);
	for (int i = 1; i < n; i++) {
		int a,b; scanf ("%d %d",&a,&b); adj[a].push_back(b); adj[b].push_back(a);
	}
	int rt = -1;
	for (int i = 1; i <= n; i++) if ((int)adj[i].size() > 1) rt = i;
	dfs(rt);
	printf ("%d\n",(int)st[pp[rt]].size());
    return 0;
}