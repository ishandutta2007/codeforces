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

const int maxn = 2001000;

int n, pri[maxn], nop[maxn], tot, a[1010];

void pre(){
	for(int i = 2; i < maxn; ++i){
		if(!nop[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && pri[j] * i < maxn; ++j){
			nop[pri[j] * i] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	scanf("%d", &n);
	pre();
	int cnt1 = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		if(a[i] == 1) cnt1++;
	}
	if(cnt1){
		for(int i = 1; i <= n; ++i)
			if(a[i] > 1 && !nop[a[i] + 1]){
				printf("%d\n", cnt1 + 1);
				for(int j = 1; j <= cnt1; ++j) printf("1 ");
				printf("%d", a[i]);
				return 0;
			}
		if(cnt1 >= 2){
			printf("%d\n", cnt1);
			for(int j = 1; j <= cnt1; ++j) printf("1 ");
			return 0;
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < i; ++j)
			if(!nop[a[i] + a[j]]){
				printf("2\n");
				printf("%d %d", a[i], a[j]);
				return 0;
			}
	printf("1\n%d", a[1]);
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