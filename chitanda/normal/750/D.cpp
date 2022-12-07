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

const int xx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int yy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct boom{
	int x, y, d, i;
	boom() {}
	boom(int x, int y, int d, int i) : x(x), y(y), d(d), i(i) {}

	int hash() {
		return x * 500 * 8 * 31 + y * 8 * 31 + d * 31 + i;
	}
};

bool tag[510][510];
int n, a[40];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	queue<boom> q;
	unordered_map<int, bool> mp;
	q.push(boom(200, 200, 0, 1));
	mp[boom(200, 200, 0, 1).hash()] = 1;
	
	while(!q.empty()){
		boom t = q.front(); q.pop();
		int x = t.x, y = t.y;
		for(int i = 1; i <= a[t.i]; ++i){
			x += xx[t.d], y += yy[t.d];
			tag[x][y] = 1;	
		}
		if (t.i == n) continue;
		int d1 = (t.d + 1) % 8, d2 = (t.d + 7) % 8;
		boom b1 = boom(x, y, d1, t.i + 1), b2 = boom(x, y, d2, t.i + 1);
		if (mp[b1.hash()] == 0){
			mp[b1.hash()] = 1;
			q.push(b1);
		}
		if (mp[b2.hash()] == 0){
			mp[b2.hash()] = 1;
			q.push(b2);
		}
	}

	int ans = 0;
	for(int i = 0; i <= 500; ++i)
		for(int j = 0; j <= 500; ++j)
			if (tag[i][j]) ans++;

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