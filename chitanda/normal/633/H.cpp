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
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define L ls, l, mid
#define R rs, mid + 1, r

const int maxn = 30010, B = 300;
int n, m, q, nn;
int f[maxn * 2], tr[maxn * 4][2], tag[maxn * 4];
int a[maxn], ans[maxn], cal[maxn];
vector<int> b;
struct que{
	int l, r, w;
}p[maxn];

bool cmp(que a, que b) { return a.l / B != b.l / B ? a.l < b.l : a.r < b.r; }

inline void push(int t, int v){
	int t1 = tr[t][1], t0 = tr[t][0];
	tr[t][1] = (f[v + 1 + nn] * t1 + f[v + nn] * t0) % m;
	tr[t][0] = (f[v + nn] * t1 + f[v - 1 + nn] * t0) % m;
	tag[t] += v;
}

inline void down(int t){
	if(tag[t]){
		push(ls, tag[t]);
		push(rs, tag[t]);
	}tag[t] = 0;
}

inline void update(int t){
	tr[t][1] = tr[ls][1] + tr[rs][1]; if(tr[t][1] >= m) tr[t][1] -= m;
	tr[t][0] = tr[ls][0] + tr[rs][0]; if(tr[t][0] >= m) tr[t][0] -= m;
}

inline void modify(int t, int l, int r, int x, int v){
	if(l == r){
		cal[l] += v;
		tr[t][1] = (cal[l] > 0) * (ll)f[tag[t] + nn] * b[l - 1] % m;
		tr[t][0] = (cal[l] > 0) * (ll)f[tag[t] - 1 + nn] * b[l - 1] % m;
		return;
	}down(t);
	if(x <= mid) modify(L, x, v);
	else modify(R, x, v);
	update(t);
}

inline void change(int t, int l, int r, int x, int y, int v){
	if(x > y) return;
	if(l < r) down(t);
	if(x <= l && y >= r){
		push(t, v);
		return;
	}
	if(x <= mid) change(L, x, y, v);
	if(y > mid) change(R, x, y, v);
	update(t);
}

void add(int l, int r){
	FOR(i, l, r)
		if(modify(1, 1, nn, a[i], 1), cal[a[i]] == 1)
			change(1, 1, nn, a[i] + 1, nn, 1);
}

void del(int l, int r){
	FOR(i, l, r)
		if(modify(1, 1, nn, a[i], -1), cal[a[i]] == 0)
			change(1, 1, nn, a[i] + 1, nn, -1);
}

void work(){
	change(1, 1, nn, 1, nn, 1);
	add(p[1].l, p[1].r);
	ans[p[1].w] = tr[1][1];
	FOR(i, 2, q){
		if(p[i].r > p[i - 1].r) add(p[i - 1].r + 1, p[i].r);
		else del(p[i].r + 1, p[i - 1].r);
		if(p[i].l < p[i - 1].l) add(p[i].l, p[i - 1].l - 1);
		else del(p[i - 1].l, p[i].l - 1);
		ans[p[i].w] = tr[1][1];
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 1, n) scanf("%d", a + i), b.pb(a[i]);
	sort(all(b));
	b.resize(unique(all(b)) - b.begin()); nn = b.size();
	FOR(i, 1, n) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

	f[1 + nn] = f[2 + nn] = 1;
	FOR(i, 3, nn) f[i + nn] = (f[i - 1 + nn] + f[i - 2 + nn]) % m;
	FOR(i, 0, nn) f[nn - i] = (f[nn - i + 2] - f[nn - i + 1] + m) % m;
	
	cin >> q;
	FOR(i, 1, q){
		scanf("%d%d", &p[i].l, &p[i].r);
		p[i].w = i;
	}
	sort(p + 1, p + q + 1, cmp);
	work();
	FOR(i, 1, q) printf("%d\n", ans[i]);
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