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

char s[100100];
int m, cnt[30];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &m);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int j = 1; j <= n; ++j) cnt[s[j] - 'a']++;
 
	for(int i = 0; i < 26; ++i){
		int la = 0;
		bool flag = 1;
		for(int j = 1; j <= n; ++j)
			if(s[j] - 'a' <= i) la = j;
			else if(j - la >= m) { flag = 0; break; }
		if(flag){
			string ss;
			for(int j = 0; j < i; ++j)
				for(int k = 1; k <= cnt[j]; ++k)
					ss = ss + char('a' + j);

			int la = 0, lai = 0;
			for(int j = 1; j <= n; ++j)
				if(s[j] - 'a' < i) la = j;
				else{
					if(s[j] - 'a' == i) lai = j;
					if(j - la >= m) ss = ss + char('a' + i), la = lai;
				}
			
			cout << ss;
			return 0;
		}
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