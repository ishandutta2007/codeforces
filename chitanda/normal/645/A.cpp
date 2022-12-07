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

char s[10], t[10], ss[10], tt[10];
int k, l;

int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	scanf("%s", s);
	scanf("%s", s + 2);
	scanf("%s", t);
	scanf("%s", t + 2);
	swap(s[2], s[3]);
	swap(t[2], t[3]);
	for(int i = 0; i < 4; i++)
		if(s[i] == 'A'){
			for(int j = 0; j < 4; j++)
				if(s[(i + j) % 4] != 'X') ss[k++] = s[(i + j) % 4];
		}
	for(int i = 0; i < 4; i++)
		if(t[i] == 'A'){
			for(int j = 0; j < 4; j++)
				if(t[(i + j) % 4] != 'X') tt[l++] = t[(i + j) % 4];
		}
	if(ss[1] == tt[1]) printf("YES\n");
	else printf("NO\n");
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