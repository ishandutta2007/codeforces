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
int n, m, p[maxn], x;
ll ans;
pair<ll, char> a[maxn], b[maxn];

void get(pair<ll, char> &a){
	scanf("%d", &x); a.fi = x;
	getchar(); a.se = getchar();
}

void kmp(){
	p[1] = 0;
	int j = 0;
	for(int i = 2; i <= m; i++){
		while(j && b[j + 1] != b[i]) j = p[j];
		if(b[j + 1] == b[i]) j++;
		p[i] = j;
	}
	j = 0;
	for(int i = 1; i <= n; i++){
		while(j && b[j + 1] != a[i]) j = p[j];
		if(b[j + 1] == a[i]) j++;
		if(j == m){
			if(i > m && a[i - m].se == b[0].se && a[i - m].fi >= b[0].fi && i < n &&
				 a[i + 1].se == b[m + 1].se && a[i + 1].fi >= b[m + 1].fi) ans++;
			j = p[j];	
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	cin >> n >> m; m--;
	FOR(i, 1, n){
		get(a[i]);
		if(i > 1 && a[i].se == a[i - 1].se) a[i - 1].fi += a[i].fi, i--, n--;
	}
	FOR(i, 0, m){
		get(b[i]);
		if(i && b[i].se == b[i - 1].se) b[i - 1].fi += b[i].fi, i--, m--;
	}
	if(!m){
		for(int i = 1; i <= n; i++)
			if(a[i].se == b[0].se && a[i].fi >= b[0].fi) ans += a[i].fi - b[0].fi + 1;
	}else	if(m == 1){
		for(int i = 1; i < n; i++)
			if(a[i].se == b[0].se && a[i].fi >= b[0].fi 
				 && a[i + 1].se == b[m].se && a[i + 1].fi >= b[m].fi) ans++;
	}else m--, kmp();
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