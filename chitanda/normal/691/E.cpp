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
#define M 100 //M
#define P 1000000007 //P

int n;
ll k, a[110];
struct matrix{
	int x[M][M];
	int *operator [] (int a) { return x[a]; }
	void clear(){
		memset(x, 0, sizeof(x));
	}
	void reset(int n){
		memset(x, 0, sizeof(x));
		for(int i = 0; i < n; ++i) x[i][i] = 1;
	}
}p, ans, A;
void inc(int &a, int b) { a += b; if (a >= P) a -= P; }
matrix operator * (matrix &a, matrix &b){
	memset(p.x, 0, sizeof(p.x));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				inc(p[i][j], (ll)a[i][k] * b[k][j] % P);
	return p;
}

int calc(ll x){
	int cnt = 0;
	while(x) cnt += x & 1, x >>= 1;
	return cnt;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%I64d", &n, &k);
	for(int i = 0; i < n; ++i) scanf("%I64d", a + i);
	A.clear();
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(calc(a[i] ^ a[j]) % 3 == 0)
				A[i][j] = 1;
	ans.reset(n); k--;
	for(; k; k >>= 1, A = A * A)
		if(k & 1) ans = ans * A;
	int res = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			inc(res, ans[i][j]);
	printf("%d\n", res);
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