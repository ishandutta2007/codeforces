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

int n, m; ll ans;
char M[3333][3333];
int L[3333][3333], R[3333][3333];
int c[3333];

void add(int x, int v){
	for(; x <= n; x += x & -x) c[x] += v;
}

int ask(int x){
	if(x < 0) return 0;
	int ans = 0;
	for(; x; x -= x & -x) ans += c[x];
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", M[i] + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			if(M[i][j] == 'z') L[i][j] = M[i][j - 1] == 'z' ? L[i][j - 1] : j;
		for(int j = m; j >= 1; j--)
			if(M[i][j] == 'z') R[i][j] = R[i][j + 1] + 1;
	}
	for(int i = 1, x, y; i <= n + m - 1; i++){
		set<pair<int, int> >q;
		memset(c, 0, sizeof(c));
		if(i <= m) x = 1, y = i;
		else x = i - m + 1, y = m;
		int k = 0;
		while(k++, x <= n && y){
			while(!q.empty() && (-(*q.begin()).fi > y || M[x][y] != 'z')) add((*q.begin()).se, -1), q.erase(q.begin());
			if(M[x][y] == 'z') ans += ask(k) - ask(k - R[x][y]) + 1, q.insert(mkp(-L[x][y], k)), add(k, 1);
			x++, y--;
		}
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