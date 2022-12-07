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

const int maxn = 200100;
struct node{
	ll x; int o, id;
	bool operator < (const node &a) const{
		return x < a.x;
	}
}a[maxn];

struct cmp{
	bool operator () (const int &x, const int &y) { return a[x].x > a[y].x; }
};

int n, k, x;
ll b[maxn];
	
int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &k, &x);
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i].x);
		if(a[i].x < 0) cnt++, a[i].x = -a[i].x, a[i].o = -1;
		else a[i].o = 1;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	if(cnt & 1); else{
		int t = (a[1].x + x - 1) / x;
		if(t > k){
			a[1].x -= k * x;
			for(int i = 1; i <= n; ++i) b[a[i].id] = a[i].x * a[i].o;
			for(int i = 1; i <= n; ++i) printf("%lld ", b[i]);
			return 0;
		}else{
			k -= t;
			a[1].x = t * x - a[1].x;
			a[1].o *= -1;
		}
		sort(a + 1, a + n + 1);
	}

	priority_queue<int, vector<int>, cmp> q;
	for(int i = 1; i <= n; ++i) q.push(i);
	while(k--){
		int t = q.top(); q.pop();
		a[t].x += x;
		q.push(t);
	}
	for(int i = 1; i <= n; ++i) b[a[i].id] = a[i].x * a[i].o;
	for(int i = 1; i <= n; ++i) printf("%lld ", b[i]);
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