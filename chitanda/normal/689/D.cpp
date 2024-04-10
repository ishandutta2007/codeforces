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

int n, a[200100][19], b[200100][19], L[200100];

int RMQ1(int l, int r){
	int k = L[r - l + 1];
	return max(a[l][k], a[r - (1 << k) + 1][k]);
}

int RMQ2(int l, int r){
	int k = L[r - l + 1];
	return min(b[l][k], b[r - (1 << k) + 1][k]);
}

int get2(int i){
	int l = i, r = n + 1;
	while(l + 1 < r){
		int d = (l + r) >> 1;
		if(RMQ1(i, d) <= RMQ2(i, d)) l = d;
		else r = d;
	}
	return r;
}

int get1(int i){
	int l = i - 1, r = n + 1;
	while(l + 1 < r){
		int d = (l + r) >> 1;
		if(RMQ1(i, d) < RMQ2(i, d)) l = d;
		else r = d;
	}
	return r;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a[i] + 0);
	for(int i = 1; i <= n; ++i) scanf("%d", b[i] + 0);
	L[1] = 0;
	for(int k = 1; (1 << k) <= n; L[1 << k] = k, ++k)
		for(int i = 1; i + (1 << k) - 1 <= n; ++i){
			a[i][k] = max(a[i][k - 1], a[i + (1 << (k - 1))][k - 1]);
			b[i][k] = min(b[i][k - 1], b[i + (1 << (k - 1))][k - 1]);
		}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) L[i] = max(L[i], L[i - 1]);
	for(int i = 1; i <= n; ++i){
		if(a[i][0] > b[i][0]) continue;
		ans += get2(i) - get1(i);
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