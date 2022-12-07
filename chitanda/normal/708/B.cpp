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

int a01, a10, a11, a00;

void work(int x, int y){
	if(a10 + a01 != x * y) return;
	string s;
	for(int i = 1; i <= x; ++i) s += '0';
	for(int i = 1; i <= y; ++i) s += '1';

	int now = x * y, cur = 0;
	while(now > a01){
		if(now - a01 >= y){
			swap(s[x - cur - 1], s[x + y - cur - 1]);
			now -= y;
		}else{
			swap(s[x - cur - 1], s[x - cur + now - a01 - 1]);
			now = a01;
		}
		cur++;
	}
	cout << s;
	exit(0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> a00 >> a01 >> a10 >> a11;
	
	int x = -1, y = -1;
	for(int i = 0; i <= 45000; ++i){
		if(i * (i - 1) == 2 * a00) x = i;
		if(i * (i - 1) == 2 * a11) y = i;
	}

	if(x == -1 || y == -1){
		cout << "Impossible";
		return 0;
	}
	work(x, y);
	if(x == 1) work(0, y);
	if(y == 1) work(x, 0);
	if(x == 1 && y == 1) work(0, 0);
	cout << "Impossible\n";
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