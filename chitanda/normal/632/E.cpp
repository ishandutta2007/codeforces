//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <complex>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

typedef complex<double> Comp;
const double pi = acos(-1.0);
const int m = 1 << 20;
Comp x[m], y[m], tmp[m], R[m];
int n, k, d, a[m], ans[m], rev[m];

void FFT(Comp *a, Comp *f){
	for(int i = 0; i < m; i++) f[i] = a[rev[i]];
	for(int k = 1; k < m; k <<= 1)
		for(int i = 0; i < m; i += 2 * k)
			for(int j = 0; j < k; j++){
				Comp z = f[i + j + k] * R[j + k];
				f[i + j + k] = f[i + j] - z;
				f[i + j] = f[i + j] + z;
			}
}

void mul(int *a, int *b){	
	for(int i = 0; i < m; i++)
		x[i] = Comp(a[i], b[i]);
	FFT(x, y);
	for(int i = 0; i < m; i++){
		int j = (m - i) & (m - 1);
		x[i] = (y[j] * y[j] - conj(y[i] * y[i])) * Comp(0, -0.25 / m);
	}
	FFT(x, y);
	for(int i = 0; i < m; i++) a[i] = y[i].real() > 0.5;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> k;
	FOR(i, 1, n) scanf("%d", &d), a[d] = 1;
	for(int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1)+ ((i & 1) << (20 - 1));
	for(int i = 0; i < m / 2; i++){
		double alp = i * 2 * pi / m;
		R[i + m / 2] = Comp(cos(alp), sin(alp));
	}
	for(int i = m / 2 - 1; i; i--) R[i] = R[i * 2];
	ans[0] = 1;
	for(; k; k >>= 1, mul(a, a))
		if(k & 1) mul(ans, a);
	for(int i = 0; i < m; i++) if(ans[i]) printf("%d ", i);
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