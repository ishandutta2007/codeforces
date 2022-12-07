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

int n, m, q, u[13], v[13], a[110], b[110], c[110];
ll f[13][8192];

int in(int mask, int t) { return (mask >> t) & 1; }

bool check(int t, int mask, int j, int k){
	FOR(i, 1, m){
		if(in(mask, v[i]) && in(mask, u[i])){
			if(in(k, u[i]) ^ in(k, v[i]))
				if(max(u[i], v[i]) != max(j, t) || min(u[i], v[i]) != min(j, t)) return 0;
		}else if(in(mask, v[i]) ^ in(mask, u[i])) if(u[i] != t && v[i] != t) return 0;
	}
	FOR(i, 1, q){
		if(in(mask, a[i]) && in(mask, b[i])){
			if(c[i] == t) { if (in(k, a[i]) && in(k, b[i])) return 0; }
			else{
				if(a[i] == t || b[i] == t) return 0;
				int tk = in(k, a[i]) + in(k, b[i]) + in(k, c[i]);
				if(tk != 0 && tk != 3) return 0;
			}
		}
	}
	return 1;
}

int lowbit(int x) { return x & -x; }

ll DP(int t, int mask){
	if(f[t][mask] > -1) return f[t][mask];
	if(mask == (1 << t)) return f[t][mask] = 1;
	f[t][mask] = 0;
	int kk = ((1 << t) & lowbit(mask)) ? lowbit(mask - lowbit(mask)) : lowbit(mask);
	ROF(k, mask - 1, 1)
		if(((k | mask) == mask) && !in(k, t) && (k & kk)){
			for(int j = 0; j < n; j++)
				if(in(k, j))
					if(check(t, mask, j, k)) f[t][mask] += DP(t, mask ^ k) * DP(j, k);
		}
	return f[t][mask];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m >> q;
	FOR(i, 1, m){
		scanf("%d%d", &u[i], &v[i]);
		u[i]--, v[i]--;
	}
	FOR(i, 1, q){
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i]--, b[i]--, c[i]--;
	}
	memset(f, -1, sizeof(f));
	cout << DP(0, (1 << n) - 1);
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