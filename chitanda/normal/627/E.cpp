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

const int maxn = 3100;
int r, c, n, k, a[maxn], nn, pre[maxn], nex[maxn], cal[maxn];
ll ans, now;
struct node{
	int x, y;
}p[maxn], q[maxn];
bool cmpy(node a, node b){ return a.y < b.y; }
bool cmp(int a, int b) { return q[a].x > q[b].x; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> r >> c >> n >> k;
	FOR(i, 1, n) scanf("%d%d", &p[i].x, &p[i].y);
	FOR(i, 1, r){
		nn = 0; now = 0;
		memset(cal, 0, sizeof(cal));
		FOR(j, 1, n) if(p[j].x >= i) q[++nn] = p[j], a[nn] = nn;
		sort(q + 1, q + nn + 1, cmpy);
		FOR(j, 1, nn - 1) nex[j] = j + 1; nex[nn] = 0;
		FOR(j, 2, nn) pre[j] = j - 1; pre[1] = 0;
		FOR(j, k + 1, nn) cal[j - 1] = (q[j].y - q[j - 1].y) * q[j - k].y, now += cal[j - 1];
		if(nn >= k) cal[nn] = (c - q[nn].y + 1) * q[nn - k + 1].y; now += cal[nn];

		sort(a + 1, a + nn + 1, cmp);
		int w = 1;
		ROF(j, r, i){
			ans += now;
			while(w <= nn && q[a[w]].x == j){
				int t = a[w];
				now -= cal[t]; cal[t] = 0;

				int lt = pre[t], rt = nex[t];
				if(lt) nex[lt] = rt;
				if(rt) pre[rt] = lt;
				
				if(lt) rt = lt; else lt = rt;
				int tt = 1; for(; tt < k && pre[lt]; tt++, lt = pre[lt]);
				for(int l = 1; rt && l <= k; l++, rt = nex[rt], tt++){
					now -= cal[rt]; cal[rt] = 0;
					if(tt < k) continue;
					if(tt > k) lt = nex[lt], tt--;
					if(nex[rt]) cal[rt] = (q[nex[rt]].y - q[rt].y) * q[lt].y;
					else cal[rt] = (c - q[rt].y + 1) * q[lt].y;
					now += cal[rt];
				}
				w++;
			}
		}
	}
	cout << ans;
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