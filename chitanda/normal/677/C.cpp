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

const int M = 1e9 + 7;
char s[101000];
int a[64];

int get(char c){
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
	if(c >= 'a' && c <= 'z') return c - 'a' + 36;
	if(c == '-') return 62;
	return 63;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	scanf("%s", s + 1);
	for(int i = 0; i < 64; ++i)
		for(int j = 0; j < 64; ++j)
			a[i & j]++;

	int n = strlen(s + 1), ans = 1;
	for(int i = 1; i <= n; ++i){
		int t = get(s[i]);
		ans = (ll)ans * a[t] % M;
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