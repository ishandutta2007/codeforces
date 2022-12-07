#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

int n, h, w, maxw, maxh, minw, minh, ans, x, y;
char s[500100];

bool ok() { return h && w; }

bool move(ll t, bool tag){
	if (s[t % n] == 'R') y = tag ? maxw + 1 : y + 1;
	if (s[t % n] == 'L') y = tag ? minw - 1 : y - 1;
	if (s[t % n] == 'D') x = tag ? maxh + 1 : x + 1;
	if (s[t % n] == 'U') x = tag ? minh - 1 : x - 1;
	if (y < minw || y > maxw){
		if (y < minw) minw--; else maxw++;
		w--;
		ans = (ans + h * (t + 1) % M) % M;
		return 1;
	}
	if (x < minh || x > maxh){
		if (x < minh) minh--; else maxh++;
		h--;
		ans = (ans + w * (t + 1) % M) % M;
		return 1;
	}
	return 0;
}

int main(){
	scanf("%d%d%d", &n, &h, &w);
	scanf("%s", s);
	for(int i = 0; i < n && ok(); i++)
		move(i, 0);
	if (x == 0 && y == 0) { printf("-1\n"); return 0; }
	vector<int> key;
	for(int i = n; i < n * 2 && ok(); i++)
		if (move(i, 0)) key.push_back(i - n);
	for(int k = 2; ok(); k++)
		for(int p = 0; p < (int)key.size() && ok(); p++)
			move((ll)k * n + key[p], 1);
	printf("%d\n", ans);
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