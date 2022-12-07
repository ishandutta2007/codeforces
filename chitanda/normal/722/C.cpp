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
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 400100;
const ll inf = 1LL << 60;

int n;
ll L[maxn], R[maxn], cnt[maxn], tr[maxn];
int a[maxn];

inline void update(int t){
	L[t] = max(L[ls], cnt[ls] + L[rs]);
	R[t] = max(R[rs], cnt[rs] + R[ls]);
	cnt[t] = cnt[ls] + cnt[rs];
	tr[t] = max(max(tr[ls], tr[rs]), R[ls] + L[rs]);

	L[t] = max(-inf, L[t]);
	R[t] = max(-inf, R[t]);
	cnt[t] = max(-inf, cnt[t]);
	tr[t] = max(-inf, tr[t]);
}

void build(int t, int l, int r){
	if(l == r){
		L[t] = R[t] = tr[t] = cnt[t] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(t << 1, l, mid);
	build((t << 1) | 1, mid + 1, r);
	update(t);
}

void modify(int t, int l, int r, int x){
	if(l == r){
		cnt[t] = -inf;
		L[t] = R[t] = 0;
		tr[t] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(ls, l, mid, x);
	else modify(rs, mid + 1, r, x);
	update(t);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	build(1, 1, n);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		modify(1, 1, n, x);
		printf("%lld\n", tr[1]);
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