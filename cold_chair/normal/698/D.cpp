#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1005;

int k, n;
struct P {
	int x, y;
	P(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
} a[N], b[N], c[N];

P operator - (P a, P b) {
	return P(a.x - b.x, a.y - b.y);
}

#define db double

db ang(P a) {
	return atan2(-a.y, a.x);
}

db lenf(P a) {
	return (ll) a.x * a.x + (ll) a.y * a.y; 
}

ll operator ^ (P a, P b) {
	return (ll) a.x * b.y - (ll) a.y * b.x;
}

const db eps = 1e-11;

int la[8][N];

int bz[N]; int p[8]; 
int z[N], st, en;
int us[N];

void dg(int x) {
	if(x > k) {
		fo(i, 1, n) if(!bz[i]) {
			st = en = 1; z[1] = i; us[i] = 1;
			fo(j, 1, k) {
				int x = z[st], y = la[p[j]][x];
				while(y) {
					if(!us[y]) us[y] = 1, z[++ en] = y;
					if(en > k) break;
					y = la[p[j]][y];
				}
				if(en > k) break;
				st ++;
				if(st > en) {
					bz[i] = 1; break;
				}
			}
			fo(j, 1, en) us[z[j]] = 0;
		}
		return;
	}
	fo(i, 1, k) if(!p[i]) {
		p[i] = x;
		dg(x + 1);
		p[i] = 0;
	}
}

int d[N], d0;
int cmpc(P a, P b) {
	if((a.x < 0) != (b.x < 0))
		return a.x < b.x;
	if((a ^ b) == 0) return lenf(a) < lenf(b);
	return (a ^ b) > 0;
}

int cmpd(int x, int y) {
	return cmpc(c[x], c[y]);
}

int ccc(P a, P b) {
	if((a.x < 0) != (b.x < 0)) return 1;
	return (a ^ b) != 0;
}

int main() {
	scanf("%d %d", &k, &n);
	fo(i, 1, k) scanf("%d %d", &a[i].x, &a[i].y);
	fo(i, 1, n) scanf("%d %d", &b[i].x, &b[i].y);
	fo(i, 1, k) {
		fo(j, 1, n) c[j] = b[j] - a[i], d[j] = j;
		sort(d + 1, d + n + 1, cmpd);
		//fo(j, 1, n) pp("%d %d  ", c[j].x, c[j].y); hh;
		int lj = 1;
		fo(j, 2, n + 1) if(j > n || ccc(c[d[j - 1]], c[d[j]])) {
			fo(k, lj + 1, j - 1) la[i][d[k]] = d[k - 1];
			lj = j;
		}
	}
	dg(1);
	int ans = 0;
	fo(i, 1, n) ans += bz[i];
	pp("%d\n", ans);
}