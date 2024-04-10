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

void win() { printf("Yes\n"); exit(0); }
void lose() { printf("No\n"); exit(0); }

char s[100];
int n, k;
bool udf[100100];
int a[100100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	cin >> n >> k;
	int cnt = 0;
	for(int i = 0; i <= n; ++i){
		scanf("%s", s);
		if(s[0] == '?') udf[i] = 1, cnt++;
		else sscanf(s, "%d", a + i);
	}

	if(!k){
		if(udf[0]){
			if((n - cnt) & 1) lose();
			else win();
		}
		else if(a[0] == 0) win(); else lose();
	}else{
		if(cnt){
			if(n & 1) win();
			else lose();
		}else{
			ll res = 0;
			for(int i = n; i >= 0; --i){
				res *= k;
				res += a[i];
				if(abs(res) > 1e14){
					lose();
					return 0;
				}
			}
			if(!res) win();
			else lose();
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