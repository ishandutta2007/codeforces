#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define mid ((l + r) >> 1)

int n, m, k, ty, x, y, ans;
char s[200001], ss[10], tag[800001];
int tr[800001][10][10];

void update(int t, int m){
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
			tr[t][i][j] = tr[ls][i][j] + tr[rs][i][j];
	tr[t][s[m] - 'a'][s[m + 1] - 'a']++;
}

void build(int t, int l, int r){
	if (l == r){
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	update(t, mid);
}

void pushdown(int t, int l, int r){
	if (!tag[t] || l == r) return;
	s[mid] = s[mid + 1] = tag[ls] = tag[rs] = tag[t];
	memset(tr[ls], 0, sizeof(tr[ls]));
	memset(tr[rs], 0, sizeof(tr[rs]));
	tr[ls][tag[t] - 'a'][tag[t] - 'a'] = mid - l;
	tr[rs][tag[t] - 'a'][tag[t] - 'a'] = r - mid - 1;
	tag[t] = 0;
}

void modify(int t, int l, int r, int x, int y, char c){
	pushdown(t, l, r);
	if (x <= l && r <= y){
		s[l] = s[r] = tag[t] = c;
		memset(tr[t], 0, sizeof(tr[t]));
		tr[t][c - 'a'][c - 'a'] = r - l;
		return;
	}
	if (x <= mid) modify(ls, l, mid, x, y, c);
	if (y > mid) modify(rs, mid + 1, r, x, y, c);
	update(t, mid);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s + 1);
	build(1, 1, n);
	while(m--){
		scanf("%d", &ty);
		if (ty == 1){
			scanf("%d%d%s", &x, &y, ss);
			modify(1, 1, n, x, y, ss[0]);
		}else{
			scanf("%s", ss);
			ans = 1;
			for(int i = 0; i < k; i++)
				for(int j = 0; j <= i; j++)
					ans += tr[1][ss[i] - 'a'][ss[j] - 'a'];
			printf("%d\n", ans);
		}
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