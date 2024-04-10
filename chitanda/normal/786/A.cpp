//int!
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;

int f[8000][2];
int a[8000], b[8000];
int n;
int k[2];
int du[8000][2];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d", k + 0);
	vector<pair<int, int>> q[2];
	memset(f, -1, sizeof(f));
	for(int i = 1; i <= k[0]; ++i){
		scanf("%d", a + i);
	}
	scanf("%d", k + 1);
	for(int i = 1; i <= k[1]; ++i){
		scanf("%d", b + i);
	}
	f[1][0] = f[1][1] = 0;
	q[0].pb(mkp(1, 0)); q[0].pb(mkp(1, 1));
	
	for(int now = 0; q[now].size(); now ^= 1){
		q[now ^ 1].clear();
		for(auto v : q[now])
			for(int j = 1; j <= k[v.se ^ 1]; ++j){
				int ni = v.fi - (v.se ? a[j] : b[j]); if(ni < 1) ni += n;
				if(ni == 1 || f[ni][v.se ^ 1] != -1) continue;
				if(now){
					if(++du[ni][v.se ^ 1] == k[v.se ^ 1]){
						f[ni][v.se ^ 1] = 0;
						q[0].pb(mkp(ni, v.se ^ 1));
					}
				}else{
					f[ni][v.se ^ 1] = 1;
					q[1].pb(mkp(ni, v.se ^ 1));
				}
			}
	}

	for(int i = 2; i <= n; ++i){
		printf("%s ", f[i][0] == 1 ? "Win" : f[i][0] == 0 ? "Lose" : "Loop");
	}
	puts("");
	for(int i = 2; i <= n; ++i){
		printf("%s ", f[i][1] == 1 ? "Win" : f[i][1] == 0 ? "Lose" : "Loop");
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