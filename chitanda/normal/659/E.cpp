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

const int maxn = 100100;
int n, m, ans, u, v;
multiset<int> g[maxn];
int du[maxn];
queue<int> q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &u, &v);
		g[u].insert(v), g[v].insert(u);
		du[u]++, du[v]++;
	}
	for(int i = 1; i <= n; ++i){
		if(du[i] == 0) ans++;
		else if(du[i] == 1) q.push(i);
	}
	while(!q.empty()){
		int t = q.front(); q.pop();
		if(!du[t]) { ans++; continue; }
		int v = *g[t].begin();
		du[v]--, g[v].erase(t);
		if(du[v] == 1) q.push(v);
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