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
#define B 128 //B

struct matrix{
	double x[B][B];
	double *operator [] (int a) { return x[a]; }
	void clear(){
		memset(x, 0, sizeof(x));
	}
	void reset(){
		clear();
		for(int i = 0; i < B; ++i) x[i][i] = 1;
	}
}p, a, ans;
matrix operator * (matrix &a, matrix &b){
	p.clear();
	for(int i = 0; i < B; i++)
		for(int j = 0; j < B; j++)
			for(int k = 0; k < B; k++)
				p[i][j] += a[i][k] * b[k][j];
	return p;
}

int n, x;
double pos[128];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &x);
	for(int i = 0; i <= x; ++i) scanf("%lf", &pos[i]);
	a.clear();
	for(int i = 0; i < 128; ++i)
		for(int j = 0; j < 128; ++j)
			a[i][j] = pos[i ^ j];
	ans.reset();
	for(; n; n >>= 1, a = a * a)
		if(n & 1) ans = ans * a;
	printf("%.10f\n", 1.0 - double(ans[0][0]));
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