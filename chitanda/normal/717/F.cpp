//int!
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 200100, oo = 1e9;
int n;
int a[maxn];
int tag[maxn * 4][2], tr[maxn * 4][2];
int v[2];

inline void update(int t){
	tr[t][0] = min(tr[ls][0], tr[rs][0]);
	tr[t][1] = min(tr[ls][1], tr[rs][1]);
}

void build(int t, int l, int r){
	if(l == r){
		tr[t][l & 1] = a[l];
		tr[t][(l & 1) ^ 1] = oo;
		return;
	}
	build(ls, l, mid), build(rs, mid + 1, r);
	update(t);
}

inline void add(int t, int l, int r, int k, bool o){
	if((l & 1) == o || r > l) tr[t][o] += k, tag[t][o] += k;
}

inline void pushDown(int t, int l, int r){
	for(int o = 0; o < 2; ++o)
		if(tag[t][o]){
			add(ls, l, mid, tag[t][o], o);
			add(rs, mid + 1, r, tag[t][o], o);
			tag[t][o] = 0;
		}
}

void modify(int t, int l, int r, int x, int y){
	if(x <= l && y >= r){
		add(t, l, r, v[0], 0);
		add(t, l, r, v[1], 1);
		return;
	}
	pushDown(t, l, r);
	if(x <= mid) modify(ls, l, mid, x, y);
	if(y > mid) modify(rs, mid + 1, r, x, y);
	update(t);
}

void query(int t, int l, int r, int x, int y){
	if(x <= l && y >= r){
		ckmin(v[0], tr[t][0]);
		ckmin(v[1], tr[t][1]);
		return;
	}
	pushDown(t, l, r);
	if(x <= mid) query(ls, l, mid, x, y);
	if(y > mid) query(rs, mid + 1, r, x, y);
	update(t);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		a[i] = a[i] - a[i - 1];
	}
	build(1, 1, n);

	int m, ty, l, r, k;
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", &ty, &l, &r);
		l++, r++;
		if(ty == 1){
			scanf("%d", &k);
			v[l & 1] = k, v[!(l & 1)] = 0;
			modify(1, 1, n, l, r);
			if((r - l) & 1); else{
				v[r & 1] = k, v[!(r & 1)] = -k;
				if(r < n) modify(1, 1, n, r + 1, n);
			}
		}else{
			v[0] = v[1] = oo;
			int vv, vr, o = (l - 1) & 1;
			if(l > 1) query(1, 1, n, l - 1, l - 1), vv = v[o];
			else vv = 0;
			v[0] = v[1] = oo;
			query(1, 1, n, r, r);
			v[o ^ 1] += vv, v[o] -= vv;
			vr = v[r & 1] == !((r - l) & 1);
			v[0] = v[1] = oo;
			query(1, 1, n, l, r);
			v[o ^ 1] += vv, v[o] -= vv;
			printf("%d\n", vr && v[o] >= 0 && v[o ^ 1] >= 1 ? 1 : 0);
		}
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