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

struct Query{
	int l, r, id;
	Query() {}
	Query(int l, int r, int id) : l(l), r(r), id(id) {}
	bool operator < (const Query &a) const{
		return l < a.l;
	}
};

const int maxn = 1000100, maxp = 4 * maxn;
int n, tr[maxp * 4], m, a[maxn], s[maxn], ans[maxn];
vector<int> p[maxn];

void modify(int t, int l, int r, int x){
	if(l == r){
		tr[t] = a[x];
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(t << 1, l, mid, x);
	else modify((t << 1) | 1, mid + 1, r, x);
	tr[t] = tr[t << 1] ^ tr[(t << 1) | 1];
}

int ask(int t, int l, int r, int x, int y){
	if(x <= l && y >= r) return tr[t];
	int mid = (l + r) >> 1, res = 0;
	if(x <= mid) res ^= ask(t << 1, l, mid, x, y);
	if(y > mid) res ^= ask((t << 1) | 1, mid + 1, r, x, y);
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	map<int, int> mp;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i), s[i] = s[i - 1] ^ a[i];
		int L = mp[a[i]];
		p[L].pb(i);
		mp[a[i]] = i;
	}
	
	scanf("%d", &m);
	vector<Query> que;
	for(int i = 1; i <= m; ++i){
		int l, r;
		scanf("%d%d", &l, &r); 
		que.pb(Query(l, r, i));
	}
	sort(all(que));
	for(int i = 0, j = 0; i < n; ++i){
		for(auto v : p[i])
			modify(1, 1, n, v);
		while(que[j].l - 1 == i){
			ans[que[j].id] = ask(1, 1, n, que[j].l, que[j].r) ^ s[que[j].r] ^ s[que[j].l - 1];
			j++;
		}
	}
	
	for(int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
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