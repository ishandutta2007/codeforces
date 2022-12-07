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

char s[500100], t[500100];
int n, m, wt, p[500100], sta[500100], pre[500100], nex[500100], top;

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &wt);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for(int i = 1; i <= n; ++i){
		if(s[i] == '(') sta[++top] = i;
		else{
			p[i] = sta[top];
			p[sta[top--]] = i;
		}
		pre[i] = i - 1;
		nex[i] = i + 1;
	}
	nex[0] = 1; pre[n + 1] = n;
	for(int i = 1; i <= m; ++i){
		if(t[i] == 'L') wt = pre[wt];
		else if(t[i] == 'R') wt = nex[wt];
		else{
			int ww = p[wt];
			if(ww > wt) swap(ww, wt);
			nex[pre[ww]] = nex[wt];
			pre[nex[wt]] = pre[ww];
			if(nex[wt] <= n) wt = nex[wt];
			else wt = pre[ww];
		}
	}
	int w = nex[0];
	while(w <= n){
		printf("%c", s[w]);
		w = nex[w];
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