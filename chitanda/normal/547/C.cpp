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

const int N = 500000;
const int maxn = N + 100;
bool nop[maxn], use[maxn];
int pri[maxn], mu[maxn], tot;
int n, q, x;
int a[maxn];
vector<int> g[maxn];
int cnt[maxn];
ll ans;

void pre(){
	mu[1] = 1;
	for(int i = 2; i <= N; ++i){
		if(!nop[i]) pri[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && pri[j] * i <= N; ++j){
			nop[pri[j] * i] = 1;
			if(i % pri[j]) mu[pri[j] * i] = -mu[i];
			else break;
		}
	}
	for(int i = 1; i <= N; ++i)
		if(mu[i] != 0)
			for(int j = i; j <= N; j += i)
				g[j].pb(i);
}

void add(int x){
	for(auto v : g[x]){
		ans += cnt[v] * mu[v];
		cnt[v]++;
	}
}

void del(int x){
	for(auto v : g[x]){
		cnt[v]--;
		ans -= cnt[v] * mu[v];
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	pre();
	for(int i = 1; i <= q; ++i){
		scanf("%d", &x);
		if(use[x]) del(a[x]);
		else add(a[x]);
		use[x] ^= 1;
		printf("%I64d\n", ans);
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