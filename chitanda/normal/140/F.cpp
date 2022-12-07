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

const int maxn = 200100;
const double eps = 1e-8;
struct node{
	int x, y;
	node() {}
	node(int x, int y) : x(x), y(y) {}
	node operator - (const node &a) const{
		return node(x - a.x, y - a.y);
	}
	bool operator == (const node &a) const{
		return x == a.x && y == a.y;
	}
	bool operator != (const node &a) const{
		return !(*this == a);
	}
	bool operator < (const node &a) const{
		return x < a.x || (x == a.x && y < a.y);
	}
}p[maxn];
int n, k;

bool work(node o){
	int cnt = 0;
	for(int i = 1, j = n; i <= n; ++i){
		while(p[i] != o - p[j] && (i == n || o - p[j] < p[i + 1]) && j > 1) --j;
		if(p[i] != o - p[j]) cnt++; else --j;
		if(cnt > k) return 0;
	}
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	if(k >= n){
		printf("-1\n");
		return 0;
	}
	sort(p + 1, p + n + 1);
	
	vector<node> ans;
	for(int i = 1; i <= k + 1; ++i)
		for(int j = n - k; j <= n; ++j){
			int x = p[i].x + p[j].x, y = p[i].y + p[j].y;
			if(work(node(x, y))) ans.pb(node(x, y));
		}
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	printf("%d\n", ans.size());
	for(auto po : ans) printf("%.1f %.1f\n", po.x * 0.5 + eps, po.y * 0.5 + eps);
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