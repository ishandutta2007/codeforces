#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mkp make_pair

const int maxn = 200100;
int n, m, k, s;
int t[maxn], c[maxn], a[maxn], b[maxn], p[maxn], q[maxn];
vector<pair<ll, pair<int, int> > >v;

bool cmpx(int x, int y) { return t[x] < t[y]; }
bool cmpy(int x, int y) { return c[x] < c[y]; }

int check(int d){
	if(!d) return 0;
	v.clear();
	int cp1 = 1, cp2 = 1;
	for(int i = 1; i <= d; i++){
		if(a[i] < a[cp1]) cp1 = i;
		if(b[i] < b[cp2]) cp2 = i;
	}
	for(int i = 1; i <= m; i++){
		if(t[i] == 1) v.pb(mkp((ll)a[cp1] * c[i], mkp(i, cp1)));
		else v.pb(mkp((ll)b[cp2] * c[i], mkp(i, cp2)));
	}
	sort(v.begin(), v.end());
	ll need = 0;
	for(int i = 0; i < k; i++) need += v[i].fi;
	return need <= s;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) scanf("%d", b + i);
	for(int i = 1; i <= m; i++)
		scanf("%d%d", t + i, c + i);
	int l = 0, r = n;
	while(l + 1 < r){
		int d = (l + r) / 2;
		if (check(d)) r = d;
		else l = d;
	}
	if(check(r)){
		printf("%d\n", r);
		for(int i = 0; i < k; i++) printf("%d %d\n", v[i].se.fi, v[i].se.se);
	}else printf("-1\n");
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