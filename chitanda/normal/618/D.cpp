//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; i++)
#define ROF(i, r, l) for(int i = (int)r; i >= (int)l; i--)

const int maxn = 200100;
int n, x, y, cal, u, v;
vector<int> g[maxn];

bool dfs(int t, int fa){
	int ta = 0;
	for(int i = 0; i < (int)g[t].size(); i++)
		if(g[t][i] != fa){
			if(dfs(g[t][i], t)) ta++;
			else cal++;
		}
	if(ta >= 2) { cal += ta - 2; return 0; }
	else return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	if(x == y){
		cout << (ll)x * (n - 1);
		return 0;
	}
	if(x > y){
		bool ok = 0;
		for(int i = 1; i <= n; i++)
			if((int)g[i].size() == n - 1) ok = 1;
		if(ok) cout << (ll)y * (n - 2) + x;
		else cout << (ll)y * (n - 1);
	}
	if(x < y){
		dfs(1, 0);
		cout << (ll)x * (n - 1 - cal) + (ll)y * cal;
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