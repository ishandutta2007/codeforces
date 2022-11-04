#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];

int l[N], r[N];

int d[N], d0, bx[N];

map<int, int> bz[N];

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, m) scanf("%d %d", &a[i], &b[i]), bz[a[i]][b[i]] = bz[b[i]][a[i]] = 1;
	r[0] = 1;
	fo(i, 1, n) l[i] = i - 1, r[i] = i + 1;
	l[n + 1] = n;
	int ans = 0;
	fo(i, 1, n) if(!bx[i]){
		d[d0 = 1] = i;
		for(int j = 1; j <= d0; j ++) {
			int x = d[j];
			for(int k = r[0]; k <= n; k = r[k]) {
				if(!bz[x][k]) {
					d[++ d0] = k;
					bx[k] = 1;
					r[l[k]] = r[k];
					l[r[k]] = l[k];
				}
			}
		}
		ans ++;
	}
	pp("%d\n", ans - 1);
}