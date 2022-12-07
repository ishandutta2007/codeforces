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

char s[1000100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int l = 1; while(s[l] == '0') l++;
	for(int i = l; i <= n; ++i)
		if(s[i] == '.'){
			if(i == l){
				l++; while(s[l] == '0') l++;
				printf("%c", s[l]);
				int r = n; while(s[r] == '0') r--;
				if(r > l){
					printf(".");
					for(int j = l + 1; j <= r; ++j) printf("%c", s[j]);
				}
				printf("E%d", i - l);
			}else{
				int r = n; while(s[r] == '0' || s[r] == '.') r--;
				printf("%c", s[l]);
				if(r > l){
					printf(".");
					for(int j = l + 1; j <= r; ++j)
						if(s[j] != '.') printf("%c", s[j]);
				}
				if(i - l - 1)printf("E%d", i - l - 1);
			}
			return 0;
		}
	printf("%c", s[l]);
	int m = n;
	while(m > l && s[m] == '0') m--;
	if(m > l){
		printf(".");
		for(int i = l + 1; i <= m; ++i) printf("%c", s[i]);
	}
	if(n - l > 0) printf("E%d", n - l);
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