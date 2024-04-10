#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

map<ll,ll> b, c;

ll k, n[18], a[18][5005];
ll s[18];

ll sum;

ll bz[18][5005];
ll d[18][2], d0;
ll us[18];

ll f[1 << 15], g[1 << 15];
ll q[1 << 15][18][2], q0[1 << 15];
ll fr[1 << 15];

ll c1[18], c2[18];

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%lld", &k);
	fo(i, 1, k) {
		scanf("%lld", &n[i]);
		fo(j, 1, n[i]) scanf("%lld", &a[i][j]);
		fo(j, 1, n[i]) {
			s[i] += a[i][j];
			b[a[i][j]] = i;
			c[a[i][j]] = j;
			sum += a[i][j];
		}
	}
	if(sum % k != 0) {
		pp("No\n"); return 0;
	}
	sum /= k;
	fo(i, 1, k) {
		fo(j, 1, n[i]) {
			fo(u, 1, k) us[u] = 0;
			ll x = i, y = j;
			d0 = 0;
			int ky = 1;
			while(!us[x]) {
				d[++ d0][0] = x, d[d0][1] = y;
				us[x] = d0;
				ll nv = sum - (s[x] - a[x][y]);
				if(b.count(nv)) {
					x = b[nv], y = c[nv];
				} else {
					ky = 0;
					break;
				}
			}
			if(!ky) continue;
			if(y != d[us[x]][1]) continue;
			ll w = 0;
			fo(u, us[x], d0) w += 1 << (d[u][0] - 1);
			g[w] = 1; q0[w] = 0;
			fo(u, us[x], d0) {
				q[w][++ q0[w]][0] = d[u][0];
				q[w][q0[w]][1] = d[u][1];
			}
		}
	}
	f[0] = 1;
	ff(i, 0, 1 << k) if(f[i]){
		for(ll j = i; j < (1 << k); j = (j + 1) | i) {
			ll u = i ^ j;
			if(g[u]) {
				f[j] = 1;
				fr[j] = i;
			}
		}
	}
	ll w = (1 << k) - 1;
	if(f[w]) {
		pp("Yes\n");
		ll x = w;
		while(x) {
			ll y = x ^ fr[x];
			fo(j, 1, q0[y]) {
				c1[q[y][j][0]] = a[q[y][j][0]][q[y][j][1]];
				ll la = j - 1;
				if(la == 0) la = q0[y];
				c2[q[y][j][0]] = q[y][la][0];
			}
			x = fr[x];
		}
		fo(i, 1, k) pp("%lld %lld\n", c1[i], c2[i]);
	} else pp("No\n");
}