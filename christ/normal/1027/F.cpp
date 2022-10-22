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
const int MN = 2e6 + 2, LOG = 17, INF = 1e8;
vector<int> adj[MN]; int sz,m,mx,mx2; bool vis[MN]; vector<int> xs;
void getx (int &x) {x = lower_bound(all(xs),x) - xs.begin() + 1;}
void dfs (int cur) {
	++sz; m += (int)adj[cur].size(); vis[cur] = 1;
	int val = xs[cur - 1];
	if (val > mx) {
		mx2 = mx;
		mx = val;
	}else mx2 = max(mx2,val);
	for (int i : adj[cur]) if (!vis[i]) dfs(i);
}
int main () { 
	int n;
	scanf ("%d",&n);
	vector<pii> edges(n);
	for (auto &au : edges) {
		scanf ("%d %d",&au.first,&au.second);
		xs.push_back(au.first); xs.push_back(au.second);
	}
	sort(all(xs)); xs.erase(unique(all(xs)),xs.end());
	for (auto &au : edges) {
		getx(au.first); getx(au.second);
		adj[au.first].push_back(au.second);
		adj[au.second].push_back(au.first);
	}
	int ans = 0;
	for (int i = 1; i <= (int)xs.size(); i++) if (!vis[i]) {
		mx = mx2 = -1e9; m = sz = 0;
		dfs(i); m /= 2;
		if (m > sz) return !printf ("-1\n");
		else if (m == sz) ans = max(ans,mx);
		else ans = max(ans,mx2);
	}
	printf ("%d\n",ans);
    return 0;
}