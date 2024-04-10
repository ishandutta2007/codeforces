//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define L ls, l, mid
#define R rs, mid + 1, r

const int maxn = 200100;
int n, q, ty, l, r, k;
int a[maxn], c[maxn], b[maxn];
typedef vector<int> vec;
vec v[maxn * 4], ans;

void insert(vec &v, int x){
	for(auto a : v)
		if(a & -a & x) x ^= a;
	if(!x) return;
	for(auto a : v)
		if(a & -a & x) a ^= x;
	v.pb(x);
}

void update(vec &a, const vec b){
	for(auto x : b) insert(a, x);
}

void modify(int t, int l, int r, int x, int y){
	if(l == r) return(v[t].clear(), insert(v[t], y));
	if(x <= mid) modify(L, x, y);
	else if(x > mid) modify(R, x, y);
	v[t] = v[ls], update(v[t], v[rs]);
}

void query(int t, int l, int r, int x, int y){
	if(x <= l && y >= r) return(update(ans, v[t]));
	if(x <= mid) query(L, x, y);
	if(y > mid) query(R, x, y);
}

void add(int x, int v){
	for(; x <= n; x += x & -x) c[x] ^= v;
}

int ask(int x){
	int ans = 0;
	for(; x; x -= x & -x) ans ^= c[x];
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> q;
	FOR(i, 1, n){
		scanf("%d", a + i), b[i] = a[i] ^ a[i - 1];
		modify(1, 1, n, i, b[i]);
		add(i, b[i]);
	}
	while(q--){
		scanf("%d%d%d", &ty, &l, &r);
		if(ty == 1){
			scanf("%d", &k);
			add(l, k), modify(1, 1, n, l, b[l] ^= k);
			if(r < n) add(r + 1, k), modify(1, 1, n, r + 1, b[r + 1] ^= k);
		}else{
			ans.clear();
			if(l < r) query(1, 1, n, l + 1, r);
			insert(ans, ask(l));
			printf("%d\n", 1 << ans.size());
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