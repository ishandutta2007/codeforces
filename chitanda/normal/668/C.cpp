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

const double eps = (1e-10);
const double eeps = (1e-17);

const int maxn = 100100;
int n;
double a[maxn], b[maxn], p[maxn], q[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	double s1 = 0, s2 = 0;
	for(int i = 1; i <= n; ++i){
		//p*s2+q*s1+pq=a
		//p(1-s2)+q(1-s1)-pq=b
		//=> p+q=a+b
		//p^2-(a+b+s2-s1)p+a-(a+b)s1=0
		double A = 1, B = -(a[i] + b[i] + s2 - s1), C = a[i] - (a[i] + b[i]) * s1;
		double delta = B * B - 4 * A * C;
		delta = max(delta, 0.0);
		p[i] = (-B + sqrt(delta)) / (2 * A);
		if(p[i] > a[i] + b[i] + eps || p[i] < 0 - eps)
			p[i] = (-B - sqrt(delta)) / (2 * A);
		q[i] = a[i] + b[i] - p[i];
		p[i] = max(0., p[i]), q[i] = max(0., q[i]);
		s1 += p[i], s2 += q[i];
	}
	p[n] += 1 - s1;
	q[n] += 1 - s2;
	for(int i = 1; i <= n; ++i) printf("%.8f ", p[i]);
	puts("");
	for(int i = 1; i <= n; ++i) printf("%.8f ", q[i]);
	puts("");
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