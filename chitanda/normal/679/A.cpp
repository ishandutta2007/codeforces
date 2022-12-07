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

const int maxn = 200;
int pri[maxn + 10], nop[maxn + 10], tot;
int cnt;
char s[10];

void pre(){
	int ta;
	for(int i = 2; i <= maxn; i++){
		if(!nop[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && (ta =  i * pri[j]) <= maxn; j++){
			nop[ta] = 1;
			if(i % pri[j]); else{
				break;
			}
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	pre();
	int cnt = 0;
	for(int i = 1; pri[i] <= 50; ++i){
		printf("%d\n", pri[i]);
		fflush(stdout);
		scanf("%s", s);
		if(s[0] == 'y') {
			cnt++;
			if(pri[i] * pri[i] > 100) continue;
			printf("%d\n", pri[i] * pri[i]);
			fflush(stdout);
			scanf("%s", s);
			if(s[0] == 'y') cnt++;
		}
		if(cnt >= 2) break;
	}
	if(cnt <= 1) printf("prime\n");
	else printf("composite\n");
	fflush(stdout);
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