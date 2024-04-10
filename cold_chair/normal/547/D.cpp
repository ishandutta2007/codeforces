#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int n, x, c[N], a[2][N];
vector<int> e[N];

#define pb push_back

void dg(int x, int z) {
	c[x] = z;
	ff(i, 0, e[x].size()) {
		int y = e[x][i];
		if(!c[y]) dg(y, 3 - z);
	}
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) {
		fo(j, 0, 1) {
			scanf("%d", &x);
			if(a[j][x]) e[i].pb(a[j][x]), e[a[j][x]].pb(i), a[j][x] = 0; else
			a[j][x] = i;
		}
	}
	fo(i, 1, n) if(!c[i]) dg(i, 1);
	fo(i, 1, n) pp("%c", c[i] > 1 ? 'r' : 'b');
}