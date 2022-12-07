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

int n, k;
char s[100100];
int v[100100];
vector<int> g;

bool check(int d){
	for(int i = 0, j = 0; i < g.size(); i++){
		while(j < i && g[i] - g[j] > d) j++;
		v[i] = i - j;
	}
	for(int i = g.size() - 1, j = g.size() - 1; i >= 0; i--){
		while(j > i && g[j] - g[i] > d) j--;
		if(j - i + v[i] >= k) return 1;
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	cin >> n >> k;
	scanf("%s", s);
	int l = 0, r = n;
	for(int i = 0; i < n; i++)
		if(s[i] == '0') g.pb(i);
	while(l + 1 < r){
		int m = (l + r) >> 1;
		if(check(m)) r = m;
		else l = m;
	}
	cout << r;
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