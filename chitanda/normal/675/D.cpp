#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
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

int n, a[100100], dp[100100];
set<pair<int, int> > q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d", a + 1);
	q.insert(mkp(a[1], 1));
	for(int i = 2; i <= n; ++i){
		scanf("%d", a + i);
		auto it1 = q.lower_bound(mkp(a[i], i));
		auto it2 = it1;
		if(it2 == q.begin()){
			dp[i] = dp[(*it1).se] + 1;
			printf("%d ", (*it1).fi);
		}else if(it2 == q.end()){
			it1--;
			dp[i] = dp[(*it1).se] + 1;
			printf("%d ", (*it1).fi);
		}else{
			it1--;
			dp[i] = (dp[(*it1).se] > dp[(*it2).se] ? printf("%d ", (*it1).fi), dp[(*it1).se] : printf("%d ", (*it2).fi), dp[(*it2).se]) + 1;
		}
		q.insert(mkp(a[i], i));
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