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
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

int n, co, m, g[600100], tot;
char s[600100];
ll ans;

int root, last, par[1200100], pos[1200100], go[1200100][27], val[1200100];
ll c[1200100];

void extend(int w, int cc, int po){
	int p = last;
	int np = ++tot; val[np] = val[p] + 1, pos[np] = po;
	c[np] = cc;
	while(p && !go[p][w]) go[p][w] = np, p = par[p];
	if(!p) par[np] = root;
	else{
		int q = go[p][w];
		if(val[p] + 1 == val[q]) par[np] = q;
		else{
			int nq = ++tot; val[nq] = val[p] + 1; pos[nq] = pos[q];
			memcpy(go[nq], go[q], sizeof(go[q]));
			par[nq] = par[q];
			par[q] = nq;
			par[np] = nq;
			while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
		}
	}
	last = np;
}

vector<int> v[1200100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("xx.out", "w", stdout);
#endif
	cin >> n;
	
	root = last = ++tot;

	FOR(i, 1, n){
		s[m++] = 'z' + 1;
		scanf("%s", s + m);
		m = strlen(s);
	}
	int j = 0;
	FOR(i, 1, n){
		scanf("%d", &co);
		extend(s[g[j] = j] - 'a', 0, j); j++;
		while(j < m && s[j] != 'z' + 1) g[j] = g[j - 1], extend(s[j] - 'a', co, j), j++;
	}
	for(int i = 1; i <= tot; i++) v[val[i]].pb(i);
	for(int h = m; h; h--){
		for(int ii = 0; ii < (int)v[h].size(); ii++){
			int i = v[h][ii], j = par[i];
			c[j] += c[i];
			int lng = min(val[i], pos[i] - g[pos[i]]);
			if(lng > val[j])
				ans = max(ans, lng * c[i]);
		}
	}
	/*	if(n == 100000 && s[1] == 'a'){
		for(int i = 1; i <= tot; i++) if(c[i] != 0) printf("%d\n", i);
		}*/
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