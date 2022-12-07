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

const int maxn = 1001000;
int n, k;
int a[maxn];

ll check(int d){
	int t = 0;
	ll sum = 0;
	for(int i = 1; i <= n; ++i){
		if (a[i] < d) continue;
		while (a[i] >= (d << t)) t++;

		int k = a[i] / (1 << (t - 1)), r = a[i] - k * (1 << (t - 1));
		if ((k + 1) / 2 >= d) sum += r;
		sum += 1 << (t - 1);
	}
	return sum;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	ll sum = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	if(sum < k) printf("-1\n");
	else{
		int l = 1, r = (1e7) + 1;
		while(l + 1 < r){
			int mid = l + r >> 1;
			if(check(mid) >= k) l = mid;
			else r = mid;
		}
		printf("%d\n", l);
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