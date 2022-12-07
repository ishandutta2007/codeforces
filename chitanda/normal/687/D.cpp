//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
#define mid ((l + r) >> 1)
#define ls getID(l, mid)
#define rs getID(mid + 1, r)

const int maxn = 1010, maxm = 1010 * 1010;
int n, m, q;
int fa[maxn];
int u[maxm], v[maxm], w[maxm];
vector<int> edges[maxm];
bool flag[maxn];

inline int getID(int l, int r){
	return (l + r) | (l < r);
}

inline bool cmp(int a, int b) { return w[a] > w[b]; }

inline int find(int x){
	if(fa[x] != x){
		int t = find(fa[x]);
		flag[x] ^= flag[fa[x]];
		return fa[x] = t;
	}else return x;
}

int merge(int e){
	int x = u[e], y = v[e];
	int xx = find(x), yy = find(y);
	if(xx != yy){
		fa[yy] = xx;
		flag[yy] ^= flag[x] == flag[y];
		return 2;
	}else{
		if(flag[x] == flag[y]) return 1;
		else return 0;
	}
}

vector<int> merge(vector<int> &a, vector<int> &b){
	vector<int> c, res;
	merge(all(a), all(b), back_inserter(c));
	sort(all(c), cmp);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	clean(flag);
	for(auto e : c){
		int tg = merge(e);
		if(tg) res.pb(e);
		if(tg == 1) break;
	}
	return res;
}

void build(int l, int r){
	int t = getID(l, r);
	if(l == r) return (void)edges[t].pb(l);
	build(l, mid), build(mid + 1, r);
	edges[t] = merge(edges[ls], edges[rs]);
}

vector<int> ans;

void add(vector<int> &a){
	for(auto v : a) ans.pb(v);
}

void query(int l, int r, int x, int y){
	int t = getID(l, r);
	if(x <= l && y >= r) return add(edges[t]);
	if(x <= mid) query(l, mid, x, y);
	if(y > mid) query(mid + 1, r, x, y);
}

int solve(){
	sort(all(ans), cmp);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	clean(flag);
	for(auto e : ans){
		int tg = merge(e);
		if(tg == 1) return w[e];
	}
	return -1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", u + i, v + i, w + i);
	}
	build(1, m);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		ans.clear();
		query(1, m, l, r);
		printf("%d\n", solve());
	}
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/