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

int n, m, tot;
char a[110], c;
int b[110], cnt0, cnt1;

char get(){
	char ch = getchar();
	while(ch == ' ') ch = getchar();
	return ch;
}

void no(){
	printf("Impossible");
	exit(0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	a[m = 1] = '+';
	while(1){
		c = get(); c = get();
		if(c == '=') break;
		a[++m] = c;
		if(c == '+') cnt0++;
		else cnt1++;
	}
	scanf("%d", &n);
	cnt0++;
	if(cnt0 * n - cnt1 < n) no();
	if(cnt0 - cnt1 * n > n) no();
	printf("Possible\n");
	int now = cnt0 * n - cnt1;
	for(int i = 1; i <= m; i++){
		if(a[i] == '+'){
			b[i] = n;
			if(now > n){
				int t = min(now - n, n - 1);
				now -= t;
				b[i] -= t;
			}
		}else{
			b[i] = 1;
			if(now > n){
				int t = min(now - n, n - 1);
				now -= t;
				b[i] += t;
			}
		}
	}
	printf("%d", b[1]);
	for(int i = 2; i <= m; i++)
		printf(" %c %d", a[i], b[i]);
	printf(" = %d", n);
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