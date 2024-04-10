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

int n, a[100100], b[100100];
char s[100100];

void work(int m){
	for(int i = 0; i < m / 2; i++){
		if(a[i] < 0) a[i] += 10, a[i + 1]--;
		if(a[m - i] > 1 || a[m - i] < 0) return;
		if(a[m - i] == 1){
			b[m - i - 1] = 9;
			b[i] = 10 + a[i] - 9;
			if(b[i] == 10) b[i] = 0, a[i + 1]++;
			a[i + 1]--;
			a[m - i]--;
			a[m - i - 1] -= b[i] - 1;
			a[i] = 0;
		}else{
			b[m - i - 1] = a[i];
			b[i] = 0;
			a[m - i - 1] -= a[i];
			a[i] = 0;
		}
	}
	if(m & 1){
		if(a[m / 2] < 0) a[m / 2] += 10, a[m / 2 + 1]--;
		if(a[m / 2 + 1] > 1 || a[m / 2 + 1] < 0) return;
		if(a[m / 2] & 1) return;
		if(a[m / 2 + 1]) b[m / 2] = 5 + a[m / 2] / 2;
		else b[m / 2] = a[m / 2] / 2;
		a[m / 2] = a[m / 2 + 1] = 0;
	}
	for(int i = 0; i < n; i++) if(a[i] != 0) return;
	if(!b[m - 1]) return;
	for(int i = m - 1; i >= 0; i--) printf("%d", b[i]);
	exit(0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++) a[i] = s[n - i - 1] - '0';
	work(n);
	for(int i = 0; i < n; i++) a[i] = s[n - i - 1] - '0';
	memset(b, 0, sizeof(b));
	if (n > 1) work(n - 1);
	printf("0\n");
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