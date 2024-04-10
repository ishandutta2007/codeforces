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
#define clean(a) memset(a, 0, sizeof(a))

int n, x, d[200100], a[200100], vis[200100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	queue<int> q;
	memset(d, 127, sizeof(d));
	d[1] = 0;
	q.push(1); vis[1] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		if(t < n && d[t] + 1 < d[t + 1]){
			d[t + 1] = d[t] + 1;
			if(!vis[t + 1]){
				vis[t + 1] = 1;
				q.push(t + 1);
			}
		}
		if(t > 1 && d[t] + 1 < d[t - 1]){
			d[t - 1] = d[t] + 1;
			if(!vis[t - 1]){
				vis[t - 1] = 1;
				q.push(t - 1);
			}
		}
		if(d[t] + 1 < d[a[t]]){
			d[a[t]] = d[t] + 1;
			if(!vis[a[t]]){
				vis[a[t]] = 1;
				q.push(a[t]);
			}
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d ", d[i]);
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