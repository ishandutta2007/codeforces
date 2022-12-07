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

const int maxn = 1000100;
int n, k, s, x, rt, tot;
int son[maxn * 30][2], cnt[maxn * 30];
ll ans;

int insert(int t, int dp, int val){
	if(!t) t = ++tot;
	cnt[t]++;
	if(dp < 0) return t;
	if(val & (1 << dp)) son[t][1] = insert(son[t][1], dp - 1, val);
	else son[t][0] = insert(son[t][0], dp - 1, val);
	return t;
}

int find(int t, int dp, int val){
	if(!t) return 0;
	if(dp < 0) return cnt[t];
	bool p = (k >> dp) & 1, q = (val >> dp) & 1;
	if(!p){
		return find(son[t][q], dp - 1, val) + cnt[son[t][q ^ 1]];
	}else return find(son[t][q ^ 1], dp - 1, val);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	rt = insert(rt, 29, 0);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		s ^= x;
		ans += find(rt, 29, s);
		rt = insert(rt, 29, s);
	}
	cout << ans;
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