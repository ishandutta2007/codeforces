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
int n, a[maxn], top;
ll s[maxn], ans, tans;

struct line{
	ll a, b;
	ll get(int x) { return a * x + b; }
	line(ll a_ = 0, ll b_ = 0):a(a_), b(b_) {}
}L[maxn];

bool check(line x, line y, line z){
	return (x.b - z.b) * (x.a - y.a) <= (x.b - y.b) * (x.a - z.a);
}

void add(int a, ll b){
	L[++top] = line((ll)a, b);
	while(top > 2 && check(L[top - 1], L[top - 2], L[top])) L[top - 1] = L[top], top--;
}

ll query(ll x){
	int l = 0, r = top;
	while(r - l > 1){
		int m = (l + r) >> 1;
		if(L[m].get(x) <= L[m + 1].get(x)) l = m; else r = m;
	}
	return L[r].get(x);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	cin >> n;
	FOR(i, 1, n) scanf("%d", a + i), s[i] = s[i - 1] + a[i], ans += (ll)i * a[i];
	
	FOR(i, 2, n){
		add(i - 1, -s[i - 2]);
		tans = max(tans, query(a[i]) + s[i - 1] - (ll)a[i] * i);
	}
	
	top = 0;
	ROF(i, n - 1, 1){
		add(-(i + 1), -s[i + 1]);
		tans = max(tans, query(-a[i]) + s[i] - (ll)a[i] * i);
	}
	cout << ans + tans;
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