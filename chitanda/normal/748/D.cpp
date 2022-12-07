//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;
typedef unsigned long long ull;

#define B 103
#define M 1000000009

int k, n;
char s[100100];
int a[100100], w[100100];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &k, &n);
	for(int i = 0; i < k; ++i){
		scanf("%s%d", s + i * n, a + i);
		w[i] = i;
	}
	sort(w, w + k, [](const int &i, const int &j) { return a[i] > a[j]; });

	map<int, queue<int> > mp;
	map<int, bool> tag;
	ll ans = 0;
	int delta = 0;
	for(int i = 0; i < k; ++i){
		int has1 = 0, has2 = 0, b = 1;
		int bg = w[i] * n;
		
		for(int j = 0; j < n; ++j){
			has1 = ((ll)has1 * b + s[bg + j] - 'a') % M;
			has2 = ((ll)has2 * b + s[bg + n - 1 - j] - 'a') % M;
			b = ((ll)b * B) % M;
		}

		if(has1 == has2) tag[has2] = 1;
		
		if(mp.count(has2) && !mp[has2].empty()){
			if(a[w[i]] + mp[has2].front() > 0){
				ans += a[w[i]] + mp[has2].front();
				mp[has2].pop();
				if (has1 == has2) delta = max(delta, -a[w[i]]);
			}
		}else{
			if (a[w[i]] >= 0) mp[has1].push(a[w[i]]);
		}
	}

	for(auto &&v : mp)
		if(tag[v.fi] == 1 && !v.se.empty())
			delta = max(delta, v.se.front());

	printf("%lld\n", ans + delta);
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