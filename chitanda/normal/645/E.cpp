//int!
#include <bits/stdc++.h>
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

int n, m, k, la[30];
char s[1000100];
int f[2000100], g[2000100];
priority_queue<pair<int, int> >q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	cin >> n >> k;
	scanf("%s", s + 1);
	m = strlen(s + 1);
	f[0] = g[0] = 1;
	for(int i = 1; i <= m; i++){
		int t = s[i] - 'a';
		f[i] = (g[i - 1] - g[la[t]] + M) % M;
		(f[i] += f[la[t]]) %= M;
		g[i] = (g[i - 1] + f[i]) % M;
		la[t] = i;
	}
	for(int i = 0; i < k; i++) q.push(mkp(-la[i], i));
	while(n--){
		m++;
		auto t = q.top(); q.pop();
		f[m] = (g[m - 1] - g[-t.fi] + M) % M;
		f[m] = (f[m] + f[-t.fi]) % M;
		g[m] = (g[m - 1] + f[m]) % M;
		la[t.se] = m;
		q.push(mkp(-m, t.se));
	}
	cout << g[m];
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