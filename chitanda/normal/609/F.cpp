//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define mid ((l + r) >> 1)
#define ls son[t][0]
#define rs son[t][1]
#define L ls, l, mid
#define R rs, mid + 1, r

const int maxn = 200100, maxm = maxn * 30, M = 1000000000;
typedef multiset<pair<int, int> > myset;
int n, m, tot, root, x[maxn], p, v, num[maxn];
ll y[maxn];
int son[maxm][2], val[maxm];
myset q;

void update(int t){
	if(y[val[ls]] > y[val[rs]]) val[t] = val[ls];
	else val[t] = val[rs];
}

int modify(int t, int l, int r, int w){
	if(!t) t = ++tot;
	if(l == r) { val[t] = w; return t; }
	if(x[w] <= mid) ls = modify(L, w);
	else rs = modify(R, w);
	update(t);
	return t;
}

int ask(int t, int l, int r, int w){
	if(!t) return 0;
	if(l == r) return val[t];
	if(y[val[ls]] >= w) return ask(L, w);
	else return ask(R, w);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 1, n){
		scanf("%d%I64d", x + i, y + i); y[i] += x[i];
		root = modify(root, 1, M, i);
	}
	while(m--){
		scanf("%d%d", &p, &v);
		int w = ask(root, 1, M, p);
		if(x[w] > p || !w) q.insert(mkp(p, v));
		else{
			for(;;){
				y[w] += v; num[w]++;
				modify(root, 1, M, w);
				myset::ite it = q.lower_bound(mkp(x[w], 0));
				if(it == q.end() || (*it).fi > y[w]) break;
				v = (*it).se; q.erase(it);
			}
		}
	}
	FOR(i, 1, n) printf("%d %I64d\n", num[i], y[i] - x[i]);
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