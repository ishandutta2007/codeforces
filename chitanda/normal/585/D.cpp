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

int n, l[30], w[30], m[30], a[30], ans = -(1 << 30), s1, s2;
map<pair<int, int>, pair<int, int> > mp;

void dfs(int x, int s, int t1, int t2, int t3){
	if(x > n / 2){
		if(!mp.count(mkp(t2 - t1, t3 - t2)) || t1 > mp[mkp(t2 - t1, t3 - t2)].fi)
			mp[mkp(t2 - t1, t3 - t2)] = mkp(t1, s); 
		return; 
	}
	dfs(x + 1, s * 3 + 0, t1, t2 + m[x], t3 + w[x]);
	dfs(x + 1, s * 3 + 1, t1 + l[x], t2, t3 + w[x]);
	dfs(x + 1, s * 3 + 2, t1 + l[x], t2 + m[x], t3);
}

void print(int p){
	if(!p) printf("MW\n");
	else if(p == 1) printf("LW\n");
	else printf("LM\n");
}

void out(int n, int t){
	if(!n) return;
	out(n - 1, t / 3);
	print(t % 3);
}

void DFS(int x, int s, int t1, int t2, int t3){
	if(x > n){
		if(mp.count(mkp(t1 - t2, t2 - t3))){
			auto t = mp[mkp(t1 - t2, t2 - t3)];
			if(t1 + t.fi > ans){
				ans = t1 + t.fi;
				s1 = t.se, s2 = s;
			}
		}
		return;
	}
	a[x] = 0, DFS(x + 1, s * 3 + 0, t1, t2 + m[x], t3 + w[x]);
	a[x] = 1, DFS(x + 1, s * 3 + 1, t1 + l[x], t2, t3 + w[x]);
	a[x] = 2, DFS(x + 1, s * 3 + 2, t1 + l[x], t2 + m[x], t3);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	FOR(i, 1, n) cin >> l[i] >> m[i] >> w[i];
	dfs(1, 0, 0, 0, 0);
	DFS(n / 2 + 1, 0, 0, 0, 0);
	if(ans == -(1 << 30)) printf("Impossible\n");
	else{
		out(n / 2, s1);
		out(n - n / 2, s2);
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