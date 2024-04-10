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

vector<pair<int, char> > ans;
const int maxn = 1000;
int n, m;
int a[maxn], b[maxn];

bool work(int l, int r, int base){
	if(l == r) return 1;
	int t = l;
	for(int i = l + 1; i <= r; ++i)
		if(a[i] > a[t]) t = i;
	for(int i = l; i <= r; ++i)
		if((i > l && a[i] > a[i - 1] || i < r && a[i] > a[i + 1]) && a[i] == a[t])
			t = i;
	int lt = t - 1, rt = t + 1;
	int now = a[t], le = 0;
	t = t - l + 1 + base;
	for(int i = l; i < r; ++i){
		if(lt >= l && now > a[lt]){
			now += a[lt];
			ans.pb(mkp(t - le, 'L'));
			le++;
			lt--;
		}else if(rt <= r && now > a[rt]){
			now += a[rt];
			ans.pb(mkp(t - le, 'R'));
			rt++;
		}else return 0;
	}
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	ll s1 = 0, s2 = 0;
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		s1 += a[i];
	}
	scanf("%d", &m);
	for(int j = 1; j <= m; ++j){
		scanf("%d", b + j);
		s2 += b[j];
	}

	if(s1 != s2){
		printf("NO\n");
		return 0;
	}
	
	int now = 0;
	for(int i = 1, j = 1, la = 1; i <= n; ++i){
		now += a[i];
		if(now == b[j]){
			if (!work(la, i, j - 1)){
				printf("NO\n");
				return 0;
			}
			la = i + 1;
			j++;
			now = 0;
		}
		if(now > b[j]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(auto v : ans)
		printf("%d %c\n", v.fi, v.se);
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