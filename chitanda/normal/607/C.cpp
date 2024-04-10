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
char a[1000100], b[1000100];
int p[1000100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n; n--;
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	p[1] = 0;
	FOR(i, 1, n)
		if(a[i] == 'N') a[i] = 'S';
		else if(a[i] == 'S') a[i] = 'N';
		else if(a[i] == 'W') a[i] = 'E';
		else a[i] = 'W';
	reverse(a + 1, a + n + 1);
	for(int i = 2, j = 0; i <= n; i++){
		while(j && a[i] != a[j + 1]) j = p[j];
		if(a[i] == a[j + 1]) j++;
		p[i] = j;
	}int j = 0;
	for(int i = 1; i <= n; i++){
		while(j && b[i] != a[j + 1]) j = p[j];	
		if(b[i] == a[j + 1]) j++;
		if(j == n && i < n) j = p[j];
	}
	cout << (j ? "NO" : "YES");
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