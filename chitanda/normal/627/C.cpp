//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

const int maxn = 200100;
int d, n, m;
struct node{
	int x, p;
}a[maxn];
bool cmp(node a, node b) { return a.x < b.x; }
struct Cmp{
	bool operator () (int x, int y) { return a[x].p < a[y].p || (a[x].p == a[y].p && a[x].x < a[y].x); }
};
set<int, Cmp> q;
ll ans;

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &d, &n, &m);
	FOR(i, 1, m) scanf("%d%d", &a[i].x, &a[i].p);
	sort(a + 1, a + m + 1, cmp);
	a[m + 1].x = d;
	for(int i = 0, j = 0; i <= m; i++){
		int pos = a[i].x;
		if(a[i + 1].x - a[i].x > n) { cout << -1; return 0; }
		q.insert(i);
		while(pos < a[i + 1].x){
			while(a[j].x + n <= pos) q.erase(j++);
			int take = min(a[i + 1].x - pos, n - (pos - a[*q.begin()].x));
			ans += (ll)take * a[*q.begin()].p;
			pos += take;
		}
	}
	cout << ans;
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