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

int n, l, r;

inline int pow(int a, int b){
	int res = 1;
	for(; b; b >>= 1, a *= a)
		if(b & 1) res *= a;
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &l, &r);
	if(n == 1) printf("%d\n", r - l + 1);
	else if(n == 2) printf("%lld\n", (ll)(r - l) * (r - l + 1));
	else{
		int li = pow(r, 1. / (n - 1)) + 0.01;
		//ll ans = r - l + 1;
		ll ans = 0;
		for(int p = 2; p <= li; ++p)
			for(int q = 1; q < p; ++q)
				if(__gcd(p, q) == 1){
					int LI = pow(q, n - 1), RI = pow(p, n - 1);
					int lt = (l - 1) / LI + 1, rt = r / RI;
					if(lt <= rt) ans += rt - lt + 1;
				}
		ans = ans * 2;
		printf("%lld\n", ans);
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