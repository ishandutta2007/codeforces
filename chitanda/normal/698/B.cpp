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

const int maxn = 200100;
int n, p[maxn], fa[maxn], ok[maxn];

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", p + i);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= n; ++i){
		if(p[i] == i) continue;
		int u = find(i), v = find(p[i]);
		if(u != v){
			ok[i] = 1;
			fa[v] = u;
		}
	}
	bool flag = 0;
	int last;
	for(int i = 1; i <= n; ++i)
		if(p[i] == i){
			ok[i] = 1;
			flag = 1;
			last = find(i);
			break;
		}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!ok[i]){
			if(!flag){
				p[i] = i;
				flag = 1;
				last = find(i);
				ans++;
			}else{
				p[i] = last;
				last = find(i);
				ans++;
			}
		}
	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i) printf("%d ", p[i]);
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