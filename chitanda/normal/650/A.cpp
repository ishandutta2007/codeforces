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

int n;
ll ans;
struct node{
	int x, y;
}p[200100];

bool cmpx(node a, node b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmpy(node a, node b){
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	cin >> n;
	FOR(i, 1, n) scanf("%d%d", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1, cmpx);
	for(int i = 2, cal = 1; i <= n; i++){
		if(p[i].x == p[i - 1].x) cal++;
		else{
			ans += (ll)cal * (cal - 1) / 2;
			cal = 1;
		}
		if(i == n) ans += (ll)cal * (cal - 1) / 2;
	}
	for(int i = 2, cal = 1; i <= n; i++){
		if(p[i].x == p[i - 1].x && p[i].y == p[i - 1].y) cal++;
		else{
			ans -= (ll)cal * (cal - 1) / 2;
			cal = 1;
		}
		if(i == n) ans -= (ll)cal * (cal - 1) / 2;
	}
	sort(p + 1, p + n + 1, cmpy);
	for(int i = 2, cal = 1; i <= n; i++){
		if(p[i].y == p[i - 1].y) cal++;
		else{
			ans += (ll)cal * (cal - 1) / 2;
			cal = 1;
		}
		if(i == n) ans += (ll)cal * (cal - 1) / 2;
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