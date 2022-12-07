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

char s[10100], ss[10100];
vector<string> q;
bool g[10100][2];

bool check(int i, int j, int l){
	for(int t = 0; t < l; t++)
		if(ss[i + t] != ss[j + t]) return 1;
	return 0;
}

void get(int i, int l){
	string s1;
	for(int t = 0; t < l; t++) s1 += ss[i - t - 1];
	q.pb(s1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s + 5);
	for(int i = 0; i < n; i++) ss[i] = s[n + 4 - i];

	g[2][0] = g[3][1] = 1;
	if (n >= 2) get(2, 2); 
	if (n >= 3) get(3, 3);
	for(int i = 4; i <= n; i++){
		if(g[i - 2][1] || (g[i - 2][0] && check(i - 2, i - 4, 2))) g[i][0] = 1;
		if(g[i - 3][0] || (g[i - 3][1] && check(i - 3, i - 6, 3))) g[i][1] = 1;
		if(g[i][0]) get(i, 2);
		if(g[i][1]) get(i, 3);
	}
	
	sort(all(q));
	q.resize(unique(all(q)) - q.begin());
	printf("%d\n", (int)q.size());
	for(auto v : q) cout << v << "\n";
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