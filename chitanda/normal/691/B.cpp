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

char m[250];
char s[1010];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	m['A'] = 'A';
	m['b'] = 'd';
	m['d'] = 'b';
	m['I'] = 'I';
	m['H'] = 'H';
	m['M'] = 'M';
	m['p'] = 'q';
	m['q'] = 'p';
	m['O'] = 'O';
	m['o'] = 'o';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['v'] = 'v';
	m['W'] = 'W';
	m['w'] = 'w';
	m['X'] = 'X';
	m['x'] = 'x';
	m['Y'] = 'Y';
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; ++i){
		if(s[i] != m[s[n - i + 1]]){
			printf("NIE\n");
			return 0;
		}
	}
	printf("TAK\n");
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