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

const int B = 200000;
int n, x[200100], y[200100], col[200100];
bool tag[400100];
set<int> g[400100];

void walk(int i, bool tg){
	if(!g[i].empty()){
		int e = *g[i].begin();
		int t = x[e] == i ? y[e] : x[e];
		g[i].erase(e);
		g[t].erase(e);
		col[e] = tg ^ 1;
		walk(t, tg ^ 1);
	}else tag[i] ^= 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", x + i, y + i);
		y[i] += B;
		g[x[i]].insert(i);
		g[y[i]].insert(i);
	}
	for(int i = 1; i <= 200000; ++i)
		while(!g[i].empty()){
			int e = *g[i].begin();
			g[i].erase(e);
			g[y[e]].erase(e);
			col[e] = tag[i];
			tag[i] ^= 1;
			walk(y[e], col[e]);
		}
	for(int i = 1; i <= n; ++i)
		printf("%c", col[i] ? 'b' : 'r');
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