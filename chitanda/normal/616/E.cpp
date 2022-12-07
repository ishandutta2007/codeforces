#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

ll n, m;

int mul(ll x, ll y, int m){
	x %= m;
	int ans = 0;
	for(; y; y >>= 1, (x <<= 1) %= m)
		if (y & 1) (ans += x) %= m;
	return ans;
}

int main(){
	scanf("%I64d%I64d\n", &n, &m);
	int ans = mul(n, m, M);
	for(ll i = 1, j, t; i <= m; i = j + 1){
		if (n / i) j = min(m, n / (n / i)); else j = m;
		if ((i + j) & 1) t = mul(i + j, (j - i + 1) / 2, M);
		else t = mul((i + j) / 2, j - i + 1, M);
		ans = (ans - mul(t, n / i, M) + M) % M;
	}
	printf("%d\n", ans);
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