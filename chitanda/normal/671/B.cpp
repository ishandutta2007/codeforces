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

const int maxn = 500100;
int n, c[maxn], k, tmin, tmax;

ll check(int d){
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		if(c[i] <= d) sum += d - c[i];
	}
	return sum;
}

ll check_(int d){
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		if(c[i] >= d) sum += c[i] - d;
	}
	return sum;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", c + i);
	if(n == 1) { printf("%d\n", 0); return 0; }
	sort(c + 1, c + n + 1);
	int l = 0, r = 1000000000;
	while(l + 1 < r){
		int d = (l + r) >> 1;
		if(check(d) <= k) l = d; else r = d;
	}
	tmin = l;
	l = 0, r = 1000000000;
	while(l + 1 < r){
		int d = (l + r) >> 1;
		if(check_(d) <= k) r = d; else l = d;
	}
	tmax = r;
	if(tmin < tmax) printf("%d\n", tmax - tmin);
	else{
		int l = 0, r = 1000000000;
		while(l + 1 < r){
			int d = (l + r) >> 1;
			if(check(d) <= check_(d)) l = d; else r = d;
		}
		if(check(l) == check_(l)) printf("0");
		else printf("1");
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