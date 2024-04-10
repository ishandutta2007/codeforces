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

const int maxn = 100100;
const int maxp = maxn * 25;
int rt[maxn];
int cnt[maxp], ls[maxp], rs[maxp];
int c[maxn], L[maxn], last[maxn];
int n;
int tot;

int modify(int t, int l, int r, int x){
	int rt = ++tot; cnt[rt] = cnt[t];
	if(l == r){
		cnt[rt]++;
		return rt;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) ls[rt] = modify(ls[t], l, mid, x), rs[rt] = rs[t];
	else ls[rt] = ls[t], rs[rt] = modify(rs[t], mid + 1, r, x);
	cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
	return rt;
}

int query(int t, int l, int r, int y){
	if(!t) return 0;
	if(r <= y) return cnt[t];
	int mid = (l + r) >> 1;
	return query(ls[t], l, mid, y) + (y > mid ? query(rs[t], mid + 1, r, y) : 0);
}

int get(int l, int r){
	return query(rt[r], 1, n, l) - query(rt[l - 1], 1, n, l);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", c + i);
		L[i] = last[c[i]];
		last[c[i]] = i;
		rt[i] = modify(rt[i - 1], 1, n, L[i] + 1);
	}

	int round = 0;
	for(int i = 1; i <= n; ++i){
		int now = 1, cnt = 0;
		if(i <= 1000){
			int tmp = 0, nowr;
			while(now <= n){
				tmp = 1;
				for(nowr = now; nowr <= n && tmp <= i; ++nowr)
					tmp += L[nowr + 1] < now;
				now = nowr;
				++cnt;
			}
		}else{
			while(now <= n){
				int l = now, r = n + 1;
				while(l + 1 < r){
					int md = (l + r) >> 1;
					if(get(now, md) <= i) l = md;
					else r = md;
					//++round;
				}
				++cnt;
				now = l + 1;
			}
		}
		printf("%d ", cnt);
	}
	//printf("%d\n", round);
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