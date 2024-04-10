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

const int maxn = 500100;
int n, len;
ll a[maxn], b[maxn], p[100], num[100];

int main(){

	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%I64d%I64d", a + i, b + i);
		sum ^= a[i];
		a[i] ^= b[i];
	}
	a[n] = sum;
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j < len; ++j)
			if(a[i] & p[j])
				a[i] ^= num[j];		
		if(a[i]){
			p[len] = a[i] & -a[i];
			num[len++] = a[i];
		}
	}
	if(a[n]) printf("1/1\n");
	else printf("%I64d/%I64d\n", (1LL << len) - 1, 1LL << len);
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