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
#define M 1000000007
#define ull unsigned long long

const int maxn = 1000100;
int n;
ll x[maxn], y[maxn], sumx[maxn], sumy[maxn], s1[maxn], s2[maxn], ans, tot, now, tnow;

ll cross(int a, int b) { return x[b] * y[a] - y[b] * x[a]; }
void add(ll &a, ll b, ll c) { a = (b + c) % M; a = (a + M) % M; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	FOR(i, 1, n) scanf("%I64d%I64d", x + i, y + i), x[i + n] = x[i], y[i + n] = y[i];
	FOR(i, 1, n) tot += cross(i, i + 1);
	FOR(i, 1, 2 * n){
		add(sumx[i], sumx[i - 1], x[i]);
		add(sumy[i], sumy[i - 1], y[i]);
		add(s1[i], s1[i - 1], cross(i, i + 1));
		add(s2[i], s2[i - 1], cross(i, i + 1) % M * i);
	}
	for(int i = 1, j = i + 1; i <= n; i++){
		while((ull)(tnow = now - cross(j, i) + cross(j, j + 1) + cross(j + 1, i)) * 2 < (ull)tot || ((ull)tnow * 2 == (ull)tot && j < n))
			now = tnow, j++;
		x[2 * n] = (sumx[j] - sumx[i] + M) % M, y[2 * n] = (sumy[j] - sumy[i] + M) % M;
		ll cal = (s1[j - 1] - s1[i - 1]) * j - (s2[j - 1] - s2[i - 1]) + cross(2 * n, i) % M;
		add(ans, ans, cal);
		now = now - cross(i, i + 1) - cross(j, i) + cross(j, i + 1);
	}
	//if(n > 10000) cout << tot;
	cout << (tot % M * ((ll)n * (n - 3) / 2 % M) % M - 2 * ans % M + M) % M;
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