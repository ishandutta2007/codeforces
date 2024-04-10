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

const int maxn = 200100;
int n, t, q, p[maxn], l[maxn], c[maxn], ty, id;
double pre[maxn], nex[maxn], ans;
set<pair<double, int> > prv, nxt;

void calc(int k){
	if(c[k]) pre[k] = 1. * p[k] * l[k] / (c[k] + l[k] - 1) / (c[k] + l[k]);
	nex[k] = 1. * p[k] * l[k] / (c[k] + l[k]) / (c[k] + l[k] + 1);
}

void add(int k){
	ans += 1. * p[k] * c[k] / (l[k] + c[k]);
	calc(k);
	if(c[k]) prv.insert(mkp(pre[k], k));
	if(c[k] < l[k]) nxt.insert(mkp(nex[k], k));
}

void del(int k){
	ans -= 1. * p[k] * c[k] / (l[k] + c[k]);
	if(c[k]) prv.erase(mkp(pre[k], k));
	if(c[k] < l[k]) nxt.erase(mkp(nex[k], k));
}

void gopre(int k){
	del(k);
	assert(c[k]);
	c[k]--;
	add(k);
}

void gonxt(int k){
	del(k);
	assert(c[k] < l[k]);
	c[k]++;
	add(k);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> t >> q;
	FOR(i, 1, n) scanf("%d", p + i);
	FOR(i, 1, n){
		scanf("%d", l + i);
		calc(i);
		add(i);
	}
	int cf = 0;
	while(cf < t && !nxt.empty()){
		gonxt(nxt.rbegin()->se);
		cf++;
	}
	FOR(i, 1, q){
		scanf("%d%d", &ty, &id);
		if(ty == 1){
			del(id);
			l[id]++;
			calc(id);
			add(id);
		}else{
			del(id);
			l[id]--;
			if(c[id] > l[id]) c[id]--, cf--;
			calc(id); add(id);
		}
		while(!nxt.empty() && !prv.empty()){
			if(prv.begin()->fi < nxt.rbegin()->fi){
				int id1 = prv.begin()->se, id2 = nxt.rbegin()->se;
				gopre(id1); gonxt(id2);
			}else break;
		}
		while(cf < t && !nxt.empty()){
			gonxt(nxt.rbegin()->se);
			cf++;
		}
		printf("%.10f\n", ans);
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