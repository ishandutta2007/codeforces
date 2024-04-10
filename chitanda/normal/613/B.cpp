#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, A, cf, cm, tm, mt;
int a[100100], b[100100];
ll sum[100100];
ll m, ans;

bool cmp(int x, int y) { return a[x] < a[y]; }

int main(){
	scanf("%d%d%d%d%I64d", &n, &A, &cf, &cm, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = i;
	sort(b + 1, b + n + 1, cmp);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[b[i]];
	if (m >= (ll)n * A - sum[n]){
		printf("%I64d\n", cf * n + (ll)cm * A);
		for(int i = 1; i <= n; i++) printf("%d ", A);
		return 0;
	}
	for(int i = n, j = 0, mm = 0; i >= 0; i--){
		ll cost = (ll)i * A - (sum[n] - sum[n - i]);
		if (cost > m) continue;
		cost = m - cost;
		while(j < n - i && ((ll)a[b[j + 1]] * j - sum[j] <= cost)) j++;
		mm = a[b[j]] + (cost - (ll)a[b[j]] * j + sum[j]) / j;
		if (i * cf + (ll)mm * cm > ans){
			ans = i * cf + (ll)mm * cm;
			mt = i, tm = mm;
		}
	}
	printf("%I64d\n", ans);
	for(int i = 1; i <= mt; i++)
		a[b[n - i + 1]] = A;
	for(int i = 1; i <= n; i++) printf("%d ", max(a[i], tm));
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