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
#define B 2 //B
#define M 1000000007
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 100100;
int n, m;
int b[maxn];

struct matrix{
	int x[B][B];
	int *operator [] (int a) { return x[a]; }
	void clear(){
		memset(x, 0, sizeof(x));
	}
	void reset(){
		memset(x, 0, sizeof(x));
		for(int i = 0; i < B; ++i) x[i][i] = 1;
	}
}p, tr[maxn * 4], tag[maxn * 4], a, res, o;
void inc(int &a, int b) { a += b; if (a >= M) a -= M; }
matrix operator * (matrix &a, matrix &b){
	memset(p.x, 0, sizeof(p.x));
	for(int i = 0; i < B; i++)
		for(int j = 0; j < B; j++)
			for(int k = 0; k < B; k++)
				inc(p[i][j], (ll)a[i][k] * b[k][j] % M);
	return p;
}
matrix operator + (matrix &a, matrix &b){
	p.clear();
	for(int i = 0; i < B; ++i)
		for(int j = 0; j < B; ++j)
			p[i][j] = (a[i][j] + b[i][j]) % M;
	return p;
}

matrix power(int n){
	a.clear(); a[0][0] = a[0][1] = a[1][0] = 1;
	res.reset();
	for(; n; n >>= 1, a = a * a)
		if(n & 1) res = res * a;
	return res;
}

void build(int t, int l, int r){
	tag[t].reset();
	if(l == r){
		tr[t] = power(b[l] - 1);
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	tr[t] = tr[ls] + tr[rs];
}

inline void pushDown(int t){
	tr[ls] = tr[ls] * tag[t];
	tr[rs] = tr[rs] * tag[t];
	tag[ls] = tag[ls] * tag[t];
	tag[rs] = tag[rs] * tag[t];
	tag[t].reset();
}

void modify(int t, int l, int r, int x, int y){
	if(x <= l && y >= r){
		tag[t] = tag[t] * o;
		tr[t] = tr[t] * o;
		return;
	}
	pushDown(t);
	if(x <= mid) modify(ls, l, mid, x, y);
	if(y > mid) modify(rs, mid + 1, r, x, y);
	tr[t] = tr[ls] + tr[rs];
}

void query(int t, int l, int r, int x, int y){
	if(x <= l && y >= r){
		o = o + tr[t];
		return;
	}
	pushDown(t);
	if(x <= mid) query(ls, l, mid, x, y);
	if(y > mid) query(rs, mid + 1, r, x, y);
	tr[t] = tr[ls] + tr[rs];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", b + i);
	build(1, 1, n);
	int ty, l, r, x;
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", &ty, &l, &r);
		if(ty == 1){
			scanf("%d", &x);
			o = power(x);
			modify(1, 1, n, l, r);
		}else{
			o.clear();
			query(1, 1, n, l, r);
			printf("%d\n", o[0][0]);
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