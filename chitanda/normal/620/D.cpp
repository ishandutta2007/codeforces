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

typedef set<pair<ll, pair<int, int> > > S;
S p;
const int maxn = 2016;
int n, m;
int a[maxn], b[maxn];
ll sa, sb, ans;
int k, A[2], B[2];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i), sa += a[i];
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d", b + i), sb += b[i];
	ans = abs(sa - sb);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			ll v = abs(sa - a[i] + b[j] - (sb + a[i] - b[j]));
			if(v < ans){
				ans = v;
				k = 1;
				A[0] = i, B[0] = j;
			}
		}
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			p.insert(mkp(2LL * a[i] + 2LL * a[j], mkp(i, j)));
	for(int i = 1; i < m; i++)
		for(int j = i + 1; j <= m; j++){
			ll x = sa - sb + 2LL * b[i] + 2LL * b[j];
			S::ite it = p.lower_bound(mkp(x, mkp(0, 0)));
			if(it != p.end() && abs(x - (*it).fi) < ans){
				ans = abs(x - (*it).fi);
				k = 2;
				A[0] = (*it).se.fi, A[1] = (*it).se.se;
				B[0] = i, B[1] = j;
			}
			if(it == p.begin()) continue;
			it--;
			if(abs(x - (*it).fi) < ans){
				ans = abs(x - (*it).fi);
				k = 2;
				A[0] = (*it).se.fi, A[1] = (*it).se.se;
				B[0] = i, B[1] = j;
			}
		}
	cout << ans << endl;
	cout << k << endl;
	for(int i = 0; i < k; i++)
		cout << A[i] << ' ' << B[i] << endl;
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