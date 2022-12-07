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

typedef pair<int, int> pa;
const int maxn = 1000100;
int n, a[maxn], b[maxn];
ll sa, sb;
bool had[maxn];
pa cal[maxn];

void print(int l, int r){
	printf("%d\n", r - l);
	for(int i = l + 1; i <= r; i++) printf("%d ", i);
	printf("\n");
}

void work(int a[], int b[], bool sw){
	sa = sb = 0;
	had[0] = 1;
	cal[0] = mkp(0, 0);
	for(int i = 1, j = 0; i <= n; i++){
		sa += a[i];
		while(j < n && sb + b[j + 1] <= sa) sb += b[++j];
		int diff = sa - sb;
		if(had[diff]){
			if(sw){
				print(cal[diff].fi, i);
				print(cal[diff].se, j);
			}else{
				print(cal[diff].se, j);
				print(cal[diff].fi, i);
			}
			return;
		}
		had[diff] = 1;
		cal[diff] = mkp(i, j);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", a + i), sa += a[i];
	FOR(i, 1, n) scanf("%d", b + i), sb += b[i];
	if(sa < sb) work(a, b, 1);
	else work(b, a, 0);
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