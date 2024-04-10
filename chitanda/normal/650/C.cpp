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

int n, m;
int a[1000010], aa[1000010], fa[1000010], c[1000010], b[1000010], get[1000010];
int r[1000010], w[1000010];

bool cmp(int x, int y) { return a[x] < a[y]; }
bool cmpx(int x, int y) { return b[x] < b[y]; }
bool cmpy(int x, int y) { return b[x] % m < b[y] % m; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int x, int y){
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	cin >> n >> m;
	FOR(i, 0, n * m - 1)scanf("%d", a + i), b[i] = i;
	sort(b, b + n * m, cmp);
	for(int i = 0, j; i < n * m; i = j + 1){
		j = i;
		while(a[b[j + 1]] == a[b[j]] && j < n * m - 1) j++;
		for(int k = i; k <= j; k++) fa[k] = k, c[k] = k;
		sort(c + i, c + j + 1, cmpx);
		for(int k = i + 1; k <= j; k++)
			if(b[c[k]] / m == b[c[k - 1]] / m) merge(c[k - 1], c[k]);
		sort(c + i, c + j + 1, cmpy);
		for(int k = i + 1; k <= j; k++)
			if(b[c[k]] % m == b[c[k - 1]] % m) merge(c[k - 1], c[k]);
		for(int k = i; k <= j; k++)
			get[find(k)] = max(get[find(k)], max(r[b[k] / m], w[b[k] % m]));
		for(int k = i; k <= j; k++) aa[b[k]] = r[b[k] / m] = w[b[k] % m] = get[find(k)] + 1;
	}
	for(int i = 0; i < n * m; i++){
		if(i && i % m == 0) printf("\n");
		printf("%d ", aa[i]);
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