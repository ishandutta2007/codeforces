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

typedef pair<ll, int> mp;
const int maxn = 100100;
int n, Q, f[maxn], ru[maxn];
ll t[maxn], ads[maxn];
set<mp> q[maxn], result;

inline ll contribution(int x){
	return t[x] / (ru[x] + 2);
}

inline ll self_contribution(int x){
	return t[x] - (ru[x] + 1) * contribution(x);
}

inline ll calc(int x){
	return ads[x] + contribution(f[x]);
}

void add(int x){
	q[f[x]].insert(mkp(ads[x], x));
}

void update(int x){
	while(!q[x].empty() && ((*q[x].begin()).fi != ads[(*q[x].begin()).se] || f[(*q[x].begin()).se] != x)) q[x].erase(*q[x].begin());
	while(!q[x].empty() && ((*q[x].rbegin()).fi != ads[(*q[x].rbegin()).se] || f[(*q[x].rbegin()).se] != x)) q[x].erase(*q[x].rbegin());
	if(!q[x].empty()) result.insert(mkp(calc((*q[x].begin()).se), (*q[x].begin()).se));
	if(!q[x].empty()) result.insert(mkp(calc((*q[x].rbegin()).se), (*q[x].rbegin()).se));
}

void update_(int x, int k){
	ads[f[x]] -= contribution(x);
	ads[x] -= self_contribution(x);
	ru[x] += k;
	ads[f[x]] += contribution(x);
	ads[x] += self_contribution(x);
	add(f[x]);
	add(x);
	update(x);
	update(f[x]);
	update(f[f[x]]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> Q;
	for(int i = 1; i <= n; i++) scanf("%I64d", t + i);
	for(int i = 1; i <= n; i++){
		scanf("%d", f + i);
		ru[f[i]]++;
	}
	for(int i = 1; i <= n; i++){
		ads[f[i]] += contribution(i);
		ads[i] += self_contribution(i);
	}
	for(int i = 1; i <= n; i++) add(i);
	for(int i = 1; i <= n; i++) update(i);
	
	int x, y, ty;
	while(Q--){
		scanf("%d", &ty);
		if(ty == 1){
			scanf("%d%d", &x, &y);
			int z = f[x];
			ads[z] -= contribution(x);
			ads[y] += contribution(x);
			f[x] = y;
			add(x);
			update_(z, -1);
			update_(y, 1);
		}else if(ty == 2){
			scanf("%d", &x);
			printf("%I64d\n", calc(x));
		}else{
			while((*result.begin()).fi != calc((*result.begin()).se)) result.erase(*result.begin());
			while((*result.rbegin()).fi != calc((*result.rbegin()).se)) result.erase(*result.rbegin());
			printf("%I64d %I64d\n", (*result.begin()).fi, (*result.rbegin()).fi);
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