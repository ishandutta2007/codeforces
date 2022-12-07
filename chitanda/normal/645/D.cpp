//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

int n, m;
int ru[100100], len[100100];
vector<int> g[100100];
queue<int> q;
int u[100100], v[100100];

bool check(int k){
	for(int i = 1; i <= n; i++) g[i].clear(), ru[i] = 0, len[i] = 0;
	for(int i = 1; i <= k; i++){
		g[u[i]].pb(v[i]);
		ru[v[i]] ++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(!ru[i]) q.push(i), len[i] = 1;
	while(!q.empty()){
		int t = q.front();
		ans = max(ans, len[t]);
		q.pop();
		for(auto v : g[t]){
			ru[v]--;
			if(!ru[v]) q.push(v);
			len[v] = max(len[v], len[t] + 1);
		}
	}
	return ans == n;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 1, m) scanf("%d%d", u + i, v + i);
	if(!check(m)) printf("-1\n"); else{
		int l = 0, r = m;
		while(l + 1 < r){
			int m = (l + r) >> 1;
			if(check(m)) r = m;
			else l = m;
		}
		cout << r;
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