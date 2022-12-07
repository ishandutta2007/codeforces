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

int n, t;
char s[200100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &t);
	scanf("%s", s + 1);
	s[0] = '0';
	int L = 1;
	for(int i = 1; i <= n; ++i)
		if(s[i] == '.'){
			for(int j = i + 1; j <= n; ++j)
				if(s[j] >= '5'){
					for(int k = j; k > i && t; --k){
						int pre = k > i + 1 ? k - 1 : i - 1;
						if(s[k] > '9'){
							s[pre]++;
							s[k] = '0';
						}
						if(s[k] >= '5'){
							n = pre;
							t--;
							s[pre]++;
						}
					}
					break;
				}
			while(s[n] == '0' && n > i) n--;
			int k = i - 1;
			while(s[k] > '9'){
				s[k] = '0';
				s[k - 1]++;
				k--;
			}
			if(s[0] > '0') L = 0;
		}
	for(int i = L; i <= n; ++i) printf("%c", s[i]);
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