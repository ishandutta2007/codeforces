#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define fl fflush(stdout)

const int N = 1005;

int n, x, y, r[N];
vector<int> e[N];

#define pb push_back

int d[N], d0;

int main() {
	scanf("%d", &n);
	fo(i, 2, n) {
		scanf("%d %d", &x, &y);
		e[x].pb(y); e[y].pb(x);
		r[x] ++; r[y] ++;
	}
	fo(i, 1, n) if(r[i] == 1)
		d[++ d0] = i;
	for(int i = 1; i <= d0; i += 2) {
		if(i + 1 > d0) {
			pp("! %d\n", d[i]); fl;
			return 0;
		}
		int u = d[i], v = d[i + 1];
		pp("? %d %d\n", u, v); fl;
		int z; scanf("%d", &z);
		if(z == u || z == v) {
			pp("! %d\n", z); fl;
			return 0;
		}
		ff(j, 0, e[u].size()) {
			int y = e[u][j];
			if((-- r[y]) == 1) d[++ d0] = y;
		}
		ff(j, 0, e[v].size()) {
			int y = e[v][j];
			if((-- r[y]) == 1) d[++ d0] = y;
		}
	}
}