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
#define M 1000000007

const int N = 10000000;
int n, x, ans;
int two[N];
int mu[N + 10], a[N + 10];

int add(int x, int y){
	x += y;
	if(x >= M) x -= M;
	return x;
}

int mul(int x, int y){
	return (ll)x * y % M;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		a[x]++;
	}
	for(int i = 2; i <= N; i++){
		mu[i]++;
		for(int j = 2 * i; j <= N; j += i)
			mu[j] -= mu[i];
	}
	two[0] = 1; for(int i = 1; i <= n; i++) two[i] = add(two[i - 1], two[i - 1]);
	for(int i = 2; i <= N; i++){
		if(!mu[i]) continue;
		int c = 0;
		for(int j = i; j <= N; j += i) c += a[j];
		if (mu[i] == 1) ans = add(ans, mul(n - c, add(two[c], M - 1)));
		else ans = add(ans, M - mul(n - c, add(two[c], M - 1)));
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