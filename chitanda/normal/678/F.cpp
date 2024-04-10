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
#define mid ((l + r) >> 1)

const int maxn = 300100, maxm = 2 * maxn;

struct Point{
	ll x, y;
	Point(){}
	Point(ll _x, ll _y): x(_x), y(_y) {}
	Point operator - (const Point a) const{
		return Point(x - a.x, y - a.y);
	}
	Point operator + (const Point a) const{
		return Point(x + a.x, y + a.y);
	}
	ll operator * (const Point a) const{
		return x * a.y - y * a.x;
	}
	ll operator / (const Point a) const{
		return x * a.x + y * a.y;
	}
	bool operator < (const Point a) const{
		return x == a.x ? y < a.y : x < a.x;
	}
}p[maxn];

vector<Point> s[maxm];
Point sta[maxn];
int n, ty[maxn], top, que[maxn], tp, l[maxn], r[maxn], re[maxn];
ll ans[maxn];
bool hasans[maxn];

inline int getID(int l, int r){
	return (l + r) | (l < r);
}

void update(int l, int r, Point &p, int x, int y){
	int t = getID(l, r);
	if(x <= l && y >= r){
		s[t].pb(p);
		return;
	}
	if(x <= mid) update(l, mid, p, x, y);
	if(y > mid) update(mid + 1, r, p, x, y);
}

ll query(Point q){
	int l = 1, r = top;
	while(l + 1 < r){
		int m = (l + r) >> 1;
		if(sta[m] / q <= sta[m + 1] / q) l = m;
		else r = m;
	}
	return max(max(sta[l] / q, sta[r] / q), sta[top] / q);
}

void solve(int l, int r){
	if(l < r){
		solve(l, mid);
		solve(mid + 1, r);
	}
	int t = getID(l, r);
	sort(all(s[t]));
	top = 0;
	for(auto p : s[t]){
		while(top > 1 && (p - sta[top]) * (p - sta[top - 1]) <= 0) top--;
		sta[++top] = p;
	}
	for(int i = l; i <= r; ++i)
		if(ty[i] == 3 && top){
			hasans[i] = 1;
			ans[i] = max(ans[i], query(Point(que[i], 1)));
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", ty + i);
		if(ty[i] == 1){
			tp++; re[i] = tp;
			scanf("%I64d%I64d", &p[tp].x, &p[tp].y);
			l[tp] = i, r[tp] = n;
		}else if(ty[i] == 2){
			int id;
			scanf("%d", &id);
			r[re[id]] = i;
		}else{
			scanf("%d", que + i);
		}
	}
	for(int i = 1; i <= tp; ++i)
		update(1, n, p[i], l[i], r[i]);
	memset(ans, 128, sizeof(ans));
	solve(1, n);
	for(int i = 1; i <= n; ++i)
		if(ty[i] == 3){
			if(hasans[i]) printf("%I64d\n", ans[i]);
			else printf("EMPTY SET\n");
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