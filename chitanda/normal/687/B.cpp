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

const int N = 1000000;
int n, k;
int c[N + 100];
vector<int> g[N + 100];
int ok[N + 100];
bool nop[N + 100];
int pp[N + 100], pri[N], tot;

void pre(){
	for(int i = 2; i <= N; ++i){
		if(!nop[i]) pri[++tot] = i, pp[i] = i;
		for(int j = 1; j <= tot && (ll)pri[j] * i <= N; ++j){
			nop[pri[j] * i] = 1;
			pp[pri[j] * i] = pri[j];
			if(i % pri[j] == 0) break;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	pre();
	for(int i = 1; i <= n; ++i){
		scanf("%d", c + i);
		ok[c[i]] = 1;
	}
	for(int i = N; i >= 2; --i){
		if(!nop[i] || !ok[i]) continue;
		int t = i, cnt = 0;
		while(t % pp[i] == 0) t /= pp[i], cnt++;
		ok[pp[i]] = max(ok[pp[i]], cnt);
		ok[t] = 1;
	}
	ok[1] = 1;
	while(k != 1){
		int cnt = 0, t = k;
		while(t % pp[k] == 0) t /= pp[k], cnt++;
		if(ok[pp[k]] < cnt) { printf("No\n"); return 0; }
		k = t;
	}
	printf("Yes\n");
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