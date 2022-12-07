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

int n, t[5010], cnt[5010], ans[5010];

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d", t + i);
	for(int i = 1; i <= n; i++){
		memset(cnt, 0, sizeof(cnt));
		int cl = t[i];
		for(int j = i; j <= n; j++){
			cnt[t[j]]++;
			if(cnt[t[j]] > cnt[cl] || (cnt[t[j]] == cnt[cl] && t[j] < cl)) cl = t[j];
			ans[cl]++;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
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